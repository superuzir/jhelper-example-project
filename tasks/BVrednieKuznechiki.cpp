#include <iostream>

#include "../library/lib.hpp"
#include "../library/factorize.h"

class BVrednieKuznechiki
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll p = read_ll();
		ll y = read_ll();

		for(ll i = y; i > p; i--)
		{
			if(factorize(i)[0] > p)
			{
				print i;
				return;
			}
		}

		print -1;
	}
};
