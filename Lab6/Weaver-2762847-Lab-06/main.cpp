#include "Sorts.h"
#include "Test.h"
#include <iostream>
#include <string>

using namespace std;

void printMenu()
{
	cout << "\n\nSelect a sort:\n";
	cout << "1) Bubble Sort\n";
	cout << "2) Insertion Sort\n";
	cout << "3) Selection Sort\n";
	cout << "4) Bogo Sort (use only with very small arrays!)\n";
	cout << "5) run Tests \n";
	cout << "Enter choice: ";
}
int main()
{
	int size=0;
	int upperBound=0;
	int lowerBound=0;
	int choice=0;
	double time=0;
	char finalchoice='n';
	int *array;
	char printarray2='n';
	char printarray='n';
	Test tester(std::cout);
	do
	{
		printMenu();
		cin >> choice;
		if(choice != 5)
		{
			cout << "Input a size for the random array: " << endl;
			cin >> size; 
			cout << "Input a lower bound on the range of random numbers: " << endl;
			cin >> lowerBound;
			cout << "Input an upper bound on the range of random numbers: " << endl;
			cin >> upperBound;
			array = Sorts<int>:: createTestArray(size, lowerBound, upperBound);
			cout << "\nDo you want to print the unsorted array? (y/n): " << endl;
			cin >> printarray;
		}
		if(printarray=='y')
		{
			cout << "Here is your unsorted array: " << endl;
			cout << "[";
			for (int i=0; i < size-1; i++)
			{
				cout << array[i] << ",";
			}
			cout <<array[size-1];
			cout << "]" << endl;
		}
		if(choice==1)
		{
			cout << " Sorting with bubbleSort..." << endl;	
			cout << " do you want to print the sorted array? (y/n): " << endl;
			cin >> printarray2;
			time = Sorts<int>::sortTimer(Sorts<int>::bubbleSort, array, size);
			if(printarray2=='y')		
			{
				cout << "Here is your sorted array: " << endl;
				cout << "[";
				for (int i=0; i < size-1; i++)
				{
					cout << array[i] << ",";
				}
				cout <<array[size-1];
				cout << "]" << endl;
				cout << size << " numbers were sorted in " << time << " seconds." << endl;
			}
			delete [] array;
			array = nullptr;
		}	
		else if(choice==2)
		{
			cout << " Sorting with InsertionSort..." << endl;	
			cout << " do you want to print the sorted array? (y/n): " << endl;
			cin >> printarray2;
			time = Sorts<int>::sortTimer(Sorts<int>::insertionSort, array, size);
			if(printarray2=='y')		
			{
				cout << "Here is your sorted array: " << endl;
				cout << "[";
				for (int i=0; i < size-1; i++)
				{
					cout << array[i] << ",";
				}
				cout <<array[size-1];
				cout << "]" << endl;
				cout << size << " numbers were sorted in " << time << " seconds." << endl;
			}
			delete [] array;
			array = nullptr;
		}
		else if(choice==3)
		{
			cout << " Sorting with SelectionSort..." << endl;	
			cout << " do you want to print the sorted array? (y/n): " << endl;
			cin >> printarray2;
			time = Sorts<int>::sortTimer(Sorts<int>::selectionSort, array, size);
			if(printarray2=='y')		
			{
				cout << "Here is your sorted array: " << endl;
				cout << "[";
				for (int i=0; i < size-1; i++)
				{
					cout << array[i] << ",";
				}	
				cout <<array[size-1];
				cout << "]" << endl;
				cout << size << " numbers were sorted in " << time << " seconds." << endl;
			}
			delete [] array;
			array = nullptr;
		}
		else if(choice==4)
		{
			cout << " Sorting with bogoSort..." << endl;	
			cout << " do you want to print the sorted array? (y/n): " << endl;
			cin >> printarray2;
			time = Sorts<int>::sortTimer(Sorts<int>::bogoSort, array, size);
			if(printarray2=='y')		
			{
				cout << "Here is your sorted array: " << endl;
				cout << "[";
				for (int i=0; i < size-1; i++)
				{
					cout << array[i] << ",";
				}
				cout <<array[size-1];
				cout << "]" << endl;
				cout << size << " numbers were sorted in " << time << " seconds." << endl;
			}
			delete [] array;
			array = nullptr;
		}	
		else if(choice==5)
		{
			tester.runTests();
		}
		cout << "Do you want to quit? (y/n): " << endl;
		cin >> finalchoice;
		printarray='n';
		printarray2='n';
	}
	while(finalchoice=='n');
	array = nullptr;
}


// to call a static don't do object.method or object -> method. instead do classname::method
