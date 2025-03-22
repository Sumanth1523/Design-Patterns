    
    Desired design features
    =======================

    An application that successfully implements states, behaviors, and state transitions should have the following design features:

        DF 1 -> It is always clear at runtime what is the application’s current state.

        DF 2 -> The code for each state, including its behaviors and transitions, should be well encapsulated.

        DF 3 -> The code for each state should handle all the actions, whether reasonable or not for that state.

        DF 4 -> It should be possible to add, remove, or modify states with minimal code changes.

        DF 5 -> There should be minimal dependencies among the states other than the transitions.
    
    
    
    States of TicketMachine
    =======================
    
        READY        --> The machine is ready to accept a customer’s credit card.

        VALIDATING   --> The machine is validating a customer’s credit card.

        TICKET_SOLD  --> The machine has sold a ticket to a customer.

        SOLD_OUT     --> The game is sold out, and the machine cannot sell any more tickets.


    The member variables whose values determine the current state of the machine are
    ================================================================================

        count         --> The number of tickets left in the machine (integer)

        car           --> inserted—Whether or not a customer’s credit card is inserted (true or false)

        card_validity --> The validity of the credit card (YES, NO, or UNKNOWN)


    State Diagram:
    =============

    
Output Interaction:
==================

    Case 1: SuccessFul Transaction
    ------------------------------

        1: insert card, 2: check card validity
        3: take ticket, 4: remove card, 0: quit
        [READY 3 false unknown] Command? 1
        Validating your credit card. 

        1: insert card, 2: check card validity
        3: take ticket, 4: remove card, 0: quit
        [VALIDATING 3 true unknown] Command? 2
        Your credit card is validated. Take your ticket.

        1: insert card, 2: check card validity
        3: take ticket, 4: remove card, 0: quit
        [TICKET_SOLD 3 true yes] Command? 3
        Remove your credit card. Enjoy the game!

        1: insert card, 2: check card validity
        3: take ticket, 4: remove card, 0: quit
        [READY 2 true yes] Command? 4
        You’ve removed your credit card.

        1: insert card, 2: check card validity
        3: take ticket, 4: remove card, 0: quit
        [READY 2 false unknown] Command? 0
        Done!


    Case 2 : We attempt to purchase a ticket when the machine is sold out. The machine remains in the SOLD_OUT state:
    -----------------------------------------------------------------------------------------------------------------

        1: insert card, 2: check card validity
        3: take ticket, 4: remove card, 0: quit
        [SOLD_OUT 0 false unknown] Command? 1
        *** Game sold out. ***
        Remove your credit card.

        1: insert card, 2: check card validity
        3: take ticket, 4: remove card, 0: quit
        [SOLD_OUT 0 true unknown] Command? 4
        You’ve removed your credit card.


    Case 3: We change our mind and remove a card while its validity is being checked. The machine returns to the READY state:
    -------------------------------------------------------------------------------------------------------------------------

        1: insert card, 2: check card validity
        3: take ticket, 4: remove card, 0: quit
        [READY 3 false unknown] Command? 1
        Validating your credit card.

        1: insert card, 2: check card validity
        3: take ticket, 4: remove card, 0: quit
        [VALIDATING 3 true unknown] Command? 4
        You removed your credit card before it was validated. No sale.

        1: insert card, 2: check card validity
        3: take ticket, 4: remove card, 0: quit
        [READY 3 false unknown] Command?

    Case 4: The machine fails to validate the credit card and rejects it. After we remove the credit card, the machine returns to the READY state:
    ----------------------------------------------------------------------------------------------------------------------------------------------

        1: insert card, 2: check card validity
        3: take ticket, 4: remove card, 0: quit
        [READY 2 false unknown] Command? 1
        Validating your credit card.

        1: insert card, 2: check card validity
        3: take ticket, 4: remove card, 0: quit
        [VALIDATING 2 true unknown] Command? 2
        *** Credit card rejected. *** 
        Remove your card.

        1: insert card, 2: check card validity
        3: take ticket, 4: remove card, 0: quit
        [READY 2 true no] Command? 4
        You’ve removed your credit card.

    Case 5: We try to take a ticket while the machine is still checking our credit card’s validity. `This is an unreasonable action`, and the machine remains in its current VALIDATING state:
    ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

        1: insert card, 2: check card validity
        3: take ticket, 4: remove card, 0: quit
        [READY 3 false unknown] Command? 1
        Validating your credit card.

        1: insert card, 2: check card validity
        3: take ticket, 4: remove card, 0: quit
        [VALIDATING 3 true unknown] Command? 3
        Still checking your credit card’s validity.

        1: insert card, 2: check card validity
        3: take ticket, 4: remove card, 0: quit
        [VALIDATING 3 true unknown] Command?















































Issues in the design:
=====================


        Multiple responsibilities ==> Class TicketMachine not only has to keep track of the machine’s state but is also responsible for all the actions that occur in all the states. All the application logic is concentrated in this one class.

        Poor encapsulation        ==> The states and their behaviors are not well encapsulated.

        Inflexible code           ==> If we need to modify, add, or remove ticket machine states and their actions, we will need to change the TicketMachine class.