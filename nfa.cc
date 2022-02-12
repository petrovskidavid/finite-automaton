/**
 * @file nfa.cc
 * 
 * @brief Containts member function definitions for the NFA class.
 *
 * @author: David Petrovski
 * Contact: petrovskidavid1@gmail.com
 */

#include "nfa.h"


NFA::NFA(){

    transition_table.resize(MAX_NUM_STATES, vector<vector<int>>(2)); 
}


NFA::~NFA(){
    
    // Clears the data stored in the vectors.
    transition_table.clear();
    words.clear();
}


void NFA::create_fa(){

    // Reads the first two integers from stdin. 
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
    for(int i = 0; i < num_states; i++){
        
        // Reads the number of transitions for a.
        cin >> num_transitions;

        for(int j = 0; j < num_transitions; j++){
            
            // Reads the a transitions.
            cin >> a;

            // Stores the transitions in the transition table.
            transition_table[i][0].push_back(a);
        }

        // Reads the number of transitions for b.
        cin >> num_transitions;

        for(int j = 0; j < num_transitions; j++){
            
            // Reads the b transitions.
            cin >> b;

            // Stores the transitions in the transition table.
            transition_table[i][1].push_back(b);
        }
    }
}


void NFA::get_words(){

    string new_word;
    
    // Reads the number of words that will be tested.
    cin >> num_words;

    // Goes through all the words and stores them in the words vector.
    for(int i = 0; i < num_words; i++){

        cin >> new_word;
        words.push_back(new_word);
    }

}


void NFA::print_transition_table() const{

    cout << "Table representation of the NFA:" << endl << endl;
    
    // Prints the first line of the table.
    cout << right << setw(5) << "|" << setw(2) << "a" << setw(2) << "b" << endl; 
    
    // Prints the second line of the table.
    cout << "----+----" << endl;

    // Prints the states and the transitions for each state.
    for(int i = 0; i < num_states; i++){

        // Checks if the state is an accpeting state.
        if(accepting_states[i]){

            // Print a '*' for the accepting state.
            cout << "*" << setw(2);

        } else {

            cout << setw(3);
        }
        
        cout << i << setw(2) << "|" << setw(2);
        
        // Prints all the transitions for a.
        cout << "{";
        for (long unsigned int j = 0; j < transition_table[i][0].size(); j++)
            cout << right << setw(2) << transition_table[i][0][j];

        cout << "}" << setw(2) << "{";
        
        // Prints all the transitions for b.
        for (long unsigned int j = 0; j < transition_table[i][1].size(); j++)
            cout << right << setw(2) << transition_table[i][1][j];

        cout << "}" << endl;
    }
}


void NFA::simulate() const{
    
    // Checks if the NFA has 0 accepting states.
    if(num_accepting == 0){
        
        // If so then none of the words are accepted.
        for (int i = 0; i < num_words; i++)
            cout << words[i] << " rejected" << endl;

    } else {

        string current_word; ///< The current word to be checked with the NFA.
        set<int> current_state; ///< A set for the states we are currently in.
        set<int> next_state; ///< A temporary set that holds the next states in the transition.
        bool accepted; ///< Holds true if the current word is accepted by the NFA, false otherwise.

        cout << endl << "Results after simulating the NFA for the provided words:" << endl << endl;
        
        // Loops through the list of words.
        for(int i = 0; i < num_words; i++){
            
            // Makes sure the current_state set is empty.
            current_state.clear();

            // Resets NFA state to 0, since NFA in our case always starts at state 0.
            current_state.insert(0); 

            // Grabs the current word from the words list.
            current_word = words[i];

            // Loops through each character in the word.
            for(size_t j = 0; j < current_word.length(); j++){

                // Resets the next_state set for the next word to be tested.
                next_state.clear();

                // Loops through the current states transitions depending if it's an 'a' or 'b' transition.
                for(auto it = current_state.begin(); it != current_state.end(); ++it){

                    switch(current_word[j]){

                        case 'a':
                            // Goes through the different transitions withing 'a' for the current state.
                            for(size_t t = 0; t < transition_table[*it][0].size(); t++)

                                // Inserts all the transitions of 'a' in the current state.
                                next_state.insert(transition_table[*it][0][t]); 

                            break;



                        case 'b': 
                            
                            // Goes through the different transitions withing 'b' for the current state.
                            for(size_t t = 0; t < transition_table[*it][1].size(); t++)
                                
                                // Inserts all the transitions of 'b' in the current state.
                                next_state.insert(transition_table[*it][1][t]);

                            break;
                    }
                }
                
                // Stores the data from the temporary next_state into the current_state set to continue with the rest of the characters of the word.
                current_state = next_state;
            }
            
            // Checks if the final state reached after reading the word is an accepting state.
            accepted = false;
            for(auto it = current_state.begin(); it != current_state.end(); ++it)
                if(accepting_states[*it])
                    accepted = true;
           
            // Prints the results for the current word.
            if (accepted)
                cout << current_word << " accepted";
            else
                cout << current_word << " rejected";

            cout << endl;
        }
    }
}
