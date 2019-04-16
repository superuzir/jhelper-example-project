#include <iostream>

#include "../library/lib.hpp"

class AVosstanovlenieTrehChisel
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		vll vec = read_vll(4);

		sort(all(vec));
		
		print vec[3] - vec[0], vec[3] - vec[1], vec[3] - vec[2];
	}
};
