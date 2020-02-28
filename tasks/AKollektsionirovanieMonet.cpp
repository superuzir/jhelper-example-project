#include <iostream>

#include "../library/lib.hpp"

class AKollektsionirovanieMonet
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll __q = read_ll();

		forn(_, __q){
			vll a = read_vll(3);
			ll n = read_ll();

			soa(a);

			n -= a[2] - a[0];
			n -= a[2] - a[1];

			if(n < 0 || n % 3)
				print "NO";
			else
				print "YES";
		}
	}
};
