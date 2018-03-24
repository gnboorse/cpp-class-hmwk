#pragma once

#include <iostream>
using namespace std;

class Square  //represent a square
{
  protected:
    double side;

  public:
    Square()
    {
        side = 1.0; //default side is 1.0
    }
    Square(double _side)
    {
        side = _side;
    }
    double calcVal()
    {
        return side * side; //area
    }
    void setSide(double _side)
    {
        side = _side; //setter
    }
    //output to stream
    friend ostream& operator<<(ostream &strm, Square &s) 
  	{
        return strm << "Square, side = " << s.side << ", area = " << s.calcVal() << endl;
    }
};