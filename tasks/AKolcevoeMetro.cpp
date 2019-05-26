#include <iostream>

#include "../library/lib.hpp"

class AKolcevoeMetro
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll a = read_ll();
		ll x = read_ll();
		ll b = read_ll();
		ll y = read_ll();

		forn(i, n)
		{
			if(a == b)
			{
				print "YES";
				return;
			}

			if(a == x || b == y)
				break;

			a++;

			if(a > n)
				a = 1;

			b--;

			if(b < 1)
				b = n;
		}
		
		print "NO";
	}
};
