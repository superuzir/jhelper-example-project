#include <iostream>

#include "../library/lib.hpp"
typedef unsigned long long ull;
class D2PodvodnayaLodkaVRibinskomMoreUslozhnyonnayaRedaktsiya
{
	ull raskuzh(string s, ll cnt, bool b){
		reverse(all(s));

		string ans;

		cnt = min(ll(s.size()), cnt);

		forn(i, cnt){
			if(b){
				ans += '0';
				ans += s[i];
			} else {
				ans += s[i];
				ans += '0';
			}
		}

		ans += s.substr(cnt);

		reverse(all(ans));

		return stoull(ans);
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto v = read_vs(n);

		const ll MOD = 998244353;

		ll ans = 0;

		forn1(i, 11){
			ll freq = 0;

			forr(s, v){
				if(s.size() == i)
					freq++;
			}

			if(!freq)
				continue;

			forr(s, v){
				ull m1 = raskuzh(s, i, true) % MOD;
				ull m2 = raskuzh(s, i, false) % MOD;
				ans += (m1 + m2) * freq;
				ans %= MOD;
			}
		}

		print ans;
	}
};
