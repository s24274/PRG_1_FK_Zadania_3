#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class Punkt 
{
	private:
	int x;
	int y;
	
	public:
	Punkt (int c , int d)
	{
		x = c;
		y = d;
		
		std::cout << "Utworzono punkt(" << x << ", " << y << ").\n";
		
	}
	Punkt (Punkt const& p)
	{
		x = p.x;
		y = p.y;
		std::cout << "Utworzono punkt(" << x << ", " << y << ").\n";
	}
	~Punkt()
	{
		std::cout << "Zniszczono punkt(" << x << ", " << y << ").\n";
	
	};
	
	auto show() -> void
	{
		std::cout << "Wspolrzedne punktu to (" << x << "," << y << ")\n";
		
	}
	
	auto getX() -> int 
	{
		return x;
	}
	
	auto getY() -> int 
	{
		return y;
	}
	
	auto setXY(int n_x, int n_y) -> void
	{ 
		x = n_x;
		y = n_y;
	}
	auto setXY(Punkt g) -> void
	{
		x = g.x;
		y = g.y;
	}
	
	auto getXY(Punkt const& p) -> Punkt
	{
		return p;
		
	}
};

auto main() -> int
{
	Punkt a(1,2);
	Punkt b(5,3);
	
	a.show();
	b.show();
	std::cout << "\n";
	
	a.getX();
	b.getY();
	std::cout << "\n";
	
	std::cout << "Przed: \n";
	std::cout << "a: ";
	a.show();
	std::cout << "Po: \n";
	a.setXY(3,4);
	std::cout << "a: ";
	a.show();
	std::cout << "\n";
	
	Punkt blub(6,7);
	std::cout << "Przed:\n";
	std::cout << "b: ";
	b.show();
	std::cout << "Po: \n";
	b.setXY(blub);
	std::cout << "b: ";
	b.show();
	std::cout << "\n";
	
	blub = blub.getXY(a);
	std::cout << "Utworzono nowy punkt: ";
	blub.show();
	std::cout << "\n";
	
	Punkt nowy(blub);
	std::cout << "\n";


	return 0;
}

