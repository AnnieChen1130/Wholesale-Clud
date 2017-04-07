#ifndef LINKEDLIST_H
#define LINKEDLIST_H
//#include "wholesale.h"
#include <iostream>
#include <fstream>

using namespace std;
template<typename E>
struct Node{
    E data;             //IN - the value of node
    Node *next;         //IN - the pointer point to next pointer
    Node *prev;         //IN - the pointer point to previouse pointer
    Node( E data ) : data(data), next(0),prev(0) {}
};


template<typename E>
class LinkedList
{
private:
    Node<E> *head;      //IN - the pointer point to the first node
    Node<E> *tail;      //IN - the pointer point to the last node
    //Delete value at the front
    void pop_front();
    //Insert value at the front
    void push_front( const E& value );              //IN - the value to insert
    


public:

    //Default constructor
    LinkedList();

    //Distructor: delete list
    ~LinkedList();

    //Display list
    void display() const;


    //Insert value at the end
    void push_back( const E& value );               //IN - the value to insert


    //Sort list
    void select_sort();

    //Insert value into a sorted list
    void insert_sorted( const E& value );           //IN - the value to insert

    //Remove specific value
    void remove(E value);                    //IN - the value to remove


    void printListINTOfile(string fileName);

    int ListSize();

    void insert(E* value);

};



//Default head to 0, tail to 0
template<typename E>
LinkedList<E>::LinkedList():head(0),tail(0)
{}

//Deallocate all remaining dynamically allocated memory
template<typename E>
LinkedList<E>::~LinkedList()
{
    while (head != 0)
    {
        pop_front();
    }

    head = NULL;
    tail = NULL;
}


/*******************************************************
 * FUNCTION: void LinkedList::display() const
 *      Display all the values in the list
 *      - RETURNS: nothing
 *______________________________________________________
 * PRECONDITION:
 *    Will need to define:
 *       temp  - a temporary pointer
 * POSTCONDITION:
 *      This function will display all the values in the list
 *******************************************************/
template<typename E>
void LinkedList<E>::display() const{

    Node<E> *temp;  //OUT - a pointer used to display
    temp = head;

    while(temp !=0 )
    {
        std::cout << temp->data;
        temp = temp->next;
    }
}

/*******************************************************
 * FUNCTION: void LinkedList::push_front( int value )
 *      Inserts a data value at the front of the list
 *      - RETURNS: nothing
 *______________________________________________________
 * PRECONDITION:
 *    Will need to define:
 *       newNode  - a new pointer with a new value
 * POSTCONDITION:
 *      This function will inserts a data value
 *          at the front of the list
 *******************************************************/
