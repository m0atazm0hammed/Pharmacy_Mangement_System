#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "index.h"
#include "varlen.h"

//Global Variable(s)
fstream LogicalFile;

template<class T>
void index<T>::write(std::string& fileName) {
	fstream file(fileName, ios::out | ios::trunc | ios::binary);
	logicalFile.seekp(0, ios::beg);
	for (auto& [key, values] : keys) {
		for (auto& value : values) {
			file.write((char*)&key, sizeof(key));
			file.put('|');
			file.write((char*)&value, sizeof(value));
			file.put('|');
		}
	}
	file.close();
}

template<class T>
void index<T>::read(std::string& fileName) {
	fstream file(fileName, ios::in | ios::binary);
	if (file.fail())
		return;
	logicalFile.seekp(0, ios::beg);
	while (!file.eof()) {
		T key;
		int value;
		file.read((char*)&key, '|');
		file.read((char*)&value, '|');
		add(key, value);
	}
	file.close();
}

template<class T>
void index<T>::add(T key, int val) {
	keys[key].insert(values);
}

template<class T>
void index<T>::update(T key, int old_val, int new_val) {
	if (keys[key].find(old_val) != keys[key].end())
		keys[key].erase(keys[key].find(old_val));

	keys[key].insert(new_val);
}

