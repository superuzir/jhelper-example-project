#include <iostream>

#include "../library/lib.hpp"

class CPrizhkiPoPlatformam
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		ll d = read_ll();
		auto v = read_vll(m);

		ll sum = sua(v);

		vll ans(n);

		ll cur = 0;

		for(ll x = d;; ){
//			dbg(x, n + 1 - x,  sum);

			if(n + 1 - x <= sum){
				ll j = n;

//				dbg(cur, v.size());

				forrl(i, cur, v.size()){
//					dbg(i);
					forn(k, v[i])
					{
						ans[j - 1] = i + 1;
//						dbg(i, k, j, i);

						j--;
					}
				}

				break;
			} else if(cur >= v.size()) {
				print "NO";
				return;
			} else {
				forlr(i, x, x + v[cur]){
					ans[i - 1] = cur + 1;
				}
				x += v[cur] - 1 + d;
				sum -= v[cur];
				cur++;
//				dbg(x, ans);
			}
		}

		print "YES";
		answer(ans, out);
	}
};
