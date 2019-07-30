#include <iostream>

#include "../library/lib.hpp"

class BVodyanayaLiliya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		double h = read_ll();
		double l = read_ll();
		
		out << fixed << setprecision(13) << ((l*l - h*h) / (2*h));
	}
};
