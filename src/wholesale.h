#ifndef WHOLESALE_H
#define WHOLESALE_H
#include "iostream"
#include "item.h"
#include "vector"
using namespace std;

class Wholesale
{
public:
    Wholesale();

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
    vector<Item> getList();
    void setList(vector<Item> items);

    //list of item, quantities sold, names of the members who shopped, total revenue
    void printStatus();
    //search list by id
    vector<Item> findTotalPurchases(int id);
    //search list by memeber name
    vector<Item> findTotalPurchases(string name);
    //return true if membership is expired
    bool membershipIsExpired();
    //return true if prefer else false
    bool isPrefer();
    //add item to my(member) list
    void addItem(Item item);

private:
    string name;
    int id;
    bool type;
    string expiration;
    double spent;
    vector<Item> list;
};

#endif // WHOLESALE_H
