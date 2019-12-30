#include <iostream>

#include "../library/lib.hpp"

class AIgraSKartami
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();
		forn(_, q)
		{
			ll n = read_ll();
			ll k1 = read_ll();
			ll k2 = read_ll();
			auto a = read_vll(k1);
			auto b = read_vll(k2);
			
			if(*max_element(all(a)) > *max_element(all(b)))
				print "YES";
			else
				print "NO";
		}
	}
};
