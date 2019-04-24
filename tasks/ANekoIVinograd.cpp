#include <iostream>

#include "../library/lib.hpp"

class ANekoIVinograd
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		vll va = read_vll(n);
		vll vb = read_vll(m);

		ll a1 = 0, a2 = 0;
		ll b1 = 0, b2 = 0;

		forn(i, n)
		{
			if(va[i] % 2)
				a1++;
			else
				a2++;
		}

		forn(i, m)
		{
			if(vb[i] % 2)
				b1++;
			else
				b2++;
		}

		print min(a1, b2) + min(b1, a2);
	}
};
