#pragma once

#include <sstream>
#include "Base.h"

class Shape : public Printable
{

};

class Point : public Shape, public Named
{
public:
    Point(double x, double y) : Named("Point")
    {
        this->x = x;
        this->y = y;
    }

    virtual std::string print() override
    {
        std::stringstream formatStream;
        formatStream << Named::print( )
                     << "("
                     << x << ", " << y
                     << ")";
        return formatStream.str( );
    }

private:
    double x;
    double y;
};