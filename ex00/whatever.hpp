// • swap: Swaps the values of two given parameters. Does not return anything.
// • min: Compares the two values passed as parameters and returns the smallest one.
// If they are equal, it returns the second one.
// • max: Compares the two values passed as parameters and returns the greatest one.
// If they are equal, it returns the second one.

#include <iostream>

template <typename T> void swap(T x, T y) {
	T temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

template <typename T> T min(T x, T y) {
	return (x < y) ? x : y;
}

template <typename T> T max(T x, T y) {
	return (x > y) ? x : y;
}
