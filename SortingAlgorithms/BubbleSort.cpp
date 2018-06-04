//***************************************
//
// Author: Gregory Hinkson
//
// Date: 06/04/2018
//
//***************************************

#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;
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

	//run bubble sort on array
	BubbleSort(array,array_size);

	//print sorted array
	std::cout << "SORTED ARRAY: \n" << std::endl;
	std::cout << " | ";	
	for(int i = 0; i < array_size; i++)
	{
		std::cout << array[i] << " | ";
	}
	std::cout << "\n" << std::endl;
}
