Lab5: main.o PreconditionViolationException.o FarmAnimal.o AnimalPen.o Cow.o Chicken.o CyberChicken.o
	g++ -std=c++11 -g -Wall main.o PreconditionViolationException.o  FarmAnimal.o AnimalPen.o Cow.o Chicken.o CyberChicken.o -o Lab5

main.o: main.cpp PreconditionViolationException.h AnimalPen.h FarmAnimal.h Cow.h Chicken.h CyberChicken.h
	g++ -std=c++11 -g -Wall -c main.cpp

AnimalPen.o: AnimalPen.h AnimalPen.cpp
	g++ -std=c++11 -g -Wall -c AnimalPen.cpp

FarmAnimal.o: FarmAnimal.h FarmAnimal.cpp
	g++ -std=c++11 -g -Wall -c FarmAnimal.cpp

Cow.o: Cow.cpp Cow.h FarmAnimal.h
	g++ -std=c++11 -g -Wall -c Cow.cpp

Chicken.o: Chicken.cpp Chicken.h FarmAnimal.h
	g++ -std=c++11 -g -Wall -c Chicken.cpp

CyberChicken.o: CyberChicken.cpp CyberChicken.h Chicken.h FarmAnimal.h
	g++ -std=c++11 -g -Wall -c CyberChicken.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -std=c++11 -g -Wall -c PreconditionViolationException.cpp
clean: 
	rm *.o Lab5
	echo clean done
