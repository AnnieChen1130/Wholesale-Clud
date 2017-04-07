#include "club.h"
#include "item.h"

Club::Club()
{

}

//sorted id number and print out each purchase, and the grand total.
void Club::printSortedPurchase()
{

}



//enter the item and return the quantity sold.
//Then use the quantityXprice in a seperate function.
int Club::getQuantity(Item item)
{

  while(List.head != List.tail)
  (
     if(report->List.name == item.name)
     {
       return List.quantity;
     }
      
    List.head = List.head.next;
  }
    
}


//call the getQuantity and print out each quanity and price of the item   
void Club::printTotal(Item item)
{
  cout << item;
}


//call the getQuantity and print quantity by item name
void Club::printQuantityByName(Item item)
{
  cout << item.getName() << endl;
  cout << getQuantity(item);
}



//call printQuantityByName to print each item (sorted by item name)
void Club::printSortedQuantity()
{
  
}


//print rebate of preferred members
void Club::printRebate(Wholesale member)
{
  double rebate = 0;
  if(member.type)
  {
    rebate += 75;
    rebate += member.spent * 0.05;
  }
  else
  {
    rebate += 60;
  }
  
  cout << "Rebate: " << rebate << endl;
}

//sorted in member id and call printRebate
void Club::printSortedIdByRebate()
{
  LinkedList<Wholesale> *temp;
  LinkedList<Wholesale> *newTemp;
  LinkedList<Wholesale> *newList = new LiknedList<Wholesale>;
  
  temp = this.head;
  newList.push_back(temp);
  
  temp = temp.next
  string tempId = temp.id;
  
  if(tempID < head.id)
  {
    newList.push_front(temp);
  }
  else
  {
    newList.push_back(temp);
  }
  
  temp = temp.next;
  while(temp != NULL)
  {
    tempID = temp.id;
    newTemp = newLIst.head;
    
    while(tempID > newTemp.id)
    {
      if(newTemp.next == NULL)
      {
        newList.push_back(temp);
        break;
      }
      
      if(tempId < newTemp.next.id)
      {
        newList.insert(newTemp, temp);
        break;
      }
 
      newTemp = newTemp.next;
            
    }
    
    temp = temp.next;
    
  }
  
  newTemp = newList.head;
  while(newTemp != NULL)
  {
    cout << "ID: " << newTemp.id;
    printRebate(newTemp);
    newTemp = newTemp.next;
  }
  
}


//amount per year paid for membership dues
double Club::getMembershipDue()
{
  
}

//call getMembershipDue and print out the year paid by each member
//sorted in basic/prefer by member names
void Club::printSortedMembership()
{
  
}

//Take in the indicated month(index) of the vector
//call the wholesale function membershipIsExpired() and if true
//then call getMembershipDue()/12 to get the month
//then print out/ return a list of members that have expired membership
//by their due amount
void Club::printExpiredMembers(int month)
{
  
}

//add member to the list by creating a member using the constructor
//Then add the member to the list according to the given month and day
void Club::addTo(int month, int day, Wholesale member) //NOT CORRECT
{
  
}



void CLub::deleteAt(int month, int day, int index)//NOT CORRECT
{
  
}

//call wholesale.isPref() then determine if the member should change to basic
//or change to pref
//loop each member in the list
void Club::determineMembership()
{
  
}

//read from the file
void Club::getFile(string file)
{
  
}

//write to the file
void Club::writeTo(string report)
{
  
}
