#include <iostream>

#include "../library/lib.hpp"

class BInteresniiPodmassiv
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();
		forn(_, q)
		{
			ll n = read_ll();
			auto a = read_vll(n);

			pll ans = {-1, -1};

			forn1(i, n){
				if(abs(a[i - 1] - a[i]) > 1)
				{
					ans = {i, i+1};
					break;
				};
			}

			if(ans.fi != -1)
			{
				print "YES";
				print ans.fi , ans.se;
			} else {
				print "NO";
			}
		};
	}
};
