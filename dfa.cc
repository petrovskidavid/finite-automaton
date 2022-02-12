/**
 * @file dfa.cc
 * 
 * @brief Containts member function definitions for the DFA class.
 *
 * @author: David Petrovski
 * Contact: petrovskidavid1@gmail.com
 */

#include "dfa.h"


DFA::DFA(){

    transition_table.resize(MAX_NUM_STATES, vector<int> (2));
}


DFA::~DFA(){
    
    // Clears the data stored in the vectors.
    transition_table.clear();
    words.clear();
}


void DFA::create_fa(){

    cin >> num_states;
    cin >> num_accepting;

    // Loops through accepting_states marking which state is accepting.
    int j; ///< The accepting states number to be used as index for the accepting_states array.
    for(int i = 0; i < num_accepting; i++){
        
        cin >> j;

        accepting_states[j] = true;
    }

    // Inserts transitions for each state inside transition_table.
    int a, b; ///< Holds the transition for the letters a and b.
    for (int i = 0; i < num_states; i++){
        
        // Reads the a and b transitions.
        cin >> a;
        cin >> b;
        
        // Stores the transitions into the transition table.
        transition_table[i][0] = a;
        transition_table[i][1] = b;
    }
}


void DFA::print_transition_table() const{
    
    cout << "Table representation of the DFA:" << endl << endl;

    // Prints the first line of the table.
    cout << right << setw(5) << "|" << setw(3) << "a" << setw(3) << "b" << endl; 
    
    // Prints the second line of the table.
    cout << "----+------" << endl;

    // Prints the states and the transitions for each state.
    for (int i = 0; i < num_states; i++){

        // Checks if the state is an accpeting state.
        if (accepting_states[i]){

            // Print a '*' for the accepting state.
            cout << "*" << setw(2);

        } else {

            cout << setw(3);
        }
        
        cout << i << setw(2) << "|" << setw(3) << transition_table[i][0] << setw(3) << transition_table[i][1] << endl;
    }
}


void DFA::simulate() const{

    // Checks if the DFA has 0 accepting states.
    if (num_accepting == 0){
        
        // If so then none of the words are accepted.
        for (int i = 0; i < num_words; i++)
            cout << words[i] << " rejected" << endl;

    } else {

        string current_word; ///< The current word to be checked with the DFA.
        int state; ///< The state that the DFA is currently in.

        cout << endl << "Results after simulating the DFA for the provided words:" << endl << endl;
        
        // Loops through the list of words.
        for (int i = 0; i < num_words; i++){
            
            // Resets DFA state to 0, since DFA in our case always starts at state 0.
            state = 0; 

            current_word = words[i];
  
            // Loops through each character in the word.
            for (size_t j = 0; j < current_word.length(); j++){

                // Checks what transition to do depending on the current character from the word.
                switch (current_word[j]){
                    
                    case 'a':
                        state = transition_table[state][0];
                        break;

                    case 'b':
                        state = transition_table[state][1];
                        break;
                }
            }
            
            // Checks if the final state reached after reading the word is an accepting state.
            if (accepting_states[state])
                cout << current_word << " accepted";
            else
                cout << current_word << " rejected";

            cout << endl;
        }
    }
}

