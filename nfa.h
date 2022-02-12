/**
 * @file nfa.h
 * 
 * @brief Header file for the NFA class.
 *
 * This file containts all the member functions and data members for the NFA class.
 * Including documentation on how they work and what they are used for. 
 *
 * @author: David Petrovski
 * Contact: petrovskidavid1@gmail.com
 */

#ifndef NFA_H
#define NFA_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>

using std::cin;
using std::cout;
using std::endl;
using std::setw;
using std::right;
using std::string;
using std::vector;
using std::set;

constexpr int MAX_NUM_STATES = 100; ///< Maximum number of states in a finite automaton.


/**
 * @brief Implements a Non-deterministic Finite Automaton, and tests words to see if they
 *        are accepted by it or rejected.
 *
 * @note Base class.
 */
class NFA{

public:

    /**
     * @brief Constructor.     
     *        Resizes the transition_table vector to fit the states, and
     *        their transitions.
     */
    NFA();


    /**
     * @brief Destructor.
     */
    ~NFA();


    /**
     * @brief Reads the data from the user and uses it to fill out the transition 
     *        table for the NFA. 
     */
    void create_fa();
    

    /**
     * @brief Reads the words that will be tested and stores them in the words vector.
     */
    void get_words();


    /**
     * @brief Prints the transition table with a and b transitions as the columns,
     *        and the rows hold the states of the NFA, with information on which
     *        sets of states to transition to depending on the type of transition.
     */
    void print_transition_table() const;


    /**
     * @brief Simulates the NFA using the words provided by the user.
     *
     *        Uses the words provided by the user to go through the transition table
     *        of the NFA. If the last character of the word ends up at an accepting
     *        state then the word is accepted by the NFA. Otherwise it is rejected.
     *
     * @note Prints results for each word that it simulates.
     */
    void simulate() const;


protected:
    int num_states = 0; ///< Number of states.
    int num_accepting = 0; ///< Number of accepting states.
    int num_words = 0; ///< Number of words to test with the DFA.
    bool accepting_states[MAX_NUM_STATES] = {false}; ///< Array where all the accepting states are set to true.
    vector<string> words; ///< Vector where the words to test will be stored.


private:
    vector<vector<vector<int>>> transition_table; ///< Transition table for the NFA, implemented as a 3D vector.
    int num_transitions; ///< Holds the number of transitions for a or b.

};

#endif
