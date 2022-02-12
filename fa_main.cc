/**
 * @file fa_main.cc
 * 
 * @brief Uses the DFA and NFA classes in order to simulate the finite automaton given by the user.
 *
 *        This file contains the usage of the DFA and NFA classes to be able to simulate the finite 
 *        automaton that the user gives. The data provided by the user has to be in a specific order
 *        so that the classes can read it and create the transition tables. At the end this program
 *        will print the results after simulating the given finite automaton.
 *
 * @author: David Petrovski
 * Contact: petrovskidavid1@gmail.com
 */

#include "nfa.h"
#include "dfa.h"

/**
 * @brief Creates the finite automaton provided by the user, prints the table and results after
 *        simulating the finite automaton.
 *
 * @return 0 Upon successfull execution.
 */
int main(){
    
    char type_of_fa; ///< Stores the type of finite automaton that needs to be creates.

    // Reads what type the finite automaton is.
    cin >> type_of_fa;
    
    if(type_of_fa == 'D'){          // If the type is 'D' it creates a DFA.
        
        DFA dfa_example;
        dfa_example.create_fa();
        dfa_example.get_words();
        dfa_example.print_transition_table();
        dfa_example.simulate();
        
    } else if (type_of_fa == 'N'){  // If the type is 'N' it creates a NFA.

        NFA nfa_example;
        nfa_example.create_fa();
        nfa_example.get_words();
        nfa_example.print_transition_table();
        nfa_example.simulate();
    }

    return 0;
}
