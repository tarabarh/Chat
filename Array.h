#pragma once
#include <assert.h>
#include <iostream>


template <typename T> class Array {

	int _len = 0;
	T* _array = nullptr;

	void _copy(T* array, T* new_array, int indx_start, int indx_finish) {
		for (int i = indx_start; i <= indx_finish; i++) {
			new_array[i] = array[i];
		}
	}

public:
	Array() = default;

	Array(int size) : _len(size) {
		_array = new T[_len];
	}

	~Array() {
		if (_array) {
			delete[] _array;
		}
	}

	void Delete() {
		if (_array) {
			for (int i = 0; i < _len; i++) {
				delete _array[i];
			}
		}
	}

	void reset() {
		if (!_array) {
			return;
		}
		delete[] _array;
		_len = 0;
		_array = nullptr;
	}

	int len()const {
		return _len;
	}

	void append(T x) {
		if (!_array) {
			_len++;
			_array = new T[_len];
			_array[0] = x;
			return;
		}
		T* temp_array = new T[_len + 1];
		_copy(_array, temp_array, 0, _len - 1);
		temp_array[_len] = x;
		_len++;
		delete[] _array;
		_array = temp_array;
	}

	T& operator[](int index) {
		assert(index < _len && index >= 0 && "Bad range!");
		return _array[index];
	}

	const T& operator[](int index) const {
		assert(index < _len && index >= 0 && "Bad range!");
		return _array[index];
	}

	friend std::ostream& operator<<(std::ostream& out, const Array& array) {

		out << "[ ";
		for (int i = 0; i < array._len - 1; i++) {
			out << array._array[i] << ", ";
		}
		out << array._array[array._len - 1] << " ]";
		return out;
	}

	void insert(int index, T x) {
		assert(index < _len && index >= 0 && "Bad range!");
		T* temp_array = new T[_len + 1];
		_copy(_array, temp_array, 0, index - 1);
		temp_array[index] = x;
		for (int i = index; i < _len; i++) {
			temp_array[i + 1] = _array[i];
		}
		_len++;
		delete[] _array;
		_array = temp_array;
	}

	bool inside(T x) {
		return findIndex(x) >= 0;
	}

	int findIndex(T x) {
		for (int i = 0; i < _len; i++) {
			if (_array[i] == x) {
				return i;
			}
		}
		return -1;
	}

	int count(T x) {
		int count = 0;
		for (int i = 0; i < _len; i++) {
			if (_array[i] == x) {
				count++;
			}
		}
		return count;
	}

	T pop(int index) {
		assert(index < _len && index >= 0 && "Bad range!");
		T* temp_array = new T[_len - 1];
		_copy(_array, temp_array, 0, index - 1);
		T value = _array[index];
		for (int i = index; i < _len - 1; i++) {
			temp_array[i] = _array[i + 1];
		}
		_len--;
		delete[] _array;
		_array = temp_array;
		return value;
	}

};