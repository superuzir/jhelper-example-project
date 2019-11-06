#include <iostream>

#include "../library/lib.hpp"
#include "../library/factorize.h"


class CPokraskaPlitok
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		auto f = factorize(n);

		f.erase(unique(all(f)), f.end());

//		print f;

		if(f.size() == 1)
			print f.front();
		else
			print 1;
	}
};
