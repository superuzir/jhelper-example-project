#include <iostream>

#include "../library/lib.hpp"

class BIhabIStranniiChelovek
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);
		
		bool ch = false;
		bool nech = false;
		
		forn(i, n)
		{
			if(vec[i] % 2)
				ch = true;
			else
				nech = true;
		}
		
		if(ch && nech)
			sort(all(vec));
		
		answer(vec, out);
	}
};
