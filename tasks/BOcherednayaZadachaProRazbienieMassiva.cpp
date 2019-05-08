#include <iostream>

#include "../library/lib.hpp"

class BOcherednayaZadachaProRazbienieMassiva
{
	struct El
	{
		ll val;
		ll idx;
		bool ok;
	};

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		ll k = read_ll();
		vector<El> vec;

		forn(i, n)
		{
			vec.pb({read_ll(), i, false});
		}

		sort(all(vec), by(val));

		nfor(i, n)
		{
			if(i >= n - m * k)
				vec[i].ok = true;
		}

		sort(all(vec), by(idx));

		ll sum = 0;
		ll cnt = 0;
		ll k1 = 0;
		vll ans;

		forr(v, vec)
		{
			if(v.ok)
			{
				cnt++;
				sum += v.val;
			}

			if(cnt == m && k1 < k - 1)
			{
				cnt = 0;
				ans.pb(v.idx + 1);
				k1++;
			}
		}

		print sum;
		answer(ans, out);
	}
};
