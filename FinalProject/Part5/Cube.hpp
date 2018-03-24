#pragma once 
#include "Square.hpp"

#include <iostream>
using namespace std;

class Cube: public Square //inherits square, just adds another dimension
{
  public:
    Cube() : Square() //call parent
    { }

    Cube(double _side) : Square(_side) //call parent
    { }

    double calcVal()
    {
        return side * Square::calcVal(); 
    }
    //output to stream
    friend ostream& operator<<(ostream &strm, Cube &c) 
  	{
        return strm << "Cube, side = " << c.side << ", volume = " << c.calcVal()<< endl;
    }
};