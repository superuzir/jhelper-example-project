#include <iostream>

#include "../library/lib.hpp"

class AOcherednoePriravnivanieTsen
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll __q = read_ll();

		forn(_, __q){
			ll n = read_ll();
			auto v = read_vll(n);

			ll s = sua(v);

			print s / n + (s % n != 0);
		}
	}
};
