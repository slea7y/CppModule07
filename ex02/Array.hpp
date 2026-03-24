#include <iostream>
#include <array>
#include <stdexcept>
// #include <excpetions>

template <typename T> class Array {
	public:
		Array(){ //constructor with no parameter
			_array = new T();
			_size = 0; 
		};
		Array(unsigned int n){  //constructor with unsigned int n as aparameter 
			_array = new T[n]; 
			_size = n; 
		};
		T &operator[](int idx){
			if (idx > this->_size || idx < 0)
				throw std::out_of_range("out of range");
			return _array[idx];
		};
		const T operator[](int idx) const { //subscript operator
			if (idx > this->_size || idx < 0)
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

		int getSize() const{
			return this->_size;
		};
		T *getArray(){
			return this->_array;
		};
	private:
		T *_array;
		int _size;
};