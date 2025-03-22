#ifndef TICKETMACHINE_H
#define TICKETMACHINE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Enums.h"

class TicketMachine
{
public:
    TicketMachine(const int c)
        : count(c), card_inserted(false),
          card_validity(Validity::UNKNOWN), state(State::READY)
    {
        srand(time(NULL));
    }

    int      get_count()    const { return count; }
    bool     get_inserted() const { return card_inserted; }
    Validity get_validity() const { return card_validity; }
    State    get()    const { return state; }

    void run();

    void insert_credit_card();  // 1                            ②
    void check_validity();      // 2                            ②
    void take_ticket();         // 3                            ②
    void remove_credit_card();  // 4                            ②

private:
    int      count;
    bool     card_inserted;
    Validity card_validity;
    State    state;
};

#endif