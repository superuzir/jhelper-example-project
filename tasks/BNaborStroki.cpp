#include <iostream>

#include "../library/lib.hpp"

class BNaborStroki
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		string str = read_s();

		ll maxsub = 0;
		
		forn1(i, n)
			if (str.substr(0, i) == str.substr(i, i))
				maxsub = max(maxsub, i);
		
		if(maxsub)
			print n + 1 - maxsub;
		else
			print n;
	}
};
