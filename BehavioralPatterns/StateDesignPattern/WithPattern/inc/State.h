#ifndef STATE_H
#define STATE_H

#include <string>
#include "Enums.h"

using namespace std;

class StatesBlock;

class State
{
public:
    State(const string id, StatesBlock& states_block,               
          int& count, bool& card_inserted, Validity& card_validity) 
        : id(id), states(states_block),
          count(count), card_inserted(card_inserted),
          card_validity(card_validity) {}
    virtual ~State() {}

    friend class TicketMachine;

    string get_id()
    {
        return id;
    }

private:
    string id;

protected:
    StatesBlock& states;

    int&      count;                                                
    bool&     card_inserted;                                        
    Validity& card_validity;                                        

    virtual State *insert_credit_card() = 0;  // Action 1           ③
    virtual State *check_validity()     = 0;  // Action 2           ③
    virtual State *take_ticket()        = 0;  // Action 3           ③
    virtual State *remove_credit_card() = 0;  // Action 4           ③
};


class READY : public State
{
public:
    READY(StatesBlock& states, int& count,                   
          bool& card_inserted, Validity& card_validity)      
        : State("READY", states, count,
                card_inserted, card_validity) {}

private:
    State *insert_credit_card() override;  // Action 1
    State *check_validity()     override;  // Action 2
    State *take_ticket()        override;  // Action 3
    State *remove_credit_card() override;  // Action 4
};

class VALIDATING : public State
{
public:
    VALIDATING(StatesBlock& states, int& count,               
               bool& card_inserted, Validity& card_validity)  
        : State("VALIDATING", states, count,
                card_inserted, card_validity) {}

private:
    State *insert_credit_card() override;  // Action 1
    State *check_validity()     override;  // Action 2
    State *take_ticket()        override;  // Action 3
    State *remove_credit_card() override;  // Action 4
};

class TICKET_SOLD : public State
{
public:
    TICKET_SOLD(StatesBlock& states, int& count,              
                bool& card_inserted, Validity& card_validity) 
        : State("TICKET_SOLD", states, count,
                card_inserted, card_validity) {}

private:
    State *insert_credit_card() override;  // Action 1
    State *check_validity()     override;  // Action 2
    State *take_ticket()        override;  // Action 3
    State *remove_credit_card() override;  // Action 4
};

class SOLD_OUT : public State
{
public:
    SOLD_OUT(StatesBlock& states, int& count,                 
             bool& card_inserted, Validity& card_validity)    
        : State("SOLD_OUT", states, count,
                card_inserted, card_validity) {}

private:
    State *insert_credit_card() override;  // Action 1
    State *check_validity()     override;  // Action 2
    State *take_ticket()        override;  // Action 3
    State *remove_credit_card() override;  // Action 4
};


#endif