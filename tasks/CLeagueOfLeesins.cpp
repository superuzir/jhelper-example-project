#include <iostream>

#include "../library/lib.hpp"

class CLeagueOfLeesins
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		vll fr(n + 1);
		multimap<pll, ll> m;

		forn(i, n - 2){
			auto v = read_vll(3);

			soa(v);

			forr(vv, v)
				fr[vv]++;

			m.insert(pair(pll(v[0], v[1]), v[2]));
			m.insert(pair(pll(v[0], v[2]), v[1]));
			m.insert(pair(pll(v[1], v[2]), v[0]));
		}

		auto req = [&](pll key){
			if(key.fi > key.se)
				swap(key.fi, key.se);

			return m.find(key);
		};

		auto rm = [&](pll key, ll value){
			if(key.fi > key.se)
				swap(key.fi, key.se);

			auto range = m.equal_range(key);

			for (auto it = range.first; it != range.second; )
			{
				if(it->second == value)
					it = m.erase(it);
				else
					++it;
			}
		};

		pll f;

		{
			vpll b;

			forn1(i, n + 1){
				if(fr[i] == 1 || fr[i] == 2)
					b.pb({fr[i], i});
			}

			soa(b);

			f = {b[0].se, b[2].se};

			if(req(f) == m.end())
				f = {b[0].se, b[3].se};
		}

//		dbg(f);

		vll ans = {f.fi, f.se};

		forn(i, n - 2)
		{
			auto nx = req(f);

			ll a[3] = {f.fi, f.se, nx->se};

			rm({a[0], a[1]}, a[2]);
			rm({a[0], a[2]}, a[1]);
			rm({a[1], a[2]}, a[0]);

			ans.pb(a[2]);

			f = {a[1], a[2]};
		}

		answer(ans, out);
	}
};
