#pragma once
class AvailList
{
public:
	int sz, offset;
	AvailList();
	AvailList(int, int);
	AvailList(const AvailList&);
};

