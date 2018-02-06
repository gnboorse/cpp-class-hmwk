 /*

@author gabriel boorse

Complex Number class for WA3_exercise1

*/


class Complex 
{
    double realPart, imaginaryPart;
  public:
  	Complex();
  	Complex(double, double);
  	double getRealPart();
  	double getImaginaryPart();
  	void setRealPart(double r);
  	void setImaginaryPart(double i);
  	Complex add(Complex a, Complex b);
  	Complex subtract(Complex a, Complex b);
  	string toString();

};

Complex::Complex()
{
	realPart = 1;
	imaginaryPart = 1;
}

Complex::Complex(double r, double i) 
{
	realPart = r;
	imaginaryPart = i;
}

double Complex::getRealPart() 
{
	return realPart;
}

double Complex::getImaginaryPart()
{
	return imaginaryPart;
}

void Complex::setRealPart(double r)
{
	realPart = r;
}

void Complex::setImaginaryPart(double i)
{
	imaginaryPart = i;
}
Complex Complex::add(Complex a, Complex b) 
{
	Complex cx (a.getRealPart() + b.getRealPart(),
				 a.getImaginaryPart() + b.getImaginaryPart());
	return cx;
}

Complex Complex::subtract(Complex a, Complex b) 
{
	Complex cx (a.getRealPart() - b.getRealPart(),
				a.getImaginaryPart() - b.getImaginaryPart());
	return cx;
}

string Complex::toString()
{
	return "(" + to_string(realPart) + ", "
			   + to_string(imaginaryPart) + ")";
}

