#include "Fraction.h"

using namespace std;

namespace sict{
    Fraction::Fraction(){  
            denom =-1;              // safe empty state
    }
    
    Fraction::Fraction(int n, int d) // n: numerator, d: denominator
    { 
        if(n >= 0 && d > 0){
            num = n;
            denom = d;
            reduce();
        }
        else 
            denom =-1;              // set to safe empty state
    }

    int Fraction::gcd()                                        // returns the greatest common divisor of num and denom 
    {
        int mn = min();                                        // min of num and denom
        int mx = max();                                        // mX of num and denom

        for (int x=mn ; x > 0 ; x--)                           // find the greatest common divisor
            if( mx % x == 0 &&  mn % x == 0)
                return x;
        return 1;

    } 

    void Fraction::reduce()                                         // simplify the Fraction number  
    {
        int tmp = gcd();
        num /= tmp;
        denom /= tmp;
    }

    int Fraction::max ()
    {
        return (num >= denom) ? num : denom; 
    }

    int Fraction::min()
    {
        return (num >= denom) ? denom : num; 
    }
  
    // TODO: Copy-paste the implementation of member isEmpty function from the in_lab part answer HERE
	void Fraction::display() const
	{
		if (this->isEmpty())
		{
			cout << "Invalid Fraction Object!";
		}
		else
		{
			if (denom != 1)
			{
				cout << num << "/" << denom;
			}
			else
			{
				cout << num;
			}
		}
	}

	// TODO: write the implementation of isEmpty function HERE
	bool Fraction::isEmpty() const
	{
		return (denom == -1);
	}

	// TODO: write the implementation of member operator+= function HERE
	Fraction& Fraction::operator+=(Fraction p)
	{
		if (p.isEmpty())
		{
			return *this;

		}
		else if (this->isEmpty())
		{
			return *this;
		}
		else
		{
			this->num = this->num * p.denom + this->denom * p.num;
			this->denom = this->denom * p.denom;
		}
		reduce();
		return *this;
	}

	// TODO: write the implementation of member operator+ function HERE
	Fraction Fraction::operator+(Fraction &p)
	{
		Fraction c;
		if (p.isEmpty())
		{
			return p;

		}
		else if (this->isEmpty())
		{
			return *this;
		}
		else
		{
			c.num = this->num * p.denom + this->denom * p.num;
			c.denom = this->denom * p.denom;
		}

		return c;
	}
	Fraction Fraction::operator+(int d)
	{
		Fraction p;
		if (this->isEmpty())
		{
			return *this;
		}
		else
		{
			p.num = this->num + this->denom * d;
			p.denom = this->denom;
		}

		return p;
	}

	// TODO: write the implementation of member operator* function HERE
	Fraction Fraction::operator*(Fraction &p)
	{
		if (p.isEmpty())
		{
			return p;

		}
		else if (this->isEmpty())
		{
			return *this;
		}
		else
		{
			this->num = this->num * p.num;
			this->denom = this->denom * p.denom;
			reduce();
		}

		return *this;
	}

    // TODO: Copy-paste the implementation of member display function from the in_ab part answer HERE
	bool Fraction::operator==(Fraction &p)
	{
		if (p.isEmpty() || this->isEmpty())
			return false;
		if (p.denom == this->denom && p.num == this->num)
			return true;
		else
			return false;
	}
    // TODO: write the implementation of member operator!= function HERE
	bool Fraction::operator!=(Fraction &p)
	{
		if (p.isEmpty() || this->isEmpty())
			return false;

		if (p.denom != this->denom && p.num != this->num)
			return true;
		else
			return false;
	}
    // TODO: write the implementation of member operator double () function HERE
	Fraction::operator double() 
	{
		reduce();
		if (this->isEmpty())
			return -1;
		else
			return (double(double(this->num) / double(this->denom)));
	}
    // TODO: write the implementation of member operator int () function HERE
	Fraction::operator int() const
	{
		if (this->isEmpty())
			return -1;
		else
			return (int(int(this->num) / int(this->denom)));
	}
}