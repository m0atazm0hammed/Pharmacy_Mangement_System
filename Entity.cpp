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
    primary_index = other.primary_index;
    secondary_index = other.secondary_index;
    Avail_List = other.Avail_List;  
}

void Entity::Add()
{
    
    LogicalFile.open(file_name, ios::in | ios::out | ios::binary);
    int offset = FirstFit(Size());

    if (offset == -1)
    {
        LogicalFile.seekp(0, ios::end);
        offset = LogicalFile.tellp();
    }
    LogicalFile.seekp(offset, ios::beg);
    Write();
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
    Avail_List.push_back(AvailList(Size(), pos));
    primary_index.keys.erase(id);
    secondary_index.keys[name].erase(id);
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

    primary_index.read(primary_file_name);
    secondary_index.read(secondary_file_name);
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
    primary_index.write(primary_file_name);

    secondary_index.write(secondary_file_name);

    LogicalFile.open(deleted_file_name, ios::out | ios::binary);
    for (auto i : Avail_List)
    {
        LogicalFile.write((char*)&i.offset, sizeof(i.offset));
        LogicalFile.write((char*)&i.sz, sizeof(i.sz));
    }
    LogicalFile.close();
}

int Entity::FirstFit(int size)
{
    int pos = -1;
    int mn = 1e9;
    for (int i = 0; i < Avail_List.size(); i++)
    {
        if (Avail_List[i].sz >= size && Avail_List[i].sz < mn)
        {
            mn = Avail_List[i].sz;
            pos = Avail_List[i].offset;
        }
    }
    return pos;
}

int Entity::ReturnPosition(int)
{
	if (primary_index.keys.find(id) == primary_index.keys.end())
    {
		return -1;
	}
	return *primary_index.keys[id].begin();
}

set<int>& Entity::ReturnPosition(char name[20])
{
    return secondary_index.keys[string(name)];
}

void Entity::Write()
{
    
}

void Entity::Read()
{
    
}

int Entity::Size()
{
}


void Entity::Name(char name[20])
{
    strcpy_s(this->name, name);
}

void Entity::Id(int id)
{
    this->id = id;
}