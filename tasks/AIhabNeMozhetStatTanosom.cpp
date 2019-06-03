#include <iostream>

#include "../library/lib.hpp"

class AIhabNeMozhetStatTanosom
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(2*n);
		
		sort(all(vec));
		
		if(vec.front() == vec.back())
		{
			print -1;
		}
		else
		{
			answer(vec, out);
		}
	}
};