template<typename E>
void LinkedList<E>::push_front( const E& value  //IN - the value to insert
                                ){

    Node<E> *newNode;   //IN - new node to hold inserted value
    newNode = new Node<E>(value);

    if(head ==0 )
    {
        head = newNode;
        tail = newNode;
        newNode->next = 0;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

/*******************************************************
 * FUNCTION: void LinkedList::push_back( int value )
 *      Inserts a data value at the end of the list
 *      - RETURNS: nothing
 *______________________________________________________
 * PRECONDITION:
 *    Will need to define:
 *       newNode  - a new pointer with a new value
 * POSTCONDITION:
 *      This function will inserts a data value
 *          at the end of the list
 *******************************************************/
template<typename E>
void LinkedList<E>::push_back( const E& value  //IN - the value to insert
                               ){

    Node<E> *newNode;   //IN - new node to hold inserted value
    newNode = new Node<E>(value);

    if(head ==0 )
    {
        head = newNode;
        tail = newNode;
        newNode->next = 0;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = 0;
        tail = newNode;
    }
}

/*******************************************************
 * FUNCTION: void LinkedList::pop_front()
 *      Remove the value at the front of the list
 *      - RETURNS: nothing
 *______________________________________________________
 * PRECONDITION:
 *    Will need to define:
 *       temp  - a temporary pointer
 * POSTCONDITION:
 *      This function will remove the value at the front of the list
 *******************************************************/
template<typename E>
void LinkedList<E>::pop_front()
{

    if(head == tail)
    {
        delete head;
        head = 0;
        tail = 0;
    }
    else
    {
        Node<E> *temp;  //IN - a pointer used to hold deleted node
        temp = head;

        head = head ->next;
        delete temp;
        temp = 0;
    }


}

/*******************************************************
 * FUNCTION: void LinkedList::select_sort()
 *      Sorts the list into ascending order using
 *  the selection sort algorithm
 *      - RETURNS: nothing
 *______________________________________________________
 * PRECONDITION:
 *    Will need to define:
 *      position  - a pointer used to track position
 *      search    - a pointer used to search min
 *      min       - a pointer used to hold min
 * POSTCONDITION:
 *      This function will sorts the list into ascending
 *  order using the selection sort algorithm.
 *******************************************************/
template<typename E>
void LinkedList<E>::select_sort(){

    Node<E> *position;      //IN - pointer used to trach position
    Node<E> *search;        //IN - pointer used to search min
    Node<E> *min;           //IN - pointer used to hold min

    //PROCESSING: position start at the beginning
    position = head;
    min = head;
    search = head;

    //PROCESSING: when position do not point at the end
    while(position)
    {
        //PROCESSING: when search is not at the end
        while(search)
        {
            //PROCESSING: check if search < position
            if(search->data < min->data)
            {
                //PROCESSING: if less, min = search;
                min = search;
            }

            //PROCESSING: go to the next search
            search = search->next;
        }

        //PROCESSING: switch
        E temp;
        temp = position->data;
        position->data = min->data;
        min->data = temp;

        //go to next position
        position = position->next;
        search = position;
        min = position;

    }

    Node<E> *last;
    last = head;
    while(last)
    {
        tail = last;
        last = last->next;
    }

}

/*******************************************************
 * FUNCTION: void LinkedList::insert_sorted( int value )
 *      Inserts the data into the appropriate position
 *  in the list
 *      - RETURNS: nothing
 *______________________________________________________
 * PRECONDITION:
 *    Will need to define:
 *      position  - a pointer used to track position
 *      insert    - a pointer used to hold insert data
 * POSTCONDITION:
 *      This function will inserts the data into
 *  the appropriate position in the list
 *******************************************************/
template<typename E>
void LinkedList<E>::insert_sorted( const E& value  //IN - the value to insert
                                   ){

    Node<E> *position;      //IN - pointer used to track position
    Node<E> *insert;        //IN - pointer used to hold insert data
    insert = new Node<E>(value);

    //PROCESSING: position start at the beginning
    position = head;

    //PROCESSING: when position do not point at the end
    while(position)
    {
        //PROCESSING: check if insert >= position
        if(insert->data >= position-> data)
        {
            //PROCESSING: check if position is at the end
            //insert newNode at the end
            if(position == tail)
            {
                position->next = insert;
                insert->prev = position;
                insert->next = NULL;

                tail = insert;
                break;
            }

            //PROCESSING: check if insert < position->next then insert value
            if(insert->data < position->next->data)
            {
                insert->next = position->next;
                position->next->prev = insert;
                position->next = insert;
                insert->prev = position;
                break;
            }

        }
        //PROCESSING: if newNode should be at the head
        else
        {
            insert->next = position;
            position->prev = insert;
            head = insert;
            break;
        }

        //go to next position
        position = position->next;

    }

}



/*******************************************************
 * FUNCTION: bool LinkedList<E>::remove(E value)
 *      Remove specific value in the list
 *      - RETURNS: nothing
 *______________________________________________________
 * PRECONDITION:
 *    Will need to define:
 *       temp  - a temporary pointer
 * POSTCONDITION:
 *      This function will remove specific value in the list
 *******************************************************/
template<typename E>
void LinkedList<E>::remove(E value) //IN - the value to remove
{
    Node<E> *current = head;

    while(current != 0 && current->data != value)
    {
        current = current->next;
    }

    if(current == 0) // not found same value
        return;

    Node<E> *previous = current->prev;
    if(previous != 0)
    {
        previous->next = current->next;
        if(current->next != 0)
            current->next->prev = previous;
        delete current;
    }
    else
    {
        head = current->next;
        head->prev = 0;
        delete current;
    }

,.    Node<E> *last;
    last = head;
    while(last)
    {
        tail = last;
        last = last->next;
    }


}

template<typename E>
void LinkedList<E>::printListINTOfile(string fileName)
{
    ofstream outFile;

    outFile.open(fileName);
    if (outFile.fail())
    {
        cout<<"Output file opening failed.\n";
    }

    Node<E> *temp;
    temp = head;

    while(temp)
    {
        outFile << temp->data;
        temp = temp->next;
    }




}

template<typename E>
int LinkedList<E>::ListSize()
{
    Node<E> *temp;
    temp = head;
    int count=0;

    while(temp)
    {
        count++;
        temp = temp->next;
    }

    return count;

}

template<typename E>
void insert(E target, E value)
{
    if(this.head == NULL)
    {
        this.push_back(value);
    }
    
        
    Node<E> *temp;
    temp = this.head;
        
    while(temp != target)
    {
        temp = temp.next;
    }
    
    value.next = temp.next;
    temp.next = value;
    
    while(this.tail.next != NULL)
    {
        tail = tail.next;
    }
}


#endif // LINKEDLIST_H
