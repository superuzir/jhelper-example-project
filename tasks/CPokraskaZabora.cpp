#include <iostream>

#include "../library/lib.hpp"

class CPokraskaZabora
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll q = read_ll();

		vpll vec = read_vpll(q);

		sort(all(vec));

		vll zabor(n + 1);

		forn(i, q)
		{
			forlr(j, vec[i].fi, vec[i].se + 1)
				zabor[j]++;
		}

		vll cnt1(n + 1);
		vll cnt2(n + 1);

		forn1(i, n + 1)
		{
			cnt1[i] = cnt1[i - 1] + (zabor[i] == 1);
			cnt2[i] = cnt2[i - 1] + (zabor[i] == 2);
		}

		auto range1 = [&](ll i, ll j){ return cnt1[j] - cnt1[i - 1]; };
		auto range2 = [&](ll i, ll j){ return cnt2[j] - cnt2[i - 1]; };

//		print zabor;
//		print cnt1;
//		print cnt2;
//		print range1(2, 3);
//		print range2(2, 3);

		ll min_uniq = max_ll;

		forn(i, q)
		forlr(j, i + 1, q)
		{
//			ll sum = vec[i].se - vec[i].fi + 1 + vec[j].se - vec[j].fi + 1;

			ll a = vec[i].fi;
			ll b = vec[i].se;
			ll c = vec[j].fi;
			ll d = vec[j].se;

			ll unique = 0;

			if(b < c)
			{
				unique = range1(a, b) + range1(c, d);
			}
			else
			{
				if(b < d)
					unique = range1(a, c) + range2(c, b) + range1(b, d);
				else
					unique = range1(a, c) + range2(c, d) + range1(d, b);
			}

//			print i, j,  unique;

			min_uniq = min(min_uniq, unique);
		}

		ll col = zabor.size() - count(all(zabor), 0);
		print col - min_uniq;
	}
};
