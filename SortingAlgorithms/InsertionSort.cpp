//
//
//
//
//
//
//

#include<iostream>
#include<time.h>
#include<cstdlib>

void insertionSort(int * array, int size)
{
	int key;

	for(int i = 0; i < size; i++)
	{
		key = array[i];
		int j = i - 1;
		
		while(j >= 0 && array[j] > key)
		{
			array[j+1] = array[j];
			j = j - 1;
		}
		array[j+1] = key;
	}	
}

int main()
{
	int array_size;

	srand(time(NULL));
	
	std::cout << "Enter size of array" << std::endl;
	std::cin >> array_size;

	int * array = new int[array_size];
	
	//initialize array with random values between 1 and 100
	std::cout << "INITIAL ARRAY: \n" << std::endl;
	std::cout << " | ";	
	for(int i = 0; i < array_size; i++)
	{	
		array[i] = rand() % 100 + 1;
		std::cout << array[i] << " | ";
	}
	std::cout << "\n" << std::endl;

	//call insertion sort on array
	insertionSort(array,array_size);

	//print sorted array
	std::cout << "SORTED ARRAY: \n" <<std::endl;
	std::cout << " | ";	
	for(int i = 0; i < array_size; i++)
	{	
		std::cout << array[i] << " | ";
	}
	std::cout << "\n" << std::endl;

}	
