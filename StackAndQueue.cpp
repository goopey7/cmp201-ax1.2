// William Kavanagh, CMP201.2022
// AX1.2 Minimal Implementation

// *******************************
// Solved by Sam Collier - 2100259
// *******************************

#include <iostream>
#include "StackAndQueue.h"

// Default constructor, init array
ArrayStack::ArrayStack()
{
    // TODO: Unassessed
    arr = new int[capacity];
}

// Remove first element, return value.
int ArrayStack::Pop()
{
    // TODO: ASSESSED [1]
    if(stackTop == -1)
    {
        return NULL;
    }

    stackTop--;
    return arr[stackTop+1];
}

// Check first element, return value.
int ArrayStack::Peek()
{
    // TODO: ASSESSED [0.5]
    return arr[stackTop];
}

// Add element to top of stack, 
// calls DoubleArray() where appropriate
void ArrayStack::Push(int n)
{
    // TODO: ASSESSED [1]
    // [0.5] if correct without resizing.

    if(stackTop == capacity - 1)
    {
        DoubleArray();
    }
    stackTop++;
    arr[stackTop] = n;
    
}

// Print elements in Stack neatly
// DO NOT CHANGE: used for testing and assessment
void ArrayStack::Display()
{
    std::cout << arr[0] << "\t<- head" << std::endl;
    for (int i = 1; i < stackTop + 1; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

// Updates array pointer to new array of double the size
// elements are copied in from old array with position preserved.
void ArrayStack::DoubleArray()
{
    // TODO: Unassessed
    capacity *= 2;
    int* newArr = new int[capacity];
    for(int i=0;i<capacity/2;i++)
    {
        newArr[i] = arr[i];
    }
    delete arr;
    arr = newArr;
}

// Node constructor
Node::Node(int n)
{
    // TODO: Unassessed
    data = n;
    next = nullptr;
}

// QL constructor
QueueList::QueueList()
{
    // TODO: ASSESSED [0.5]
    front = nullptr;
    back = nullptr;
}

// Add item to back of queue
void QueueList::Enqueue(int n)
{
    // TODO: ASSESSED [1]
    
    // make new node
    Node* toTheBack = new Node(n);

    // if line was empty
    if(front == nullptr && back == nullptr)
    {
        front = toTheBack;
        back = toTheBack;
        return;
    }

    // otherwise we put you in the back of the line

    back->next = toTheBack;
    back = toTheBack;
}

// Remove item from front of queue
int QueueList::Dequeue()
{
    // TODO: ASSESSED [1]

    // if list is empty return NULL macro
    if(front == nullptr && back == nullptr)
    {
        // NULL macro ew
        return NULL; // warning's usually means bad practice
        // seems to just get converted to a plain old 0
        // with gcc at least
    }

    int valueToReturn = front->data; // capture value to return so we can return after deleting
    Node* tillNumberFourPlease = front; // capture guy in front's addy so we can delete later
    front = front->next; // Nobody in front of this dude now
    delete tillNumberFourPlease; // leaving the line. DELETE
    return valueToReturn; // return the customer's number
}

// Print elements in Stack neatly
// DO NOT CHANGE: used for testing and assessment
void QueueList::Display()
{
    if (!front)
    {
        std::cout << "[]";
        return;
    }
    Node* n = front;
    std::cout << "f: ";
    while (n != back)
    {
        std::cout << n->data << ",\t";
        n = n->next;
    }
    std::cout << "b: " << n->data << std::endl;
}

