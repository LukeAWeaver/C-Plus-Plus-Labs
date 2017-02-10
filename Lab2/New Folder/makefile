Lab2: main.o Test.o LinkedList.o Node.o
	g++ -std=c++11 -g -Wall main.o Test.o Node.o LinkedList.o -o Lab2

main.o: main.cpp LinkedList.o
	g++ -std=c++11 -g -Wall -c main.cpp

Test.o: Test.cpp Test.h
	g++ -std=c++11 -g -Wall -c Test.cpp

LinkedList.o: LinkedList.cpp LinkedList.h Node.h Test.h
	g++ -std=c++11 -g -Wall -c LinkedList.cpp

Node.o: Node.cpp Node.h
	g++ -std=c++11 -g -Wall -c Node.cpp	

clean: 
	rm *.o Lab2
	echo clean done
