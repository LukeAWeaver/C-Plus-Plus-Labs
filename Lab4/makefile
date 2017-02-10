Lab4: main.o PreconditionViolationException.o Test.o
	g++ -std=c++11 -g -Wall main.o Test.o PreconditionViolationException.o -o Lab4

main.o: main.cpp Test.h PreconditionViolationException.h
	g++ -std=c++11 -g -Wall -c main.cpp

Test.o: Test.cpp Test.h PreconditionViolationException.h
	g++ -std=c++11 -g -Wall -c Test.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -std=c++11 -g -Wall -c PreconditionViolationException.cpp
clean: 
	rm *.o Lab4
	echo clean done
