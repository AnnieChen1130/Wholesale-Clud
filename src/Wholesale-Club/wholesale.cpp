#include "wholesale.h"

Wholesale::Wholesale():name(""),id(0),expiration(""),spent(0.0)
{
    type = false;
}

Wholesale::Wholesale(string n, int ID, bool IsPreferred, string date, double money)
{
    name = n;
    id = ID;
    type = IsPreferred;
    expiration = date;
    spent = money;

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
    return type;
}

string Wholesale::getExpiration()
{
    return expiration;
}

double Wholesale::getSpent()
{
     return spent;
}

LinkedList<Item> Wholesale::getList()
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

void Wholesale::printStatus()
{
    std::cout << "Member's Status:\n"
              << "Member's Name: " << name << std::endl
              << "Member's ID number: "<< id << std::endl
              << "Member's type: ";
     if(type)
         std::cout << "Preferred.\n";
     else
         std::cout << "Basic.\n";
     std::cout << "Expiration Date: " << expiration << std::endl
               << "Total amount of spent: $" << spent << std::endl;


//     std::cout << "Name ID Type Expiration Date Total amount of spent\n";
//     std::cout << name <<" " << id << " " ;
//     if(type)
//         std::cout << "Preferred ";
//     else
//         std::cout << "Basic ";
//     std::cout << expiration << " " << "$" << spent <<std::endl;


}

void Wholesale::printINTOfile(string fileName)
{
    ofstream outFile;

    outFile.open(fileName, std::ios_base::app);
    if (outFile.fail())
    {
        cout<<"Output file opening failed.\n";
    }

    outFile << name <<" " << id << " " ;
    if(type)
        outFile << "Preferred ";
    else
        outFile << "Basic ";
    outFile << expiration << " " << "$" << spent <<endl;

    outFile.close();
}

ostream& operator<<(ostream& out, Wholesale member)
{
    out << member.name <<" " << member.id << " " ;
    if(member.type)
        out << "Preferred ";
    else
        out << "Basic ";
    out << member.expiration << " " << "$" << member.spent <<endl;

    return out;
}

bool Wholesale::operator ==(const Wholesale& member) const
{
    return id == member.id;
}

bool Wholesale::operator != (const Wholesale& member) const
{
    return id != member.id;
}

bool Wholesale::operator < (const Wholesale& member) const
{
    return name < member.name;
}

bool Wholesale::operator > (const Wholesale& member) const
{
    return name > member.name;
}

bool Wholesale::operator <= (const Wholesale& member) const
{
    return name < member.name || name == member.name;
}

bool Wholesale::operator >= (const Wholesale& member) const
{
    return name > member.name || name == member.name;
}
