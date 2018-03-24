#pragma once


#include <iostream>
using namespace std;

//object that stores pointers to two variables of type T
template <class T>
class Two
{
    T* left;
    T* right;        

  public:
    Two(T* _left, T* _right)
    {
        left = _left;
        right = _right;
    }

    void setLeft(T value)
    {
        *left = value; //set value at address left
    }

    void setRight(T value)
    {
        *right = value; //set value at address right
    }

    void setBoth(T value) //set both values
    {
        *right = value;
        *left = value;
    }
    void swap() //swap values
    {
        T* temp = left;
        left = right;
        right = temp;
    }

    T getLeft() //return the left value
    {
        return *left;
    }

    T getRight() //return the right value
    {
        return *right;
    }

    //output to stream
    friend ostream& operator<<(ostream &strm, Two<T> &t) 
  	{
	  return strm << "Two [" << t.getLeft() << ", " << t.getRight() << "]" << endl;
	}

};
