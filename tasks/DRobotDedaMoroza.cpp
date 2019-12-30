#include <iostream>

#include "../library/lib.hpp"

const ll MOD = 998244353;

#include "../library/mod.h"


class DRobotDedaMoroza
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		vll freq(1000*1000 + 2);
		vll prob(1000*1000 + 2);

		forn(i, n)
		{
			ll k = read_ll();
			auto v = read_vll(k);

			forn(j, k){
				freq[v[j]]++;
				prob[v[j]] = add(prob[v[j]], divide(1, multiply(n, k)));
			}
		}

//		dbg(freq);
//		dbg(prob);

		ll ans = 0;

		forn(i, prob.size()){
			ans = add(ans, multiply(prob[i], divide(freq[i], n)));
		}

		print ans;
	}
};
