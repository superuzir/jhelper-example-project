#include <iostream>

#include "../library/lib.hpp"

class AKonneRIARCMarklandN
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll __q = read_ll();

		forn(_, __q){
			ll n = read_ll();
			ll s = read_ll();
			ll k = read_ll();

			auto v = read_vll(k);

			set<ll> set(all(v));

            forn(i, 1e6){
                if(s + i <= n && !set.count(s + i)){
                    print i;
                    break;
                }

                if(s - i >= 1 && !set.count(s - i)){
                    print i;
                    break;
                }
            }
		}
	}
};
