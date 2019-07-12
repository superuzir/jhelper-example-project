#include <iostream>

#include "../library/lib.hpp"

class CTokitsukazeIVibrasivanieVeshei
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		ll k = read_ll();

		ll max_poss = k;
		ll todrop = 0;
		ll ans = 1;

		forn(i, m)
		{
			ll p = read_ll();

			if(p <= max_poss)
			{
				todrop++;
			}
			else
			{
				if(todrop)
					ans++;

				max_poss += todrop;
				todrop = 1;

				if(p > max_poss)
				{
					max_poss += divceil(p - max_poss, k) * k;
				}
			}
		}

		print ans;
	}
};
