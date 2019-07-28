#include <iostream>

#include "../library/lib.hpp"

class D1ParallelnieVselennieLegkaya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll() - 1;
		ll m = read_ll();
		ll t = read_ll();

		vll v(n);

		v[k] = 1;

//		print v;

		forn(_, t)
		{
			ll c = read_ll();
			ll i = read_ll() - 1;

			if(c == 0)
			{
				if(i < k)
					v.erase(v.begin(), v.begin() + i + 1);
				else
					v.erase(v.begin() + i + 1, v.end());
			}
			else
			{
				v.insert(v.begin() + i, 0);
			}
			
//			dbg(c, i, v);
			
			forn(i, v.size())
			{
				if(v[i])
				{
					k = i;
					print v.size(), i + 1;
				}
			}
		}
	}
};
