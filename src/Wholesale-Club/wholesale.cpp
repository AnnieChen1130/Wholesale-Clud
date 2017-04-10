#include "wholesale.h"

Wholesale::Wholesale():name(""),id(""),type(""),expiration(""),spent(0.0)
{}

Wholesale::Wholesale(string n, string ID, string membershipType, string date, double money)
{
    name = n;
    id = ID;
    type = membershipType;
    expiration = date;
    spent = money;

}

string Wholesale::getName()
{
    return name;
}

string Wholesale::getId()
{
    return id;
}

string Wholesale::getType()
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

void Wholesale::setId(string number)
{
    id = number;
}

void Wholesale::setType(string membership)
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

bool Wholesale::isPrefer()
{
    if(type == "Preferred")
        return true;
    else
        return false;

}

ostream& operator<<(ostream& out, Wholesale member)
{
    out << member.name << std::endl << member.id << std::endl << member.type
        << std::endl << member.expiration << std::endl;

    return out;
}

string Wholesale::coutString()
{
    std::string out = "";
    out += name;
    out += "\n";
    out += id;
    out += "\n";
    out += type;
    out += "\n";
    out += expiration;
    out += "\n";

    return out;
}




void Wholesale::printStatus()
{
    std::cout << "Member's Status:\n"
              << "Member's Name: " << name << std::endl
              << "Member's ID number: "<< id << std::endl
              << "Member's type: " << type <<std::endl
              << "Expiration Date: " << expiration << std::endl
              << "Total amount of spent: $" << spent << std::endl;

}

string Wholesale::printStatusString()
{
    std::string out = "";
    out += "Member's Status:\n";
    out += "Member's Name: ";
    out += name;
    out += "\n";
    out += "Member's ID number: ";
    out += id ;
    out += "\n";
    out += "Member's type: ";
    out += type ;
    out += "\n";
    out += "Expiration Date: " ;
    out += expiration ;
    out += "\n";
    out += "Total amount of spent: $" ;
    out += std::to_string(spent) ;
    out += "\n";

    return out;

}



void Wholesale::printINTOfile(string fileName)
{
    ofstream outFile;

    outFile.open(fileName, std::ios_base::app);
    if (outFile.fail())
    {
        cout<<"Output file opening failed.\n";
    }

    outFile << name << std::endl << id << std::endl << type
            << std::endl << expiration << std::endl;

    outFile.close();
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

/*void Wholesale::addNewMember(LinkedList<Wholesale> memberList)
{
    string n;
    string ID;
    string membershipType;
    string date;
    double money;

    std::cout << "Enter new member's name: ";
    std::cin >> n;

    std::cout << "Enter new member's ID: ";
    std::cin >> ID;

    char ans;
    std::cout << "Is preferred member, enter 'Y', not enter ''N: ";
    std::cin >> ans;

    if(ans == 'y' || ans == 'Y')
        membershipType = "Preferred";
    else
        membershipType = "Basic";

    std::cout << "Enter expiration date: ";
    std::cin >> date;

    money = 0;



    Wholesale newMember(n, ID, membershipType, date, money);
    newMember.printStatus();

    //add new member into list
    memberList.push_back(newMember);

    //add new member into file
    newMember.printINTOfile("Wholesale_Member.txt");
}
*/


void Wholesale::addNewMember(string n,
                             string ID,
                             string membershipType,
                             string date,
                             LinkedList<Wholesale> memberList)
{
    double money=0;

    Wholesale newMember(n, ID, membershipType, date, money);
    //    newMember.printStatus();

    //add new member into list
    memberList.push_back(newMember);

    //add new member into file
    newMember.printINTOfile("Wholesale_Member.txt");
}









//void readFromFile(LinkedList<Wholesale> memberList)
//{
//    fstream inFile;
//    Wholesale member;
//    string name;
//    string ID;
//    string type;
//    string expiration;



//    inFile.open("warehouse shoppers.txt");
//    if (inFile.fail())
//       {
//           cout<<"Input file opening failed.\n";
//           //exit(1);
//       }

//    while(!inFile.eof())
//    {

//        getline(inFile, name, '\n');
//        getline(inFile, ID, '\n');
//        getline(inFile, type, '\n');
//        getline(inFile, expiration, '\n');

//        member.setName(name);
//        member.setId(ID);
//        member.setType(type);
//        member.setExpiration(expiration);
//        member.setSpent(0);

//        memberList.push_back(member);


//    }
//    inFile.close();

//    memberList.display();

//}

























