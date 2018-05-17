//***************************************
//
// Author: Gregory Hinkson
//
// Date: 03/29/2018
//
//***************************************

#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

void selectionSort(int * array, int size)
{
	int min;
	
	for(int i =  0; i < size; i++)
	{
		min = i;
		for(int j = i + 1; j < size; j++)
		{
		
			if(array[j] < array[min])
			{
				min = j;
			}	
		}
		//swap values
		int tempVal = array[min];
		array[min] = array[i];
		array[i] = tempVal;
	}	 	
}

int main()
{
	int array_size;
	
	//seed random generator
	srand(time(NULL));
	
	std::cout << "Enter size of array: ";
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

	//run selection sort on array
	selectionSort(array,array_size);

	//print sorted array
	std::cout << "SORTED ARRAY: \n" << std::endl;
	std::cout << " | ";	
	for(int i = 0; i < array_size; i++)
	{
		std::cout << array[i] << " | ";
	}
	std::cout << "\n" << std::endl;
}


