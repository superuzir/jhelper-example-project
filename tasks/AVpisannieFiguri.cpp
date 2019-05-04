#include <iostream>

#include "../library/lib.hpp"

class AVpisannieFiguri
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);

		ll ans = 0;

		forn1(i, n)
		{
			ll prev = vec[i - 1];
			ll curr = vec[i];


			if(curr == 1)
			{
				ans += prev == 2 ? 3 : 4;
			}


			if(curr == 2)
			{
				if(prev == 3)
				{
					print "Infinite";
					return;
				}

				if(i >= 2 && vec[i - 2] == 3)
					ans += 2;
				else 
					ans += 3;
			}

			if(curr == 3)
			{
				if(prev == 2)
				{
					print "Infinite";
					return;
				}
				
				ans += 4;
			}
		}

		print "Finite";
		print ans;
	}
};
