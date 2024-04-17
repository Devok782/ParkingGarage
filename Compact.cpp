#include "Compact.h"

Compact::Compact(int arrived, int parked, string numbers) : Vehicle(arrived, parked, numbers)
{

}

Compact::~Compact()
{

}

CarType Compact::getType() const
{
    return type;
}