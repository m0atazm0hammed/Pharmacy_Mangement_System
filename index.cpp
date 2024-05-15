#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "index.h"


indx::indx()
{
}

void indx::write(std::string &fileName, std::string &secondFileName)
{
    fstream file(fileName, ios::out | ios::trunc | ios::binary);
	for (auto& [key, values] : primary_keys) {
		for (auto& value : values) {
			file.write((char*)&key, sizeof(key));
			file.put('|');
			file.write((char*)&value, sizeof(value));
			file.put('|');
		}
	}
	file.close();
	file.open(secondFileName, ios::out | ios::trunc | ios::binary);
	for (auto& [key, values] : secondary_keys) {
		for (auto& value : values) {
			file.write((char*)&key, sizeof(key));
			file.put('|');
			file.write((char*)&value, sizeof(value));
			file.put('|');
		}
	}
	file.close();
}

void indx::read(std::string &fileName, std::string &secondFileName) {
	fstream file(fileName, ios::in | ios::binary);
	if (file.fail())
		return;
	file.seekp(0, ios::beg);
	while (!file.eof()) {
		int key;
		int value;
		file.read((char*)&key, '|');
		file.read((char*)&value, '|');
		primary_keys[key].insert(value);

	}
	file.close();
	file.open(secondFileName, ios::in | ios::binary);
	if (file.fail())
		return;
	file.seekp(0, ios::beg);
	while (!file.eof()) {
		string key;
		int value;
		file.read((char*)&key, '|');
		file.read((char*)&value, '|');
		secondary_keys[key].insert(value);
	}
	file.close();
}

