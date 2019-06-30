#include <iostream>

#include "../library/lib.hpp"

class DSortirovkaPodotrezkov
{
	struct Item
	{
		ll val;
		ll
	};

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();

		forn(_, t)
		{
			ll n = read_ll();

			vll a = read_vll(n);
			vll b = read_vll(n);

			{
				vll a1 = a;
				vll b1 = b;

				sort(all(a1));
				sort(all(b1));

				if(!equal(all(b1), a1.begin()))
				{
					print "NO";
				}
			}

			vll cnt(n + 1);


		}
	}
};
