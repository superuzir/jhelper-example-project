#include <iostream>

#include "../library/lib.hpp"

class BBashnyaIzKubikov
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();

		forn(_, t){
			ll x = read_ll();

			ll c = x % 14;

			if(x >= 15 && c >= 1 && c <= 6)
				print "YES";
			else
				print "NO";
		}
	}
};
