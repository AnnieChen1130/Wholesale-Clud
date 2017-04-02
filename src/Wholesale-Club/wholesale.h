#ifndef WHOLESALE_H
#define WHOLESALE_H
#include "iostream"
#include "item.h"
#include "LinkedList.h"
#include "linkedlist.h"
#include <fstream>

using namespace std;

class Wholesale
{
public:
    Wholesale();
    Wholesale(string n, int ID, bool IsPreferred, string date, double money);


    string getName();
    void setName(string member);
    int getId();
    void setId(int number);
    bool getType();
    void setType(bool membership);
    string getExpiration();
    void setExpiration(string date);
    double getSpent();
    void setSpent(double total);
    LinkedList<Item> getList();
    void setList(LinkedList<Item> items);

    //list of item, quantities sold, names of the members who shopped, total revenue
    void printStatus();
    //search list by id
    LinkedList<Item> findTotalPurchases(int id);
    //search list by memeber name
    LinkedList<Item> findTotalPurchases(string name);
    //return true if membership is expired
    bool membershipIsExpired();
    //return true if prefer else false
    bool isPrefer();
    //add item to my(member) list
    void addItem(Item item);

    void printINTOfile(string fileName);
    //print out by name,quantity,price for testing
    friend ostream& operator<<(ostream& out,Wholesale member);
    bool operator == (const Wholesale& member) const;
    bool operator != (const Wholesale &member) const;
    bool operator < (const Wholesale& member) const;
    bool operator > (const Wholesale& member) const;
    bool operator <= (const Wholesale& member) const;
    bool operator >= (const Wholesale& member) const;


private:
    string name;
    int id;
    bool type;
    string expiration;
    double spent;
    LinkedList<Item> list;
};

#endif // WHOLESALE_H
