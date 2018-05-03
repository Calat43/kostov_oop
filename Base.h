#pragma once

#include <string>

class Printable
{
public:
    virtual std::string print() = 0;
};

class Named : public Printable
{
public:
    Named(const std::string & name)
    {
        this->name = name;
    }

    virtual std::string print() override
    {
        return name;
        // ? return "Named: " + name;
    }

private:
    std::string name;
};