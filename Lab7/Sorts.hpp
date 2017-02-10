/**
*	@file : Sorts.hpp
*	@author : Luke Weaver
*	@date : 11-03-2015
*	Purpose: to sort arrays
*/
using namespace std;
//done
template <typename T> 
void Sorts<T>::bubbleSort(T arr[], int size)
{
	T big;
	T small;
	while(Sorts<T>::isSorted(arr, size)!=true)
	{
		for(int i = 1,counter=0; i<size; i++,counter++)
		{
			small=arr[counter];
			big=arr[i];
			if(arr[counter]>=arr[i])
			{
				small= arr[i];
				big = arr[counter];
			} 
			arr[counter] = small;
			arr[i] = big; 
		}
	}	
	assert( Sorts<T>::isSorted(arr, size));	
}

template <typename T>
void Sorts<T>::bogoSort(T arr[], int size)
{
   	default_random_engine generator(time(nullptr)); //generator
    	uniform_int_distribution<int> distribution(0, size); //sets bounds
	while(Sorts<T>::isSorted(arr, size)!=true)
	{
		Sorts<T>::shuffle(arr,size, generator);
	}
	assert( Sorts<T>::isSorted(arr, size) );	
}

template <typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{
	int temp=0;
	int temp2=0;
	for(int i = 1; i< size; i++)
	{
		for(int j=i,k=i-1; j>0; j--,k--)
		{
			temp=arr[k];
			temp2=arr[j];
			if(arr[j]<arr[k])
			{
				temp = arr[j];
				temp2 = arr[k];
			}
			arr[j]=temp2;
			arr[k]=temp;
		}
	}
	assert( Sorts<T>::isSorted(arr, size) );	
}

template <typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{
	int min=0;
	int temp=0;
	for (int i=0; i < size-1; i++)
	{
		min=i;
 		for (int j=i+1; j < size; j++)
		{
			if(arr[j]<arr[min])
				{
					min = j;
				}
		}
		if(min!=i)
		{
			temp = arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
		}
	}
	assert( Sorts<T>::isSorted(arr, size) );
}

//done
template <typename T>
bool Sorts<T>::isSorted(T arr[], int size)
{
	if(size==1)
		return true;
	else
	{
		for(int i=0,j=1; i< size-1; i++,j++)
		{
			if(arr[i] > arr[j])
			{
				return false;
			}
		}
	return true;
	}
}

template <typename T>
void Sorts<T>::shuffle(T arr[], int size, std::default_random_engine& generator)
{
	int x;
	int temp;
    	uniform_int_distribution<int> distribution(0, size-1); //sets bounds
	for(int i = 0; i < size; i++)
	{
		x= distribution(generator);
		temp = arr[i];
		arr[i]=arr[x];
		arr[x] = temp;
	}
}

//done
template <typename T>
int* Sorts<T>::createTestArray(int size, int min, int max)
{
	T* array  = new T[size];
   	default_random_engine generator(time(nullptr)); //generator
    	uniform_int_distribution<int> distribution(min, max); //sets bounds
	for(int i = 0; i < size; i++)
	{
		array[i] = distribution(generator);
	}
	return array;
}

//done
template <typename T>
double Sorts<T>::sortTimer(std::function<void(T[],int)> sort, T arr[], int size)
{
	std::chrono::system_clock::time_point start;
	sort(arr,size);
	std::chrono::system_clock::time_point end;
	std::chrono::duration<double> elapsed;
	start = std::chrono::system_clock::now();
   	end = std::chrono::system_clock::now();
 	std::chrono::duration<double> elapsed_seconds = (end-start);
	return elapsed_seconds.count();
}

template <typename T>
void Sorts<T>::quickSort(T arr[], int size)
{
	quickSortRec(arr,0,size-1,false);
}

template <typename T>
void Sorts<T>::quickSortWithMedian(T arr[], int size)
{
	quickSortRec(arr,0,size-1,true);
}

template <typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median)
{
	if(median && ((last)<2))
	{
		selectionSort(arr,(last+1));
		return;	
	}
	if(first<last)
	{
		int pivot = partition(arr,first,last,median);
		quickSortRec(arr, first, (pivot-1), median);
		quickSortRec(arr, (pivot+1),last,median);
		return;
	}
}

template<typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median){
	int lHalf = last;
	int fHalf=first;
	int rHalf = (lHalf-1);
	if(median==true)
	{
		setMedianPivot(arr, first, last);
	}
	bool done = true;
	while(done)
	{
		while((arr[fHalf]<arr[lHalf])&&(fHalf<(last+1)))
		{
			fHalf++;
		}
		while((arr[rHalf]>= arr[lHalf])&&(rHalf>0))
		{
			rHalf--;
		}
		if(fHalf<rHalf)
		{
			T temp = arr[fHalf];
			arr[fHalf] = arr[rHalf];
			arr[rHalf]= temp;
		}
		else
		{
			T temp = arr[fHalf];
			arr[fHalf] = arr[lHalf];
			arr[lHalf]= temp;
			done = false;
		}
	}
	return fHalf;
}

template<typename T>
void Sorts<T>::merge(T* a1, T* a2, int size1, int size2)
	{
	if(size1+size2 <= 1)
	{
		return;
	}
	else
	{
		T* temp = new T[size1+size2];
		int x=0;
		int y=0;
		int temp2 = 0;
		while(x<size1 && y<size2)
		{
			if(*(a1+x)<*(a2+y))
			{
				temp[temp2] = *(a1 +x);
				x++;
			}
			else
			{
				temp[temp2] = *(a2+y);
				y++;
			}
			temp2++;
		}	
		while(x<=size1-1)
		{
			temp[temp2] = *(a1+x);
			x++;
			temp2++;
		}
		while(y<=size2-1)
		{
			temp[temp2] = *(a2+y);
			y++;
			temp2++;
		}
		for(int i = 0; i<(size1+size2); i++)
		{
			a1[i] = temp[i];
		}
		delete [] temp;
		return;
	}
}

template<typename T>
void Sorts<T>::mergeSort(T arr[], int size)
{
	if(size<=1)
	{
		return;
	}
	else
	{
		int firstHalf = (size/2);
		int lastHalf = (size-firstHalf);
		T* left = arr;
		T* right = (arr+firstHalf);
		mergeSort(left, firstHalf);
		mergeSort(right, lastHalf);
		merge(left, right, firstHalf, lastHalf);
		assert(Sorts<T>::isSorted(arr, size));
	}
		return;
}

template <typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last)
{
	int mid = (last+1)/2;
	T temp [] = {arr[first], arr[mid], arr[last]};
	selectionSort(temp,3);
	if(arr[first]==temp[1])
	{
		T temp = arr[mid];
		arr[mid] = arr[last];
		arr[last]= temp;
		return;
	}
	else if(arr[mid] == temp[1])
	{
		T temp = arr[mid];
		arr[mid] = arr[last];
		arr[last]= temp;
		return;
	}
}
