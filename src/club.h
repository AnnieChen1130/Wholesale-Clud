#ifndef CLUB_H
#define CLUB_H
#include "wholesale.h"

class Club
{
public:
    Club();
    //sorted id number and print out each purchase, and the grand total.
    void printSortedPurchase();
    //enter the item and return the quantity sold.
    //Then use the quantityXprice in a seperate function.
    int getQuantity(Item item);
    //call the getQuantity and print out each quanity and price of the item
    void printTotal(Item item);
    //call the getQuantity and print quantity by item name
    void printQuantityByName(Item item);
    //call printQuantityByName to print each item (sorted by item name)
    void printSortedQuantity(Item item);
    //print rebate of preferred members
    void printRebate(Wholesale member);
    //sorted in member id and call printRebate
    void printSortedIdByRebate();
    //amount per year paid for membership dues
    double getMembershipDue();
    //call getMembershipDue and print out the year paid by each member
    //sorted in basic/prefer by member names
    void printSortedMembership();
    //Take in the indicated month(index) of the vector
    //call the wholesale function membershipIsExpired() and if true
    //then call getMembershipDue()/12 to get the month
    //then print out/ return a list of members that have expired membership
    //by their due amount
    void printExpiredMembers(int month);
    //add member to the list by creating a member using the constructor
    //Then add the member to the list according to the given month and day
    void addTo(int month, int day, Wholesale member); //NOT CORRECT
    //delete member by month and day and order(index)
    //a testing function
    void deleteAt(int month, int day, int index); //NOT CORRECT
    //call wholesale.isPref() then determine if the member should change to basic
    //or change to pref
    //loop each member in the list
    void determineMembership();
    //read from the file
    void getFile(string file);
    //write to the file
    void writeTo(string report);

private:
    vector<Wholesale*> report;
};

#endif // CLUB_H
