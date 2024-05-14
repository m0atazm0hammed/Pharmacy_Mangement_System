#include "AvailList.h"

AvailList::AvailList()
{
    sz = offset = -1;
}

AvailList::AvailList(int sz, int offset) : sz(sz), offset(offset) {}
