#include <iostream>

#include "../library/lib.hpp"

class BLenta
{
public:
	struct Otr
	{
		ll idx;
		ll dist;
		bool brk;
	};

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		ll k = read_ll();
		vll vec = read_vll(n);

		vector<Otr> otr(n - 1);

		forn1(i, n)
			otr[i - 1] = {i - 1, vec[i] - vec[i - 1], false };

		sort(all(otr), by(dist));

		nfor(i, otr.size())
		{
			if(k == 1)
				break;

			otr[i].brk = true;

			k--;
		}

		sort(all(otr), by(idx));

		ll ans = 0;
		ll begin = vec[0];

		forn(i, n - 1)
		{
			if(otr[i].brk)
			{
				ans += vec[i] - begin + 1;
				begin = vec[i + 1];
			}
		}

		ans += vec.back() - begin + 1;

		print ans;
	}
};
