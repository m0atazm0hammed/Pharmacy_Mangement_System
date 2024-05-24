#pragma once
#include "Entity.h"
class Product : public Entity
{
public:
	
	int price, stock;
	char exp_date[11];
	Product();
	Product(int, char[20], int, int, int, char[11]);
	Product(Product &other);
	~Product();

	void Write();
	int Size();
	void Read();
	void Add();
	int Delete(int);
	int Update(int, int, int);

	void Price(int price);
	void Stock(int stock);
	void Size(int size);
	void Exp_date(char exp_date[11]);

	int ReturnPosition(int);
	set<int> &ReturnPosition(char[20]);

	int BestFit(int);
	

	void load_files();
	void save_files();

};
