#include <iostream>

#include "../library/lib.hpp"

class BSonyaIVistavka
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		
		forn(i, m)
			read_vll(2);
		
		string ans;
		
		forn(i, n)
			ans += to_string(i & 1);
		
		print ans;
	}
};
