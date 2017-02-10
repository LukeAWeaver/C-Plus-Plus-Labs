
using namespace std;
//done
template <typename T> 
void Sorts<T>::bubbleSort(T arr[], int size)
{
	T defaultSmaller=0;
	T defaultLarger=0;
	while(Sorts<T>::isSorted(arr, size)!=true)
	{
		for(int i = 1,counter=0; i<size; i++,counter++)
		{
			defaultSmaller=arr[counter];
			defaultLarger=arr[i];
			if(arr[counter]>=arr[i])
			{
				defaultSmaller= arr[i];
				defaultLarger = arr[counter];
			} 
			arr[counter] = defaultSmaller;
			arr[i] = defaultLarger; 
		}
	}	
	assert( Sorts<T>::isSorted(arr, size) );	
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


template <typename T>


//done
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

//don't add stati to hpp file



/*
  static int  r[10];

  // set the seed
  srand( (unsigned)time( NULL ) );
  for (int i = 0; i < 10; ++i)
  {
    r[i] = rand();
    cout << r[i] << endl;
  }

  return r;

*/





//when passing in functions type like this: Sorts<T>:: sortTimer(Sorts<T>::InsertionSort, arr,size);

//dont put static in .hpp or .cpp file. just header
