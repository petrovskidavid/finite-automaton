# Finite-Automaton

### Description

This program was created to simulate Finite Automaton, specifically [Deterministic](https://en.wikipedia.org/wiki/Deterministic_finite_automaton) and [Nondeterministic Finite Automaton](https://en.wikipedia.org/wiki/Nondeterministic_finite_automaton). The program accepts as input the type of Finite Automaton, a description of it over the alphabet Σ = {a, b}, and words that will be tested by the Finite Automaton.
Finally, it prints the transition table of the Finite Automaton andit reports whether each was was accepted or rejected by machine.

### Instructions
- Clone this repository.
- Run `make` command in the directory where this repo is cloned.
- Run executable with one of the provided input files or your custom created input file.
- To remove executable and object files run `make clean` command in the directory where this repo is cloned.

### Input

The program reads the input from **stdin**.

The following is the format that the input file must have for a NFA:
1. The first line will must have _N_ to specify that a NFA is to be created.
2. The second line will have two integers, _nstates_ and _naccepting_. _nstates_ is the number of states in the machine and _naccepting_ is the number of accepting states.
3. There will then be _naccepting_ lines each with a single integer that specifies each of the accepting states. (This can be 0, which means no accepting states are provided.)
4. There will then be _nstates_ lines each for a state that is in the NFA. Since this is an NFA each line will have information on the sets of states for each transition of each state. So for each state the line will start with the number of outgoing transitions (_ntranistions_) for the first symbol of Σ. Followed by the states to transition to (There will be _ntransitions_ number of them). Immediately after these, there will be another integer that will represent the number of transitions for the second symbol in Σ. Followed by the states to transition to.
5. Then there will be a number _nwords_ to specify how many words will be tested by the NFA. Followed by the each one of those words on a new line.

Example:
```
N
5 2
2
4 
2 0 1 2 0 3 
1 2 0 
1 2 1 2 
0 1 4 
1 4 1 4
5
a
ab
aba
abaa
abaab
```

The following is the format that the input file must have for a DFA:
1. The first line will must have _D_ to specify that a DFA is to be created.
2. The second line will have two integers, _nstates_ and _naccepting_. _nstates_ is the number of states in the machine and _naccepting_ is the number of accepting states.
3. There will then be _naccepting_ lines each with a single integer that specifies each of the accepting states. (This can be 0, which means no accepting states are provided.)
4. There will then be _nstates_ lines each for a state that is in the DFA. Since this is a DFA each line will only have two integers. The first integer represents the transition for the first symbol of Σ. Followed by the transition for the second symbol of Σ.
5. Then there will be a number _nwords_ to specify how many words will be tested by the DFA. Followed by the each one of those words on a new line.

Example:
```
D
2 1
0
0 1
1 1
6
a
b
ab
ba
aa
aaa
```

_Note: It is assumed that **0 <= naccepting <= nstates**,**nwords > 0**, **0 < nstates <= 100**, and that state 0 is always the start state._

### Output

The output of this program is printed onto **stdout**.

It first prints the transition table with an asterisk infront of every state that is an accepting state. And then it prints the results for each word after running the simulation of the Finite Automaton.

Example using the input for the DFA above:

<img src="https://i.imgur.com/LyV6w8L.png" width=600 height=300>
