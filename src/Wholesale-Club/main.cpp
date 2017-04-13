#include <iostream>
#include <wholesale.h>
#include <fstream>

using namespace std;

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
    Wholesale m1("Annie", "101", "Prefered","11/30/2017",100.10),
            m2("Tony", "102", "Basic", "01/01/2018", 6089.1),
            m3;

    m3.setName("Amy");
    m3.setId("103");
    m3.setType("Prefered");
    m3.setExpiration("05/08/2018");
    m3.setSpent(122.43);

    cout << endl << "----- m1 -----" << endl;
    m1.printStatus();
    m1.printINTOfile("Wholesale_Member.txt");
    cout << endl << "----- m2 -----" << endl;
    m2.printStatus();
    m2.printINTOfile("Wholesale_Member.txt");

    m3.printStatus();
    m3.printINTOfile("Wholesale_Member.txt");

    cout << endl;
    LinkedList<Wholesale> memberList;

    memberList.push_back(m2);
    memberList.push_back(m3);
    memberList.push_back(m1);

    cout << "Memberlist: \n";
    memberList.display();

    cout << endl <<endl;

    memberList.select_sort();
    memberList.display();

    cout << endl << endl;

    memberList.remove(m2);
    memberList.display();

    cout << endl << endl;

    memberList.insert_sorted(m2);
    memberList.display();

    return 0;
}
