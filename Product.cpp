#include "Product.h"


Product::Product() : Entity()
{
    price = stock = size = -1;
    strcpy_s(exp_date, "");
}

Product::Product(int id, char name[20], int price, int stock, int size, char exp_date[11]) : Entity(id, name), price(price), stock(stock), size(size)
{
    strcpy_s(this->exp_date, exp_date);
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
    LogicalFile.getline(name, sz, '|');
    LogicalFile.read((char*)&price, sizeof(price));
    LogicalFile.read((char*)&stock, sizeof(stock));
    LogicalFile.read((char*)&size, sizeof(size));
    LogicalFile.getline(exp_date, sz, '|');
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