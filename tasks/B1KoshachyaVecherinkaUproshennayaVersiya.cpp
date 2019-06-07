#include <iostream>

#include "../library/lib.hpp"

class B1KoshachyaVecherinkaUproshennayaVersiya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);

		vll col(10);

		ll ans = -1;

		forn(i, n)
		{
			col[vec[i] - 1]++;

			map<ll, ll> m;

			forn(j, 10)
			{
				if(col[j])
					m[col[j]]++;
			}

			if(m.size() == 2)
			{
				if((m.begin()->fi == 1 && m.begin()->se == 1) ||
					(m.rbegin()->se == 1 && (m.begin()->fi + 1 == m.rbegin()->fi)))
				{
					ans = i + 1;
				}

//				print *m.begin(), *m.rbegin();
			}
			else if(m.size() == 1)
			{
				if(m.begin()->fi == 1 || m.begin()->se == 1)
				{
					ans = i + 1;
				}
			}
			
//			print col, m.size(), ans;
		}

		print ans;
	}
};
