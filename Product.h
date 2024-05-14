#pragma once
#include <Entity.h>
class Product : public Entity
{
private:
	int price, stock, size;
	char exp_date[11];
public:
	Product();
	Product(int, char[20], int, int, int, char[11]);
	Product(Product &other);
	~Product();

	void Write();
	int Size();
	void Read();
	
	void Price(int price);
	void Stock(int stock);
	void Size(int size);
	void Exp_date(char exp_date[11]);


};

