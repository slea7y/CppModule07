#pragma once
#include <stdexcept>
// from General rules:
// • Any function implementation put in a header file (except for function templates)
// means 0 to the exercise.

template <typename T> class Array {
	public:
		Array() : _array(new T[0]), _size(0) { //constructor with no parameter
		};
		Array(unsigned int n) : _array(new T[n]), _size(n) {  //constructor with unsigned int n as aparameter 
		};
		T &operator[](int idx){
			if (idx >= this->_size || idx < 0)
				throw std::out_of_range("out of range");
			return _array[idx];
		};
		const T &operator[](int idx) const { //subscript operator
			if (idx >= this->_size || idx < 0)
				throw std::out_of_range("out of range");
			return _array[idx];
		}
		Array(const Array &other) {
			this->_size = other._size;
			this->_array = new T[this->_size];
			for (int i = 0; i < other._size; i++)
				this->_array[i] = other._array[i];
		};
		Array &operator=(const Array &other) {
			if (this != &other) {
				delete[] this->_array;
				this->_size = other._size;
				this->_array = new T[this->_size];
				for (int i = 0; i < other._size; i++)
					this->_array[i] = other._array[i];
			}
			return *this;
		};
		~Array() {
			delete[] _array;
		};

		int size() const{
			return this->_size;
		};
		T *getArray(){
			return this->_array;
		};
	private:
		T *_array;
		int _size;
};