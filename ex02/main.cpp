#include <cstdio>
#include <exception>
#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

// int main(){
// 	// int *a = new int();
// 	// int *a;
// 	Array a(6);

// 	std::cout << Array::a << std::endl;
// }

// int main(int, char**)
// {
// 	Array<int>numbers(5);
// 	// try
// 	for (int i = 0; i < 5; i++){
// 		int value = 1;
// 		numbers[i] = value;
// 	}
// 	// catch (std::exception &e) {
// 	// 	std::cout << "exception: " << e.what() << std::endl;
// 	// }
// 	// for (int i = 0; i < 5; i++)
// 	// 	printf("%i ", numbers[i]);

// 	Array<int>number2(6);

// 	number2 = numbers;

// 	for (int i = 0; i < 5; i++)
// 		printf("%i ", number2[i]);

// 	printf("adres 1: %p\n", number2.getArray());
// 	printf("adres 2: %p\n", numbers.getArray());
// }

#include <stdio.h>

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

	for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
	
	//SCOPE
    {
		Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
	
    for (int i = 0; i < MAX_VAL; i++)
    {
		if (mirror[i] != numbers[i])
        {
			std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
		numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
		std::cerr << e.what() << '\n';
    }
	printf("gowno\n");
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
	// std::cout <<numbers[MAX_VAL] << std::endl;
    // delete [] mirror;//
    return 0;
}