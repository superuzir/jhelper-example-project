#include <iostream>

#include "../library/lib.hpp"

class BStolbi
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);
		
		ll maxi = max_element(all(vec)) - vec.begin();
		
		forlr(i, maxi + 1, n)
		{
			if(vec[i] >= vec[i - 1])
			{
				print "NO";
				return;
			}
		}

		lrfor(i, 0, maxi)
		{
			if(vec[i] >= vec[i + 1])
			{
				print "NO";
				return;
			}
		}
		
		print "YES";
	}
};
