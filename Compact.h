#ifndef COMPACT_H
#define COMPACT_H

#include "Vehicle.h"

class Compact : public Vehicle
{
    private:
        const CarType type = CarType::COMPACT;

    public:
        Compact();
        Compact(int, int, string);
        virtual ~Compact();
        virtual CarType getType() const;

};

#endif