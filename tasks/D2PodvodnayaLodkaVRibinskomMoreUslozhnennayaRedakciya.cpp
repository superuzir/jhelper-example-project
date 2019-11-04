#include <iostream>

#include "../library/lib.hpp"


static ull merge(string a, size_t cnt, bool ch){
	reverse(all(a));
	cnt = min(cnt, a.size());

	string ans;

	forn(i, cnt){
		if(ch)
		{
			ans += a[i];
			ans += '0';
		}
		else {
			ans += '0';
			ans += a[i];
		}
	}

	forlr(i, cnt, a.size()){
		ans += a[i];
	}

	reverse(all(ans));

	return stoull(ans);
}


class D2PodvodnayaLodkaVRibinskomMoreUslozhnennayaRedakciya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto v = read_vs(n);

		ll ans = 0;

		forn(i, 11){
			ll s = 0;

			forr(str, v){
				if(str.size() == i + 1)
					s++;
			}

			if(s == 0)
				continue;

			forr(str, v){
				ull m1 = merge(str, i + 1, true) % 998244353;
				ull m2 = merge(str, i + 1, false) % 998244353;
				ans += s * m1;
				ans %= 998244353;
				ans += s * m2;
				ans %= 998244353;
//				dbg(i + 1, s, v[j], m1, m2, ans);
			}
		}
		
		print ans;
	}
};
