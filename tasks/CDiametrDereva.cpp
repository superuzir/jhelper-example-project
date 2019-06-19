#include <iostream>

#include "../library/lib.hpp"

class CDiametrDereva
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();

		forn(_, t)
		{
			ll n = read_ll();

			ll ans = 0;

			for(ll k = 2; k < 2 * n; k *= 2)
			{
				vector<vll> v(2);

				forn(i, n)
				{
					v[i % k < k/2].pb(i + 1);
				}

				out << v[0].size() << " "
					<< v[1].size() << " ";

				forr(vv, v)
				forr(i, vv)
					out << i << " ";

				out << endl;

				ans = max(ans, read_ll());
			}

			out << -1 << " " << ans << endl;
		}
	}
};
