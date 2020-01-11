#include <iostream>

#include "../library/lib.hpp"
#include "../library/dsu.h"

class DSekretnieParoli
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto v = read_vs(n);

		Dsu dsu(27);

		forr(s, v){
			forr(c, s){
				dsu.make(c - 'a' + 1);
			}
		}

		forr(s, v){
			forn1(i, s.size()){
				dsu.unite(s[i - 1] - 'a' + 1, s[i] - 'a' + 1);
			}
		}

		set<ll> set;

		forn(i, 27){
			ll s = dsu.find(i);
			if(s)
				set.insert(s);
		}

		print set.size();
	}
};
