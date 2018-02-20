	#include <iostream>
using namespace std;

class Rational
{
	//private properties
	int a; //numerator
	int b; //denominator

  public:
  	Rational(int numerator, int denominator)
  	{
  		if (denominator < 1)
  		{
  			a = numerator;
  			b = 1; //set to 1 by default
  		}
  		else
  		{
  			a = numerator;
  			b = denominator;
  		}

  		this->simplify();

  	}
  	Rational() //default is 1/1
  	{
  		a = 1;
  		b = 1;
  	}

  	void simplify();

  	//GETTERS
  	int getNumerator() { return a; }
  	int getDenominator() { return b; }
  	double getValue() const { return (double)a / (double)b; } //rational number

  	//SETTERS
  	void setNumerator(int newNum) 
  	{
  		a = newNum;
  	}

  	void setDenominator(int newDenom)
  	{

  		if (newDenom < 1)
  		{
  			b = 1; //set to 1 by default
  		}
  		else
  		{
  			b = newDenom;
  		}
  	}

  	//this is a nice override for the << operator
  	//I'm used to Java's toString, so this is the most convenient alternative
  	friend std::ostream& operator<<(std::ostream &strm, const Rational &r) 
  	{
	  return strm << r.a << "/" << r.b;
	}

	static int getLCD(int x, int y);

	Rational operator+ (const Rational& r)
	{
		int LCD = getLCD(this->b, r.b); //lowest common denominator
		int mult1 = LCD / this->b; //multipliers
		int mult2 = LCD / r.b;

		Rational r2;
		r2.setNumerator( this->a * mult1 + r.a * mult2); //multipliers times numerators
		r2.setDenominator(LCD);
		return r2;
	}

	Rational operator- (const Rational& r)
	{
		int LCD = getLCD(this->b, r.b); //lowest common denominator
		int mult1 = LCD / this->b; //multipliers
		int mult2 = LCD / r.b;

		Rational r2;
		r2.setNumerator( this->a * mult1 - r.a * mult2); //multipliers times numerators
		r2.setDenominator(LCD);
		return r2;
	}

	Rational operator* (const Rational& r)
	{
		Rational r2;
		r2.setNumerator(this->a * r.a);
		r2.setDenominator(this->b * r.b);
		r2.simplify(); //simplify just in case
		return r2;
	}

	Rational operator/ (const Rational& r)
	{
		Rational r2;
		r2.setNumerator(this->a * r.b); //cross multiply
		r2.setDenominator(this->b * r.a);
		r2.simplify(); //simplify just in case 	
		return r2;
	}

	bool operator== (const Rational& r)
	{
		// this->simplify();
		// r.simplify();
		return this->getValue() == r.getValue();
	}

	bool operator!= (const Rational& r)
	{
		// this->simplify();
		// r.simplify();
		return this->getValue() != r.getValue();
	}

	bool operator< (const Rational& r)
	{
		// this->simplify();
		// r.simplify();
		return this->getValue() < r.getValue();
	}

	bool operator> (const Rational& r)
	{
		// this->simplify();
		// r.simplify();
		return this->getValue() > r.getValue();
	}

	bool operator<= (const Rational& r)
	{
		// this->simplify();
		// r.simplify();
		return this->getValue() <= r.getValue();
	}

	bool operator>= (const Rational& r)
	{
		// this->simplify();
		// r.simplify();
		return this->getValue() >= r.getValue();
	}


};


//this function finds the GCF and factors the rational
void Rational::simplify()
{
	int larger = (a > b) ? a : b; //larger of the two
	
	int GCF = 0; //find the greatest common factor by incrementing
    for (int i = 1; i <= larger; i++) 
    {
        if (a % i == 0 && b % i ==0) //find remainder
        { 
            GCF = i; //admittedly, a brute force method
            //but it works!
        }
    }
    if (GCF > 0) //we've found a GCF
    {
	    a /= GCF;
    	b /= GCF;
	}

}

//static function that finds the lowest common denominator
int Rational::getLCD(int x, int y)
{
	int lowerbound = (x > y) ? x : y; //larger of the two

	int upperbound = x * y; //largest lcd possible

	for (int i = upperbound; i >= lowerbound; i--)
	{
		if ( i % x == 0 && i % y == 0)
		{
			upperbound = i; // the first time, this will be x*y
		}
	}

	return upperbound;
}
