#include <iostream>

#include "../library/lib.hpp"

class CIhabIOsobayaZadachaORaskraske
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		vll ans(n + 1, 0);

		ll x = 1;

		for (ll i = 2; i <= n; ++i)
		{
			if (ans[i] == 0)
			{
				for (ll j = i; j <= n; j += i)
				{
					if(ans[j] == 0)
						ans[j] = x;
				}
				
				x++;
			}
		}

		for (ll i = 2; i <= n; ++i)
		{
			out << ans[i] << " ";
		}
		
		out << endl;
	}
};
