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
    std::cout<<"testing LLQ"<<std::endl;
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




    return 0;
}


#endif