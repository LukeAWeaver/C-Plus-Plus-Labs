Lab9: main.o Position.o MazeWalker.o MazeReader.o MazeCreationException.o Test.o
	g++ -std=c++11 -g -Wall main.o MazeWalker.o MazeReader.o Position.o MazeCreationException.o Test.o -o Lab9
main.o: main.cpp Test.h MazeReader.cpp
	g++ -std=c++11 -g -Wall -c main.cpp
Position.o: Position.cpp Position.h
	g++ -std=c++11 -g -Wall -c Position.cpp
MazeCreationException.o: MazeCreationException.cpp MazeCreationException.h
	g++ -std=c++11 -g -Wall -c MazeCreationException.cpp
MazeReader.o:MazeReader.h MazeReader.cpp MazeCreationException.h Position.h
	g++ -std=c++11 -g -Wall -c MazeReader.cpp
MazeWalker.o:MazeWalker.h MazeWalker.cpp Position.h
	g++ -std=c++11 -g -Wall -c MazeWalker.cpp
Test.o: Test.h Test.cpp
	g++ -std=c++11 -g -Wall -c Test.cpp
clean: 
	rm *.o Lab9
	echo clean done
