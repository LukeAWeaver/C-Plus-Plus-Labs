Lab7: main.o NumberFileDriver.o NumberFileGenerator.o SortDriver.o Test.o
	g++ -std=c++11 -g -Wall main.o NumberFileDriver.o SortDriver.o NumberFileGenerator.o Test.o -o Lab7

main.o: main.cpp NumberFileGenerator.h SortDriver.h Test.h
	g++ -std=c++11 -g -Wall -c main.cpp

Test.o: Test.cpp Test.h
	g++ -std=c++11 -g -Wall -c Test.cpp

SortDriver.o: SortDriver.cpp SortDriver.h
	g++ -std=c++11 -g -Wall -c SortDriver.cpp

NumberFileGenerator.o: NumberFileGenerator.cpp NumberFileGenerator.h
	g++ -std=c++11 -g -Wall -c NumberFileGenerator.cpp

NumberFileDriver.o: NumberFileDriver.cpp NumberFileDriver.h NumberFileGenerator.h
	g++ -std=c++11 -g -Wall -c NumberFileDriver.cpp
clean: 
	rm *.o Lab7
	echo clean done
