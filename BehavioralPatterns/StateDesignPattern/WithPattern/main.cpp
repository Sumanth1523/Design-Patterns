#include <iostream>
#include "inc/TicketMachine.h"

using namespace std;

int main()
{
    TicketMachine tktMachine(4);
    tktMachine.run();
    return 0;
}