#include <iostream>

#include "../library/lib.hpp"

class BGlupayaOshibka
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto v = read_vll(n);

		map<ll, ll> m;
		vll ans;
		ll cur = 0;

		set<ll> was;

		forn(i, n){
			cur++;
			ll vv = v[i];
			if(vv > 0){
				m[vv]++;
				if(m[vv] > 1 || was.count(vv))
				{
					print -1;
					return;
				}
				was.insert(vv);
			} else {
				if(!m.count(-vv)){
					print -1;
					return;
				} else {
					m.erase(-vv);
					if(m.empty()) {
						ans.pb(cur);
						cur = 0;
						was.clear();
					}
				}
			}
		}

		if(!m.empty()){
			print -1;
			return;
		}

		print ans.size();
		answer(ans, out);
	}
};
