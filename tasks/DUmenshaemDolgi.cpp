#include <iostream>

#include "../library/lib.hpp"

class DUmenshaemDolgi
{
public:

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();

		vll v(n + 1);

		forn(i, m){
			ll v1 = read_ll();
			ll v2 = read_ll();
			ll d = read_ll();

			v[v1] -= d;
			v[v2] += d;
		}

//		print v;

		auto next_pos = [&](ll i){
			while(v[i] <= 0 && i < n)
				i++;

			return i;
		};

		auto next_neg = [&](ll i){
			while(v[i] >= 0 && i < n)
				i++;

			return i;
		};

		ll a = next_pos(0);
		ll b = next_neg(0);

		vector<tuple<ll, ll, ll>> ans;

		while(a < n || b < n){
			ll d = min(v[a], -v[b]);

			v[a] -= d;
			v[b] += d;

//			dbg(a, b, d);

			ans.pb({b, a, d});

			a = next_pos(a);
			b = next_neg(b);
		}

		print ans.size();

		forr(t, ans){
			print get<0>(t), get<1>(t), get<2>(t);
		}
	}
};
