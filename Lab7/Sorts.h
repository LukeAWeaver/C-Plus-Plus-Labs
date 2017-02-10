/**
*	@file : Sorts.H
*	@author : Luke Weaver
*	@date : 11-03-2015
*	Purpose: to declare variables for Sorts.cpp
*/
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
	/**
	*  @pre an array and an int.
	*  @post Calls quickSortRec with median flag set to true
	*  @return none
	*/
	static void quickSortWithMedian(T arr[], int size);
	/**
	*  @pre an array and an int.
	*  @post sorts arr using mergeSort algorithm
	*  @return none
	*/
	static void mergeSort(T arr[], int size);
	/**
	*  @pre an array and an int.
	*  @post Calls quickSort with median flag set to false
	*  @return none
	*/
	static void quickSort(T arr[], int size);
	private:
	/**
	*  @pre an array and an int.
	*  @post used by merge sort to two sorted combine arrays (which are actually two halved of a single array) into a single sorted array
	*  @return none
	*/
	static void merge(T* a1, T* a2, int size1, int size2);
	/**
	*  @pre an array and an int.
	*  @post sorts the array by partitioning the array, quick sorting every left of the pivot, and quick sorting everything right of the pivot
	*  @return none
	*/
	static void quickSortRec(T arr[], int first, int last, bool median);
	/**
	*  @pre an array and an int.
	*  @post puts the median value of the array in the last position
	*  @return none
	*/
	static void setMedianPivot(T arr[], int first, int last);
	/**
	*  @pre an array and an int.
	*  @post chooses a pivot based on the median flag, if median is true, use setMedianPivot, otherwise select the last element in the array
	*  @return none
	*/
	static int partition(T arr[], int first, int last, bool median);


};
#include "Sorts.hpp"


#endif
