#include <iostream>
#include <vector>
#include <string>
#include <cmath>

class Punkt
{
	public:
	int x;
	int y;
	
	Punkt (int a, int b)
	{
		x = a;
		y = b;
		
		std::cout << "Punkt o wspolrzednych (" << x << ", " << y << ")\n";
	}
};

class Prostokat
{
	private:
	Punkt pkta;
	Punkt pktb;
	
	public:
	
	Prostokat (int k, int l, int m, int n) : pkta(k,l), pktb(m,n)
	{
	}
	
	Prostokat (Punkt p1, Punkt p2) : pkta(p1), pktb(p2)
	{
    }
    
    auto show() -> void 
    {
		std::cout << "Wspolrzednie wierzcholkow prostokata:\n";
		std::cout << "Lewy gorny: (" << pkta.x << ", " << pkta.y << ")\n";
		std::cout << "Prawy dolny: (" << pktb.x << ", " << pktb.y << ")\n";
		
	}
	
	auto pole_p() -> int 
	{
		int pp = (abs(pkta.x) + abs(pktb.x)) * (abs(pkta.y) + abs(pktb.y));
		
		return pp;
	}
	
	auto p_inside(Punkt const& p) -> bool
	{
		if (p.x >= pkta.x && p.x <= pktb.x && p.y <= pkta.y && p.y >= pktb.y)
		{
			return true;
		}
		else 
		return false;
	}
	
	auto p_inside(int x, int y) -> bool
	{
		if (x >= pkta.x && x <= pktb.x && y <= pkta.y && y >= pktb.y)
		{
			return true;
		}
		else 
		return false;
	}
};

auto main() -> int
{
	Punkt pk1(1,2);
	Punkt pk2(5,3);
	
	Prostokat prost1(pk1, pk2);
	Prostokat prost2(1,3,-1,4);
	
	std::cout << "\n";
	
	prost1.show();
	prost2.show();
	
	std::cout << "\n";
	
	int pole_prost1 = prost1.pole_p();
	std::cout << "Pole pierwszego prostokata: " << pole_prost1 << ".\n";
	
	int pole_prost2 = prost2.pole_p();
	std::cout << "Pole drugiego prostokata: " << pole_prost2 << ".\n";
	
	std::cout << "\n";
	
	Punkt nowy_pkt(1,1);
	bool rozw1, rozw2;
	
	rozw1 = prost1.p_inside(nowy_pkt);
	
	if (rozw1)
	{
		std::cout << "Punkt (" << nowy_pkt.x << ", " << nowy_pkt.y << ")" << "znajduje sie w pierwszym prostokacie.\n";
	}
	else
	std::cout << "Punkt (" << nowy_pkt.x << ", " << nowy_pkt.y << ")" << "nie znajduje sie w pierwszym prostokacie.\n";
	
	rozw2 = prost1.p_inside(2,2);
	
	if (rozw2)
	{
		std::cout << "Punkt (2,2) znajduje sie w pierwszym prostokacie.\n";
	}
	else
	std::cout << "Punkt (2,2) nie znajduje sie w pierwszym prostokacie.\n";
	
return 0;

}
