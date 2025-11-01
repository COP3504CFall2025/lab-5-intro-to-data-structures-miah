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
    LLQ<int> linkedListQueue;
    linkedListQueue.dequeue();
    linkedListQueue.enqueue(5);
    linkedListQueue.enqueue(5);
    linkedListQueue.enqueue(5);
    linkedListQueue.enqueue(5);

    return 0;
}


#endif