#pragma once
#include "stdio.h"

// Implement a function template iter that takes 3 parameters and returns nothing.
// • The first parameter is the address of an array.
// • The second one is the length of the array, passed as a const value.
// • The third one is a function that will be called on every element of the array
// The function passed as the third parameter may take its argument by const reference
// or non-const reference, depending on the context.
// template <typename T> void iter(T *arr, const int len, T (*func)(void)) {


template <typename T, typename F>
void iter(T *arr, const size_t len, F func) {

	if (arr == nullptr || func == nullptr)
		return;
	for (size_t i = 0; i < len; i++) {
		func(arr[i]);
	}
}

