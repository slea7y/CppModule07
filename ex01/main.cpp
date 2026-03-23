#include "iter.hpp"
#include <cstdio>
#include <iostream>

void print(const char &val){
	std::cout << val << std::endl ;
}

void add_five(int &val) {
	val += 5;
}

int main(){
	
	int a[4] = {0, 2, 4, 3};
	const char arr[5] = {'a', 'b', 'c', 'd'};
	
	//test 
	iter(arr, 4, print); //check const
	
	std::cout << "before: ";
	for ( int i =0; i < 4; i++ )
		std::cout << a[i];
	std::cout << std::endl;

	iter(a, 4, add_five); //check non-cost
		
	std::cout << "after:  ";
	for ( int i =0; i < 4; i++ )
		std::cout << a[i];
	std::cout << std::endl;
}