/**
 * @file dfa.h
 * 
 * @brief Header file for the DFA class.
 *
 * This file containts all the member functions and data members for the DFA class.
 * Including documentation on how they work and what they are used for. 
 *
 * @author: David Petrovski
 * Contact: petrovskidavid1@gmail.com
 */

#ifndef DFA_H
#define DFA_H

#include "nfa.h"


/**
 * @brief Implements a Deterministic Finite Automaton, and tests words to see if they
 *        are accepted by it or rejected.
 *
 * @note Deterived class from the NFA class.
 */
class DFA : public NFA{

public:

    /**
     * @brief Constructor.
     *        
     *        Resizes the transition_table vector to fit the states, and
     *        their transitions.
     */
    DFA();


    /**
     * @brief Destructor.
     */
    ~DFA();


    /**
     * @brief Reads the data from the user and uses it to fill out the transition 
     *        table for the DFA. 
     */
    void create_fa();

    /**
     * @brief Prints the transition table with a and b transitions as the columns,
     *        and the rows hold the states of the DFA, with information on which
     *        state to transition to depending on the type of transition.
     */
    void print_transition_table() const;
    
    /**
     * @brief Simulates the DFA using the words provided by the user.
     *
     *        Uses the words provided by the user to go through the transition table
     *        of the DFA. If the last character of the word ends up at an accepting
     *        state then the word is accepted by the DFA. Otherwise it is rejected.
     *
     * @note Prints results for each word that it simulates.
     */
    void simulate() const;


private:
    vector<vector<int>> transition_table; ///< 2D vector that will be used as a transition table for the simulation of the DFA.

};

#endif
