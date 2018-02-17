
default: visible transition uppercase tape transitionfunc tapealphabet inputalphabet states finalstates turingmachine main

visible: visible.h visible.cpp
	g++ -g -Wall -c visible.cpp

transition: transition.h transition.cpp direction.h
	g++ -g -Wall -c transition.cpp

uppercase: upperCase.h upperCase.cpp
	g++ -g -Wall -c upperCase.cpp

tape: Tape.h Tape.cpp direction.h 
	g++ -g -Wall -c Tape.cpp

transitionfunc: transition_function.h transition_function.cpp transition.h transition.cpp direction.h
	g++ -g -Wall -c transition_function.cpp

tapealphabet: tape_alphabet.h tape_alphabet.cpp
	g++ -g -Wall -c tape_alphabet.cpp

inputalphabet: Input_alphabet.h Input_alphabet.cpp
	g++ -g -Wall -c Input_alphabet.cpp

states: State.h State.cpp
	g++ -g -Wall -c State.cpp

finalstates: final_state.h final_state.cpp
	g++ -g -Wall -c final_state.cpp

turingmachine: turing_machine.h turing_machine.cpp Tape.h Tape.cpp transition_function.h transition_function.cpp transition.h transition.cpp direction.h
	g++ -g -Wall -c turing_machine.cpp

main: main.cpp turing_machine.cpp visible transition uppercase tape transitionfunc tapealphabet inputalphabet states finalstates turingmachine
	g++ -g -Wall -c main.cpp
	g++ -g -Wall -o turingmachine main.o turing_machine.o Tape.o upperCase.o final_state.o State.o Input_alphabet.o tape_alphabet.o transition_function.o transition.o visible.o 
	rm -f visible.o
	rm -f transition.o
	rm -f upperCase.o
	rm -f Tape.o
	rm -f transition_function.o
	rm -f tape_alphabet.o
	rm -f Input_alphabet.o
	rm -f State.o
	rm -f final_state.o
	rm -f turing_machine.o
	rm -f main.o	
clean:
	rm -f turingmachine