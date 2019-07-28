#include <iostream>

#include "../library/lib.hpp"

class CRazbienieIObedinenie
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			ll n = read_ll();
			auto p = read_vplli(n);

			soa(p);
			
			ll ans = 1;

			ll r = p[0].fi.se;
			p[0].fi.fi = ans;

			forn1(i, n)
			{
				if(p[i].fi.fi > r)
					ans = 2;

				r = max(r, p[i].fi.se);
				p[i].fi.fi = ans;
			}

			sort(all(p), by(se));
			
			if(ans == 2)
			{
				forn(i, n)
					out << p[i].fi.fi << " ";
				out << endl;
			}
			else
				print -1;
		}
	}
};
