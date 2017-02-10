Lab3: main.o Test.o 
	g++ -std=c++11 -g -Wall main.o Test.o -o Lab3

main.o: main.cpp Test.h
	g++ -std=c++11 -g -Wall -c main.cpp

Test.o: Test.cpp Test.h
	g++ -std=c++11 -g -Wall -c Test.cpp


clean: 
	rm *.o Lab3
	echo clean done
