#include <iostream>

#include "../library/lib.hpp"

class CLeagueOfLeesins
{
public:

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		map<pll, vll> m;

		vll fr(100001);

		forn(i, n - 2){
			ll v[] = { read_ll(), read_ll(), read_ll() };
			sort(v, v + 3);

			m[{v[0], v[1]}].pb(v[2]);
			m[{v[1], v[2]}].pb(v[0]);
			m[{v[0], v[2]}].pb(v[1]);


			fr[v[0]]++;
			fr[v[1]]++;
			fr[v[2]]++;
		}

//		print fr;

		auto st11 = find(all(fr), 1);
		auto st12 = find(st11 + 1, fr.end(), 1);

		auto st21 = find(all(fr), 2);
		auto st22 = find(st21 + 1, fr.end(), 2);


		ll s11 = st11 - fr.begin();
		ll s12 = st12 - fr.begin();
		ll s21 = st21 - fr.begin();
		ll s22 = st22 - fr.begin();

		auto sorted = [](pll p){
			if(p.fi > p.se)
				swap(p.fi, p.se);

			return p;
		};
		
		if(!m.count(sorted({s11, s21})))
			s21 = s22;

//		dbg(s11, s21);

		vll ans;

		set<ll> was;

		while(m.count(sorted({s11, s21}))){

			vll c = m[sorted({s11, s21})];

//			dbg(c.size());

			if(was.count(c[0])){
				if(c.size() == 1){
					ans.pb(s11);
					ans.pb(s21);
					break;
				} else {
					c[0] = c[1];
				}
			}

			was.insert(s11);
			ans.pb(s11);


			s11 = s21;
			s21 = c[0];



//			dbg(s11, s21);
		}

//		ans.pb(s21);

		answer(ans, out);
	}
};
