#include "wholesale.h"

Wholesale::Wholesale()
{

}

string Wholesale::getName()
{
    return name;
}

int Wholesale::getId()
{
    return id;
}

bool Wholesale::getType()
{
    return tyep;
}

string Wholesale::getExpiration()
{
    return expiration;
}

double Wholesale::getSpent()
{
     return spent;
}

vector<Item> Wholesale::getList()
{
    return list;
}

void Wholesale::setName(string member)
{
    name = member;
}

void Wholesale::setId(int number)
{
    id = number;
}

void Wholesale::setType(bool membership)
{
    type = membership;
}

void Wholesale::setExpiration(string date)
{
    expiration = date;
}

void Wholesale::setSpent(double total)
{
    spent = total;
}
