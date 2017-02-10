#ifndef SORTS_H
#define SORTS_H

#include <random>
#include <ctime>
#include <chrono>
#include <cassert>
#include <functional>
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Sorts
{
	public:
	/**
	*  @pre an array and an int.
	*  @post sorts using bubble algorithm
	*  @return none
	*/
	static void bubbleSort(T arr[], int size);
	/**
	*  @pre an array and an int.
	*  @post sorts using bogo algorithm
	*  @return none
	*/
	static void bogoSort(T arr[], int size);
	/**
	*  @pre an array and an int.
	*  @post sorts using insertionSort algorithm
	*  @return none
	*/
	static void insertionSort(T arr[], int size);
	/**
	*  @pre an array and an int.
	*  @post sorts using selectionSort algorithm
	*  @return none
	*/
	static void selectionSort(T arr[], int size);
	/**
	*  @pre an array and an int.
	*  @post checks if array is sorted
	*  @return true is arr is in ascending order, false otherwise
	*/
	static bool isSorted(T arr[], int size);
	/**
	*  @pre an array and an int.
	*  @post For each index in the array, swap it the value at another random index
	*  @return none
	*/
	static void shuffle(T arr[], int size, std::default_random_engine& generator);
	/**
	*  @pre an array a max and a min.
	*  @post creates a new array of the specified size and contains random values that fall within the range specified by min and max (inclusive)
	*  @return an int pointer
	*/
	static int* createTestArray(int size, int min, int max);
	/**
	*  @pre an array a max and a min.
	*  @post arr is a vaild array of T of size elements, and the < operator is overloaded for T. 
	*  @return returns the time, in seconds, the sort required to sort arr.
	*/
	static double sortTimer(std::function<void(T[],int)> sort, T arr[], int size);




};
#include "Sorts.hpp"


#endif
