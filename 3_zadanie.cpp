#include <iostream>
#include <string>

auto NWD(int a, int b) -> int
{
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else 
		{
			b = b - a;
		}
	}
return a;
}



class Wymierne 
{
	private:
	int numerator = 1;
	int denominator = 1;
	
	public:
	
	Wymierne (int m , int n)
	{
		simplify(m, n);
		numerator = m;
		denominator = n;
		
		std::cout << numerator << "/" << denominator << "\n";
	}
	
	Wymierne (int m)
	{
		numerator = m;
		
		std::cout << numerator << "/" << denominator << "\n";
	}
	
	
	auto simplify(int& m, int& n) -> void
	{
		int nwd = NWD(m,n);
		m = m/nwd;
		n = n/nwd;
	}
	
	auto getX() -> int
	{
		return numerator;
	}
	
	auto getY() -> int 
	{
		return denominator;
	}
	
	auto show() -> void 
	{
		std::cout << " num = " << numerator << ", den = " << denominator << "\n";
	}
	
	auto sum (Wymierne x) -> Wymierne 
	{
		if (x.denominator != denominator)
		{
			int blub = denominator;
			denominator = denominator * x.denominator;
			numerator = numerator * x.denominator;
			x.denominator = x.denominator * blub;
			x.numerator = x.numerator * blub;
		}
		
		int num = x.numerator + numerator;
		int den = denominator;
		simplify(num, den);
		
		Wymierne y (num, den);
		return y;
	}
	
	auto sum2(Wymierne x) -> void
	{
		if (x.denominator != denominator)
		{
			int blub = denominator;
			denominator = denominator * x.denominator;
			numerator = numerator * x.denominator;
			x.denominator = x.denominator * blub;
			x.numerator = x.numerator * blub;
		}
		
		int num = x.numerator + numerator;
		int den = denominator;
		simplify(num, den);
		denominator = den;
		numerator = num;
	}
	
	auto sum(int x) -> Wymierne
	{
		if ( denominator != 1)
		{
			x = x * denominator;
		}
		int num = x + numerator;
		int den = denominator;
		simplify(num, den);
		Wymierne y (num, den);
		return y;
	}
};
auto main() -> int 
{
	Wymierne wym_1(2,10);
	Wymierne wym_2(5);
	
	std::cout << "\n";
	
	int num_1 = wym_2.getX();
	
	std::cout << "Numerator wym_2 to: " << num_1 << "\n";
	std::cout << "\n";
	
	int den_1 = wym_1.getY();
	
	std::cout << "Denominator wym_1 to: " << den_1 << "\n";
	std::cout << "\n";
	
	std::cout << "wym_1: ";
	wym_1.show();
	std::cout << "\n";
	
	std::cout << "wym_2: ";
	wym_2.show();
	std::cout << "\n";
	
	Wymierne wym_3 = wym_1.sum(wym_2);
	wym_3.show();
	std::cout << "\n";
	
	Wymierne wym_4(3,6);
	wym_4.show();
	wym_4.sum2(wym_3);
	wym_4.show();
	std::cout << "\n";
	
	Wymierne wym_5 = wym_4.sum(1);
	Wymierne wym_6 = wym_1.sum(9);
	wym_5.show();
	wym_6.show();
	
return 0;
}
	
	
		
	
