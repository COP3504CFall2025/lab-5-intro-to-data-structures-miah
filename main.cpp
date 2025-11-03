#ifdef MAIN

#include "ABDQ.hpp"
#include "ABQ.hpp"
#include "ABS.hpp"
#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include "LLDQ.hpp"
#include "LLQ.hpp"
#include "LLS.hpp"
#include <iostream>
#include <list>
#include <unistd.h>

/*
    - LEAVE THE IFDEF GUARDS TO KEEP YOUR MAIN WITHOUT CONFLICTING WITH GRADESCOPE!
    - Test your code in this main and run locally with the RunMain configuration in CLion, or
    through your own command line compilation. Make sure to add flag "-DMAIN" to your compilation so this
    main function can compile.

*/

int main() {
    std::cout<<"testing linked list"<<std::endl;
    LinkedList<int> ll;

    std::cout<<ll.getCount()<<std::endl;
    try {
        ll.printForward();
        ll.printReverse();
        std::cout<<ll.getHead()<<std::endl;
        std::cout<<ll.getTail()<<std::endl;
    } catch (std::runtime_error& err) {
        std::cout<<"woopsies"<<std::endl;
    }

    ll.addHead(2);
    ll.addHead(1);
    ll.addTail(3);
    ll.addTail(4);

    ll.printForward();
    ll.printReverse();
    std::cout<<ll.getCount()<<std::endl;


    std::cout<<"removing"<<std::endl;

    std::cout<<ll.getHead()->data<<std::endl;
    std::cout<<ll.getTail()->data<<std::endl;

    ll.removeHead();

    std::cout<<ll.getHead()->data<<std::endl;
    std::cout<<ll.getTail()->data<<std::endl;
    std::cout<<ll.getCount()<<std::endl;


    LinkedList<int> newll(ll);
    newll=ll;
    LinkedList<int> movedll(std::move(ll));
    movedll=std::move(newll);

    std::cout<<movedll.getHead()->data<<std::endl;
    std::cout<<movedll.getTail()->data<<std::endl;
    std::cout<<movedll.getCount()<<std::endl;



    std::cout<<std::endl<<"testing LLQ"<<std::endl;
    LLQ<int> linkedListQueue;
    try {
        std::cout<<linkedListQueue.getSize()<<std::endl;
        std::cout<<linkedListQueue.peek()<<std::endl;
        std::cout<<linkedListQueue.dequeue()<<std::endl;
    }catch (std::runtime_error& error) {
        std::cout<<"didly darn"<<std::endl;
    }
    linkedListQueue.enqueue(1);
    linkedListQueue.enqueue(2);
    linkedListQueue.enqueue(3);
    linkedListQueue.enqueue(4);
    linkedListQueue.dequeue();

    std::cout<<linkedListQueue.getSize()<<std::endl;
    std::cout<<linkedListQueue.peek()<<std::endl;
    std::cout<<linkedListQueue.dequeue()<<std::endl;

    std::cout<<std::endl<<"testing LLS"<<std::endl;

    LLS<int> lls;

    try {
        std::cout<<lls.getSize()<<std::endl;
        std::cout<<lls.peek()<<std::endl;
        std::cout<<lls.pop()<<std::endl;
    } catch (std::runtime_error& err) {
        std::cout<<"dagnit"<<std::endl;
    }

    lls.push(1);
    lls.push(2);
    lls.push(3);
    lls.push(4);
    lls.push(5);
    lls.pop();

    std::cout<<lls.getSize()<<std::endl;
    std::cout<<lls.peek()<<std::endl;
    std::cout<<lls.pop()<<std::endl;

    LLS<int> newlls=std::move(lls);

    std::cout<<newlls.peek()<<std::endl;
    newlls.pop();
    std::cout<<newlls.pop()<<std::endl;

    std::cout<<std::endl<<"testing LLDQ"<<std::endl;

    LLDQ<int> lldq;

    try {
        std::cout<<lldq.getSize()<<std::endl;
        std::cout<<lldq.front()<<std::endl;
        std::cout<<lldq.back()<<std::endl;
        std::cout<<lldq.popFront()<<std::endl;
        std::cout<<lldq.popBack()<<std::endl;
    } catch (std::runtime_error& err) {
        std::cout<<"phooey"<<std::endl;
    }

    lldq.pushFront(1);
    lldq.pushBack(10);
    lldq.pushFront(2);
    lldq.pushBack(20);
    lldq.pushFront(3);
    lldq.pushBack(30);

    std::cout<<lldq.getSize()<<std::endl;
    std::cout<<lldq.front()<<std::endl;
    std::cout<<lldq.back()<<std::endl;
    std::cout<<lldq.popFront()<<std::endl;
    std::cout<<lldq.popBack()<<std::endl;


    std::cout<<std::endl<<"testing Circular buffer:"<<std::endl;
    CircularBuffer<int> cb;

    try {
        std::cout<<cb.getCapacity()<<std::endl;
        std::cout<<cb.getSize()<<std::endl;
        std::cout<<cb.front()<<std::endl;
        std::cout<<cb.back()<<std::endl;
        cb.removeFront();
        cb.removeBack();
    } catch (std::runtime_error& err) {
        std::cout<<"uhh ohh"<<std::endl;
    }

    cb.addFront(2);
    cb.addFront(1);
    cb.addBack(3);
    cb.addBack(4);

    cb.printData();
    std::cout<<cb.front()<<std::endl;
    std::cout<<cb.back()<<std::endl;
    cb.removeFront();
    cb.removeBack();
    cb.printData();

    cb.addBack(6);
    cb.removeBack();
    cb.addBack(6);
    cb.removeFront();
    cb.printData();
    cb.addBack(7);
    cb.printData();
    cb.removeFront();
    cb.printData();
    cb.addBack(8);
    cb.printData();

    cb.printData();

    std::cout<<"cap "<<cb.getCapacity()<<std::endl;
    std::cout<<cb.getSize()<<std::endl;
    std::cout<<cb.front()<<std::endl;
    std::cout<<cb.back()<<std::endl;


    std::cout<<std::endl<<"Testing ABS"<<std::endl;

    ABS<int> abs;

    abs.push(1);
    abs.push(2);
    abs.push(3);
    abs.push(4);
    abs.push(5);
    abs.push(6);
    abs.push(7);

    std::cout<<abs.getSize()<<std::endl;
    std::cout<<abs.peek()<<std::endl;
    std::cout<<abs.getMaxCapacity()<<std::endl;

    std::cout<<"removing"<<std::endl;

    std::cout<<abs.pop()<<std::endl;
    std::cout<<abs.pop()<<std::endl;
    std::cout<<abs.pop()<<std::endl;
    std::cout<<abs.pop()<<std::endl;
    std::cout<<abs.pop()<<std::endl;
    std::cout<<abs.pop()<<std::endl;
    std::cout<<abs.pop()<<std::endl;






    return 0;
}


#endif