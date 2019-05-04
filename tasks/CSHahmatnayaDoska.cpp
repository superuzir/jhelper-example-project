#include <iostream>

#include "../library/lib.hpp"


class CSHahmatnayaDoska
{
	ll dist(const vs & in, char first)
	{
		ll ans = 0;

		forn(i, in.size())
		forn(j, in[0].size())
		{
			bool color = in[i][j] == first;

			if((!color && ((i + j) % 2 == 0)) ||
				(color && ((i + j) % 2)))
				ans++;
		}

		return ans;
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		vector<vs> str = {
			read_vs(n),
			read_vs(n),
			read_vs(n),
			read_vs(n)
		};

		vpll dists;

		forr(s, str)
			dists.pb({dist(s, '1'), dist(s, '0')});

		ll ans = max_ll;

		sort(all(dists));

		do
		{
			ll cand = 0;

			cand += n * n - dists[0].fi;
			cand += n * n - dists[1].fi;
			cand += n * n - dists[2].se;
			cand += n * n - dists[3].se;

			ans = min(ans, cand);

		} while(next_permutation(all(dists)));

		print ans;
	}
};
