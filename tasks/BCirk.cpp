#include <iostream>

#include "../library/lib.hpp"

class BCirk
{
public:

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto c = read_s();
		auto a = read_s();

		ll ccnt = count(all(c), '1');

		ll c0 = 0;
		ll c1 = 0;
		ll c2 = 0;

		set<ll> team1;

		forn(i, n)
		{
			team1.insert(i + 1);

			if(c[i] == '0' && a[i] == '0') c0++;
			if(c[i] == '0' && a[i] == '1') c1++;
			if(c[i] == '1' && a[i] == '0') c1++;
			if(c[i] == '1' && a[i] == '1') c2++;
		}

		forn(i, c1 + 1)
		{
			ll d = ccnt - i;

			if(d % 2 || d < 0)
				continue;

			ll c2req = d / 2;

			if(c2req <= c2);
			{
				ll zerreq = n/2 - i - c2req;
				if(zerreq <= c0)
				{
//					print ccnt;
//					print zerreq, i, c2req;

					forn(j, n)
					{
						if(c[j] == '0' && a[j] == '0') { if(zerreq) { zerreq--; team1.erase(j + 1); } }
						if(c[j] == '0' && a[j] == '1') { if(i) { i--; team1.erase(j + 1); } }
						if(c[j] == '1' && a[j] == '0') { if(i) { i--; team1.erase(j + 1); } }
						if(c[j] == '1' && a[j] == '1') { if(c2req) { c2req--; team1.erase(j + 1); } }
					}

					forr(t, team1)
					{
						out << t << " ";
					}

					return;
				}
			}
		}

		print -1;
	}
};
