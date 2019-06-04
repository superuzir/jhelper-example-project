#include <iostream>

#include "../library/lib.hpp"

class DStasIOcheredVBufet
{
	struct Chel
	{
		ll a;
		ll b;
		ll dif;

		ll ned(ll j, ll n)
		{
			return a * (j - 1) + b * (n - j);
		}
	};

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vector<Chel> vec;

		forn(i, n)
		{
			Chel c;
			c.a = read_ll();
			c.b = read_ll();
			c.dif = c.b - c.a;
			vec.pb(c);
		}

		sort(all(vec), by(dif));

		ll ans = 0;

		forn(i, n)
		{
			ans += vec[i].ned(i + 1, n);
		}
		
		print ans;
	}
};
