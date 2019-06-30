#include <iostream>

#include "../library/lib.hpp"

class BMagazinBukv
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto s = read_s();

		ll m = read_ll();

		vector<vll> cnt(26, vll(n));

		cnt[s[0] - 'a'][0] = 1;

		forn1(i, n)
		{
			forn(j, 26)
			{
				cnt[j][i] = cnt[j][i - 1] + (s[i] == ('a' + j));
			}
		}

		forn(i, m)
		{
			auto t = read_s();

			vll cntt(26);
			
			forr(c, t)
			{
				cntt[c - 'a']++;
			}
			
			ll ans = 0;
			
			forn(k, 26)
			{
				auto it = lower_bound(all(cnt[k]), cntt[k]);
				ans = max(ans, ll(it - cnt[k].begin()) + 1);
			}
			
			print ans;
		}
	}
};
