#include <iostream>

#include "../library/lib.hpp"

class ANovogodnyayaGirlyanda
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();
		
		forn(_, q)
		{
			auto v = read_vll(3);
			
			soa(v);
			
			if(v[0] + v[1] < v[2] - 1)
				print "No";
			else
				print "Yes";
		}
	}
};
