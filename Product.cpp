#include "Product.h"


Product::Product() : Entity()
{
    price = stock = size = -1;
    strcpy_s(exp_date, "");
    primary_file_name = "Proudct01.txt", secondary_file_name = "Proudct02.txt",
    file_name = "Proudct00.txt", deleted_file_name = "ProudctAvail.txt";
    load_files();
}

Product::Product(int id, char name[20], int price, int stock, int size, char exp_date[11]) : Entity(id, name), price(price), stock(stock), size(size)
{
    strcpy_s(this->exp_date, exp_date);
    primary_file_name = "Proudct01.txt", secondary_file_name = "Proudct02.txt",
    file_name = "Proudct00.txt", deleted_file_name = "ProudctAvail.txt";
    load_files();
}

Product::Product(Product &other) : Entity(other), price(other.price), stock(other.stock), size(other.size)
{
    strcpy_s(exp_date, other.exp_date);
}

Product::~Product()
{
    save_files();
}

void Product::Write()
{
    LogicalFile.put('$');
    LogicalFile.write((char*)&id, sizeof(id));
    LogicalFile.write(name, strlen(name));
    LogicalFile.put('|');
    LogicalFile.write((char*)&price, sizeof(price));
    LogicalFile.write((char*)&stock, sizeof(stock));
    LogicalFile.write((char*)&size, sizeof(size));
    LogicalFile.write(exp_date, strlen(exp_date));
    LogicalFile.put('|');
}

void Product::Read()
{
    streamsize sz = 0;
    LogicalFile.get();
    LogicalFile.read((char*)&id, sizeof(id));
    LogicalFile.getline(name, 20, '|');
    LogicalFile.read((char*)&price, sizeof(price));
    LogicalFile.read((char*)&stock, sizeof(stock));
    LogicalFile.read((char*)&size, sizeof(size));
    LogicalFile.getline(exp_date, 20, '|');
}

int Product::Size()
{
    return 19 + strlen(name) + strlen(exp_date);
}

void Product::Price(int price)
{
    this->price = price;
}

void Product::Stock(int stock)
{
    this->stock = stock;
}

void Product::Size(int size)
{
    this->size = size;
}

void Product::Exp_date(char exp_date[11])
{
    strcpy_s(this->exp_date, exp_date);
}



void Product::Add()
{

    LogicalFile.open(file_name, ios::in | ios::out | ios::binary);
    int offset = BestFit(Size());

    if (offset == -1)
    {
        LogicalFile.seekp(0, ios::end);
        offset = LogicalFile.tellp();
    }
    else
        LogicalFile.seekp(offset, ios::beg);
    Write();
    indexes.primary_keys[id].insert(offset);
    indexes.secondary_keys[string(name)].insert(id);
    LogicalFile.close();
}

int Product::Update(int id, int price, int stock)
{
    int pos = ReturnPosition(id);
    if (pos == -1)
    {
        return 0;
    }
    LogicalFile.open(file_name, ios::binary | ios::in | ios::out);
    LogicalFile.seekg(pos, ios::beg);
    Read();
    LogicalFile.seekp(pos, ios::beg);
    this->price = price;
    this->stock = stock;
    Write();
    LogicalFile.close();
    return 1;
}


int Product::Delete(int id)
{
    int pos = ReturnPosition(id);
    if (pos == -1)
    {
        return 0;
    }
    LogicalFile.open(file_name, ios::in | ios::out | ios::binary);
    LogicalFile.seekg(pos, ios::beg);
    Read();
    LogicalFile.seekp(pos, ios::beg);
    LogicalFile.put('*');
    Avail_List.push_back(AvailList(Count(pos), pos));
    LogicalFile.close();
    indexes.primary_keys.erase(id);
    indexes.secondary_keys[name].erase(id);
    return 1;
}


int Product::BestFit(int size)
{
    int pos = -1;
    int ind;
    int mn = 1e9;
    for (int i = 0; i < Avail_List.size(); i++)
    {
        if (Avail_List[i].sz >= size && Avail_List[i].sz < mn)
        {
            mn = Avail_List[i].sz;
            ind = i;
            pos = Avail_List[i].offset;
        }
    }
    if (pos != -1)
        Avail_List.erase(Avail_List.begin() + ind);

    return pos;
}

int Product::ReturnPosition(int id)
{
	if (indexes.primary_keys.find(id) == indexes.primary_keys.end())
    {
		return -1;
	}
	return *indexes.primary_keys[id].begin();
}

set<int>& Product::ReturnPosition(char name[20])
{
    return indexes.secondary_keys[string(name)];
}


void Product::save_files()
{
    indexes.write(primary_file_name, secondary_file_name);


    LogicalFile.open(deleted_file_name, ios::out | ios::binary);
    for (int i = 0; i < Avail_List.size(); ++i)
    {
        int sz = Avail_List[i].sz, offset = Avail_List[i].offset;
        LogicalFile.write((char*)&offset, sizeof(offset));
        LogicalFile.write((char*)&sz, sizeof(sz));
    }  
    LogicalFile.close();
}

void Product::load_files()
{
    LogicalFile.open(file_name, ios::in | ios::out | ios::binary);
    if (!LogicalFile.is_open())
    {
        LogicalFile.open(file_name, ios::out | ios::binary);
        LogicalFile.close();
    }
    else
        LogicalFile.close();

    indexes.read(primary_file_name, secondary_file_name);
    LogicalFile.open(deleted_file_name, ios::in | ios::out | ios::binary);
    if (LogicalFile.is_open())
    {
        LogicalFile.seekp(0, ios::end);
        int size = LogicalFile.tellp();
        LogicalFile.seekg(0, ios::beg);
        
        while (LogicalFile.tellg() < size && !LogicalFile.eof())
        {
            AvailList temp;
            LogicalFile.read((char*)&temp.offset, sizeof(temp.offset));
            LogicalFile.read((char*)&temp.sz, sizeof(temp.sz));
            Avail_List.push_back(temp);
        }
        LogicalFile.close();
    }
}