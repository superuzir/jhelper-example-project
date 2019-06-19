#include <iostream>

#include "../library/lib.hpp"

class ESupergeroiskayaBitva
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll h = read_ll();
		ll n = read_ll();
		vll d = read_vll(n);

		vll hp(n);
		ll curhp = 0;
		forn(i, n)
		{
			curhp += d[i];
			hp[i] = curhp;
		}

		ll minhp = *min_element(all(hp));

		if(minhp >= 0)
		{
			print "-1";
			return;
		}

		ll hpleft = h + minhp;

		if(hpleft > 0 && hp.back() >= 0)
		{
			print "-1";
			return;
		}

		ll rounds = 0;
		
		if(hpleft > 0)
		{
			rounds = hpleft / -hp.back() + (hpleft % -hp.back() != 0);
			h += hp.back() * rounds;
		}
			

		forn(i, n)
		{
			if(h <= 0)
			{
				print rounds * n + i;
				return;
			}
			h += d[i];
		}

		print (rounds + 1) * n;
	}
};
