#include <iostream>
#include <wholesale.h>
#include <fstream>

using namespace std;
void readFromFile(LinkedList<Wholesale> memberList);
int main()
{
//    cout << "Hello World!" << endl;
//    Item item1("item1",3,100.0);
//    cout<<item1<<endl;
//    Item item2("item2",1,45);
//    cout<<item2<<endl;

//    ifstream inFile;
//    ofstream outFile;
//    inFile.open("Wholesale_Member.txt");
//    if (inFile.fail())
//    {
//        cout<<"Input file opening failed.\n";
//        //exit(1);
//    }

//    outFile.open("Wholesale_Member.txt");
//    if (outFile.fail())
//    {
//        cout<<"Output file opening failed.\n";
//    }

//    LinkedList<Wholesale> members;
//    Wholesale m1("Annie", 101, true,"11/30/2017",100.10),
//            m2("Tony",102, false, "01/01/2018", 6089.1),
//            m3;

//    m3.setName("Amy");
//    m3.setId(103);
//    m3.setType(true);
//    m3.setExpiration("05/08/2018");
//    m3.setSpent(122.43);

//    cout << endl << "----- m1 -----" << endl;
//    m1.printStatus();
//    m1.printINTOfile("Wholesale_Member.txt");
//    cout << endl << "----- m2 -----" << endl;

    LinkedList<Wholesale> memberList;

//    memberList.push_back(m2);
//    memberList.push_back(m3);
//    memberList.push_back(m1);

//    memberList.display();

//    cout << endl <<endl;

//    memberList.select_sort();
//    memberList.display();

//    cout << endl << endl;

//    memberList.remove(m2);
//    memberList.display();

//    cout << endl << endl;

//    memberList.insert_sorted(m2);
//    memberList.display();

//    cout << memberList.ListSize();

    readFromFile(memberList);
    memberList.display();





    cout << endl;
    return 0;
}

void readFromFile(LinkedList<Wholesale> memberList)
{
    fstream inFile;
    Wholesale member;
    string name;
    string ID;
    string type;
    string expiration;



    inFile.open("warehouse shoppers.txt");
    if (inFile.fail())
       {
           cout<<"Input file opening failed.\n";
           //exit(1);
       }

    while(!inFile.eof())
    {

        getline(inFile, name, '\n');
        getline(inFile, ID, '\n');
        getline(inFile, type, '\n');
        getline(inFile, expiration, '\n');

        member.setName(name);
        member.setId(ID);
        member.setType(type);
        member.setExpiration(expiration);
        member.setSpent(0);

        memberList.push_back(member);


    }
    inFile.close();

    memberList.display();

}

