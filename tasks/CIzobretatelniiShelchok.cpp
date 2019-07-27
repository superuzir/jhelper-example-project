#include <iostream>

#include "../library/lib.hpp"

class CIzobretatelniiShelchok
{
	ll a;
	ll b;

public:
	ll rec(ostream &out, vll &vec, ll l, ll r)
	{
		ll mid = (l + r) / 2;

		auto lit = lower_bound(all(vec), l);
		auto rit = upper_bound(all(vec), r);

		ll cnt = rit - lit;

//		dbg(l, mid, r, cnt);

		if(!cnt)
		{
//			print a;
			return a;
		}

		if(l == r)
		{
//			print b * cnt;
			return b * cnt;
		}

		ll dstr = cnt * (r - l + 1) * b;
		ll r1 = rec(out, vec, l, mid);
		ll r2 = rec(out, vec, mid + 1, r);

//		dbg(l, mid, r, cnt, dstr, r1, r2);

		return min(dstr, r1 + r2);
	}

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();
		a = read_ll();
		b = read_ll();
		vll vec = read_vll(k);

		sort(all(vec));

		ll ans = rec(out, vec, 1, 1 << n);

		print ans;
	}
};
