#include "Entity.h"

Entity::Entity() : id(-1), name("") { load_files(); }
Entity::Entity(int id, char name[20]) : id(id)
{ 
    strcpy_s(this->name, name);
    load_files(); 
}
Entity::~Entity() { save_files(); }
Entity::Entity(Entity& other) : id(other.id)
{
    strcpy_s(name, other.name);
    indexes.primary_keys = other.indexes.primary_keys;
    indexes.secondary_keys = other.indexes.secondary_keys;
    Avail_List = other.Avail_List;  
}

void Entity::Add()
{
    
    LogicalFile.open(file_name, ios::in | ios::out | ios::binary);
    int offset = BestFit(Size());

    if (offset == -1)
    {
        LogicalFile.seekp(0, ios::end);
        offset = LogicalFile.tellp();
    }
    LogicalFile.seekp(offset, ios::beg);
    Write();
    indexes.primary_keys[id].insert(offset);
    indexes.secondary_keys[string(name)].insert(id);
    LogicalFile.close();
}

int Entity::Update(int id)
{
    int pos = ReturnPosition(id);
    if (pos == -1) {
        return 0;
    }
    LogicalFile.open(file_name, ios::binary | ios::in | ios::out);
    LogicalFile.seekg(pos, ios::beg);
    Read();
    LogicalFile.seekp(pos, ios::beg);
    Write();
    LogicalFile.close();
    return 1;
}

int Entity::Delete(int id)
{
    int pos = ReturnPosition(id);
    if (pos == -1) {
        return 0;
    }
    LogicalFile.open(file_name, ios::in | ios::out | ios::binary);
    LogicalFile.seekg(pos, ios::beg);
    Read();
    LogicalFile.seekp(pos, ios::beg);
    LogicalFile.put('*');
    LogicalFile.close();
    Avail_List.push_back(AvailList(Count(pos), pos));
    indexes.primary_keys.erase(id);
    indexes.secondary_keys[name].erase(id);
    return 1;
}

void Entity::load_files()
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
        while (!LogicalFile.eof())
        {
            AvailList temp;
            LogicalFile.read((char*)&temp.offset, sizeof(temp.offset));
            LogicalFile.read((char*)&temp.sz, sizeof(temp.sz));
            Avail_List.push_back(temp);
        }
        LogicalFile.close();
    }
}

void Entity::save_files()
{
    indexes.write(primary_file_name, secondary_file_name);


    LogicalFile.open(deleted_file_name, ios::out | ios::binary);
    for (auto i : Avail_List)
    {
        LogicalFile.write((char*)&i.offset, sizeof(i.offset));
        LogicalFile.write((char*)&i.sz, sizeof(i.sz));
    }  
    LogicalFile.close();
}

int Entity::BestFit(int size)
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

int Entity::ReturnPosition(int id)
{
	if (indexes.primary_keys.find(id) == indexes.primary_keys.end())
    {
		return -1;
	}
	return *indexes.primary_keys[id].begin();
}

set<int>& Entity::ReturnPosition(char name[20])
{
    return indexes.secondary_keys[string(name)];
}

void Entity::Write()
{
    
}

void Entity::Read()
{
    
}

int Entity::Size()
{
    return 7;
}


void Entity::Name(char name[20])
{
    strcpy_s(this->name, name);
}

void Entity::Id(int id)
{
    this->id = id;
}

int Entity::Count(int offset)
{
    string s;
    LogicalFile.seekg(offset, ios::beg);
    LogicalFile.get();
    streamsize sz = 0;
    LogicalFile.getline((char *) &s, sz, '$');
    int r = LogicalFile.tellg();
    LogicalFile.seekg(offset, ios::beg);
    LogicalFile.get();
    LogicalFile.getline((char *) &s, sz, '*');
    r = min(r, (int)LogicalFile.tellg());
    return (r - offset);
}