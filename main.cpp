#include "StackAndQueue.h"
#include <iostream>

int main()
{
    // Stack test.

    ArrayStack* stack = new ArrayStack();
    std::cout << "POP EMPTY STACK RETURN VAL: " << stack->Pop() << '\n';
    stack->Push(20);
    stack->Push(30);
    stack->Push(40);
    std::cout << "Testing stack, expecting: \nh:20,\t30,\t40.\nGot: \n";
    stack->Display();
    std::cout << "\n";
    stack->Pop();
    stack->Push(50);
    std::cout << "Show me 50: " << stack->Peek() << "\n";
    std::cout << "Testing stack, expecting: \nh:20,\t30,\t50\nGot: \n";
    stack->Display();

    // Check Overflow

    ArrayStack* bigStack = new ArrayStack();
    for (int i = 0; i < 100; i++)
    {
        bigStack->Push(i);
    }
    std::cout << "Expecting stack of 0..99:\n";
    bigStack->Display();
    std::cout << "Expecting stack capacity of 2^7. capacity is actually: " << bigStack->capacity << "\n";


    // Queue test.

    QueueList* q = new QueueList();
    q->Dequeue();
    q->Enqueue(25);
    q->Enqueue(40);
    q->Enqueue(7);
    std::cout << "Testing queue, expecting: \nf: 25,\t40,\tb: 7\nGot: \n";
    q->Display();

    q->Dequeue();           // remove 25 from queue, do nothing with it.
    q->Enqueue(45);
    std::cout << "Testing queue, expecting: \nf: 40,\t7,\tb: 45\nGot: \n";
    q->Display();

    return 0;
}
