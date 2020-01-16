#include <iostream>

#include "../library/lib.hpp"

class BUbeiIkhVsekh
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q) {
			ll n = read_ll();
			ll r = read_ll();
			auto v = read_vll(n);

			sort(rall(v));

			v.resize(unique(all(v)) - v.begin());

			ll s = 0;

			forr(m, v){
				if(s >= m){
					break;
				}

				s += r;
			}

			print s / r;
		}
	}
};
