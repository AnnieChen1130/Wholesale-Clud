#include "item.h"

Item::Item(string item, int number, double rate)
{
    name = item;
    quantity = number;
    price = rate;
}

int Item::getQuantity(){
    return quantity;
}

void Item::setQuantity(int number){
    quantity = number;
}

string Item::getName(){
    return name;
}

void Item::setName(string item){
    name = item;
}

double Item::getPrice(){
    return price;
}

void Item::setPrice(double rate){
    price = rate;
}

ostream& operator<<(ostream& out, Item item){
    out<<item.name<<" , quantity is "<<item.quantity<<" , $"<<item.price;
    return out;
}
