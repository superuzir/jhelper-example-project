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

		if(n == 3){
			print read_ll(), read_ll(), read_ll();
			return;
		}

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

		auto st = find(all(fr), 1);

		ll f = st - fr.begin();

		*st = 0;

		auto st2 = find(all(fr), 1);

		ll l = st2 - fr.begin();

		*st2 = 0;


//		print m;

		auto fnd = [&](pll p){
			return m[p];
		};

//		dbg(fnd({2,3}));
//		dbg(fnd({2,5}));
//		dbg(fnd({3,5}));
//		dbg(fnd({2,4}));

		vll ans;

		forr(kv, m)
		{
			if(find(all(kv.se), f) != kv.se.end()){
//				dbg(f);

				pll fp = kv.fi;

				while(true){

//					print fp;
//					print fnd(fp);

					auto v = fnd(fp);

					if(find(all(v), l) != v.end())
					{
						ans.pb(f);
						ans.pb(fp.fi);
						ans.pb(fp.se);
						ans.pb(l);

						answer(ans, out);
						return;
					}

					if(v[0] == f)
						v[0] = v[1];

					ans.pb(f);

					pll nfp = {fp.fi, v[0]};
					f = fp.se;
					if(fnd(nfp).size() != 2)
					{
						nfp = pll{fp.se, v[0]};
						f = fp.fi;
					}

					fp = nfp;
				};
			}
		}







	}
};
