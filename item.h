#ifndef ITEM_H
#define ITEM_H
#include "iostream"
#include <string.h>
#include "linkedlist.h"

using namespace std;

class Item
{
public:
    Item( string item = "",int number = 0, double rate =0 );

    int getQuantity();
    void setQuantity(int number);
    string getName();
    void setName(string item);
    double getPrice();
    void setPrice(double rate);
    double revenue();
    
    //print out by name,quantity,price for testing
    friend ostream& operator<<(ostream& out, Item item);
    //return true if the items have the same name
    bool operator == (const Item& member) const;
private:
    int quantity;
    string name;
    double price;
};

#endif // ITEM_H
