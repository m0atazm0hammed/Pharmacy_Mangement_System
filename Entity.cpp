#include "Entity.h"
#include <iostream>

Entity::Entity() : id(-1), name("") {}
Entity::Entity(int id, char name[20]) : id(id)
{ 
    strcpy_s(this->name, name);

}
Entity::~Entity() {  }
Entity::Entity(Entity& other) : id(other.id)
{
    strcpy_s(name, other.name);
    indexes.primary_keys = other.indexes.primary_keys;
    indexes.secondary_keys = other.indexes.secondary_keys;
    Avail_List = other.Avail_List;  
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