#include <iostream>

#include "../library/lib.hpp"

typedef unsigned long long ull;

class CSdelaiKhoroshim
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();
		forn(_, q)
		{
			ll n = read_ll();
			auto a = read_vll(n);

			ull s = 0;
			ull x = 0;

			forr(v, a){
				s += v;
				x ^= ull(v);
			}

			print 2;
			print x, x + s;
		}
	}
};
