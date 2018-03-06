#pragma once
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;
template <class T>
class Array 
{
  private:
  	size_t size;
  	T* ptr;
  public:

  	Array() 
  		: size{static_cast<size_t>(10)},
  		 ptr {new T[size]{}}
  	{

  	}

  	Array(int arraySize) 
  		: size{arraySize > 0 ? static_cast<size_t>(arraySize) : throw invalid_argument{"Array size must be greater than 0"}},
  		 ptr {new T[size]{}}
  	{

  	}
  	// Array(const Array& arrayToCopy)
  	// 	: size{arrayToCopy.size},
  	// 	ptr{new }
  	// {

  	// }

  	~Array()
  	{
  		delete[] ptr;
  	}

  	T* getPtr() const {return ptr;}

  	size_t getSize() const { return size; }

  	T& operator[](int subscript)
  	{
  		if (subscript < 0 || subscript >= size)
  		{
  			throw out_of_range{"subscript out of range"};

  		}
  		else
  		{
  			return ptr[subscript];
  		}
  	}

  	T operator[](int subscript) const
  	{
  		if (subscript < 0 || subscript >= size)
  		{
  			throw out_of_range{"subscript out of range"};

  		}
  		else
  		{
  			return ptr[subscript];
  		}
  	}

  	








};

template <class T>
ostream& operator<<(ostream& output, const Array<T>& a)
{
	for (size_t i{0}; i < a.getSize(); i++)
	{
		output << a.getPtr()[i] << " ";
	}
	return output;
}