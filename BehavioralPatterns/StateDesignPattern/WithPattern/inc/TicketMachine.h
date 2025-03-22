#ifndef TICKETMACHINE_H
#define TICKETMACHINE_H

#include <time.h>

#include "Enums.h"
#include "State.h"
#include "StatesBlock.h"

class TicketMachine
{
public:
    TicketMachine(const int c)
        : count(c), card_inserted(false),
          card_validity(Validity::UNKNOWN)
    {
        srand(time(NULL));

        StatesBlock *block = new StatesBlock(count, card_inserted,
                                             card_validity);
        state = block->get_initial_state();
    }

    void run()
    {
        int command;

        do
        {
            cout << endl;
            cout << "1: insert card, 2: check card validity" << endl;
            cout << "3: take ticket, 4: remove card, 0: quit" << endl;
            cout << "[" << state->get_id() << " " << count
                 << " " << boolalpha << card_inserted
                 << " " << card_validity << "] ";
            cout << "Command? ";

            cin >> command;

            switch (command)
            {
            case 1:
                insert_credit_card();
                break;
            case 2:
                check_validity();
                break;
            case 3:
                take_ticket();
                break;
            case 4:
                remove_credit_card();
                break;

            case 0:
                cout << endl
                     << "Done!" << endl;
                break;

            default:
                cout << "*** Invalid command. ***" << endl;
            }
        } while (command != 0);
    }

    void insert_credit_card()
    {
        state = state->insert_credit_card();
    }

    void check_validity()
    {
        state = state->check_validity();
    }

    void take_ticket()
    {
        state = state->take_ticket();
    }

    void remove_credit_card()
    {
        state = state->remove_credit_card();
    }

private:
    int count;
    bool card_inserted;
    Validity card_validity;

    State *state;
};

#endif