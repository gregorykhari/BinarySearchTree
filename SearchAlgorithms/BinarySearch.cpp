#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

int BinarySearch(int * array, int array_size, int search_key)
{
	int first = 0; 
	int last = array_size - 1;

	while(first <= last)
	{	
		//find middle of search area
		int middle = first + (last-first)/2;
		
		//if key is at middle of current search area return location
		if(array[middle] == search_key)
			return middle;
		
		//decrease search area to lower half of current array
		if(array[middle] > search_key)
			last = middle - 1;
	
		//decrease search area to upper half of current array
		if(array[middle] < search_key)
			first = middle + 1;
	}
	
	//search key not found in array
	return -1;
}

void BubbleSort(int * array, int array_size)
{
	for(int i = 0; i < array_size; i++)
	{
		for(int j = 0; j < array_size - i - 1;j++)
		{
			if(array[j] > array[j+1])
			{
				int tempVal = array[j+1];
				array[j+1] = array[j];
				array[j] = tempVal;				
			}
		}
	}

}

int main()
{
	int array_size;
	int search_key;
	int found;
	
	//seed random generator
	srand(time(NULL));
	
	std::cout << "Enter size of array: ";
	std::cin >> array_size;	

	int * array = new int[array_size];
	
	//initialize array with random values between 1 and 100
	for(int i = 0; i < array_size; i++)
	{
		array[i] = rand() % 100 + 1;	
	}

	//run bubble sort on array
	BubbleSort(array,array_size);

	//print sorted array
	std::cout << "ARRAY: \n" << std::endl;
	std::cout << " | ";	
	for(int i = 0; i < array_size; i++)
	{
		std::cout << array[i] << " | ";
	}
	std::cout << "\n" << std::endl;

	std::cout << "Enter value to search for: ";
	std::cin >> search_key;
	
	//run binary search on array using search key
	found = BinarySearch(array, array_size, search_key);
	
	//if found is -1 value not in array
	if(found != -1)
		std::cout << "The value " << search_key << " was found at position " << found << " in the array" << std::endl;
	else 
		std::cout << "The value " << search_key << " does not exist within the array" << std::endl;

	return 0;	
}

