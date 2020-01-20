#include <iostream>

#include "../library/lib.hpp"
#include "../library/matrix.h"

class EElections
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();

		auto v = read_mll(m, n);

		vll ans(m);

		iota(all(ans), 1);

		forn(i, n - 1){
			vpll dif;

			ll s = 0;

			forn(j, m){
				dif.pb({v[j][n - 1] - v[j][i], j + 1});
				s += dif.back().fi;
			}

			soa(dif);

			vll cand;

			while(s > 0){
				s -= dif.back().fi;
				cand.pb(dif.back().se);
				dif.pop_back();
			}

			if(cand.size() < ans.size())
				ans = cand;
		}

		print ans.size();
		answer(ans, out);
	}
};
