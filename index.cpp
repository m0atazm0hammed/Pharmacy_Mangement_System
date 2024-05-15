#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "index.h"

indx::indx()
{
	primary_keys = {};
	secondary_keys = {};
}

void indx::write(std::string &fileName, std::string &secondFileName)
{
	fstream file(fileName, ios::out | ios::trunc | ios::binary);
	for (auto &[key, values] : primary_keys)
	{
		for (auto &value : values)
		{
			file.write((char *)&key, sizeof(key));
			file.put('|');
			file.write((char *)&value, sizeof(value));
			file.put('|');
		}
	}
	file.close();
	file.clear();
	file.open(secondFileName, ios::out | ios::trunc | ios::binary);
	for (auto &[key, values] : secondary_keys)
	{
		for (auto &value : values)
		{
			file.write((char *)&key, key.size());
			file.put('|');
			file.write((char *)&value, sizeof(value));
			file.put('|');
		}
	}
	file.close();
}

void indx::read(std::string &fileName, std::string &secondFileName)
{
	fstream file(fileName, ios::in | ios::binary);
	if (file.fail())
		return;
	std::cerr << 'g' << std::endl;
	file.seekg(0, ios::end);
	int size = file.tellg();
	file.clear();
	file.seekg(0, ios::beg);
	std::cerr << file.tellg() << std::endl;
	while (file.tellg() < size && !file.eof())
	{
		int key;
		int value;
		streamsize sz = 0;
		file.read((char *)&key, sizeof(key));
		file.get();
		file.read((char *)&value, sizeof(value));
		file.get();
		primary_keys[key].insert(value);
	}
	std::cerr << 'g' << std::endl;
	file.close();
	file.open(secondFileName, ios::in | ios::binary);
	if (file.fail())
		return;
	file.seekp(0, ios::end);
	size = file.tellp();

	file.clear();
	file.seekg(0, ios::beg);
	std::cerr << 'g' << std::endl;

	while (file.tellg() < size && !file.eof())
	{
		string key;
		int value;
		streamsize sz = 0;
		file.getline((char *)&key, sz, '|');
		file.read((char *)&value, sizeof(value));
		file.get();
		std::cerr << key << std::endl << value << std::endl;
		secondary_keys[key].insert(value);
		break;
	}
	std::cerr << 'g' << std::endl;
	file.close();
}
