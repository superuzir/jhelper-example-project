#include <iostream>

#include "../library/lib.hpp"

class CRazdachaKonfet
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vl = read_vll(n);
		vll vr = read_vll(n);

		vll sum(n);

		forn(i, n) sum[i] = vl[i] + vr[i];

		ll max = *max_element(all(sum));
		ll min = *min_element(all(sum));

		if(min != 0)
		{
			print "NO";
		}
		else
		{
			vll ans;

			forn(i, n)
				ans.pb(max + 1 - sum[i]);

			forn(i, n)
			{
				ll cnt_l = count_if(ans.begin(), ans.begin() + i, [&](ll v){ return v > ans[i]; });
				ll cnt_r = count_if(ans.begin() + i + 1, ans.end(), [&](ll v){ return v > ans[i]; });

				if(cnt_l != vl[i] || cnt_r != vr[i])
				{
					print "NO";
					return;
				}
			}
			
			print "YES";
			answer(ans, out);
		}

	}
};
