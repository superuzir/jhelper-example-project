#include <iostream>

#include "../library/lib.hpp"

class BStishokDlyaSanti
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			ll n = read_ll();
			ll s = read_ll();
			auto v = read_vll(n);

			if(s >= sua(v)){
				print 0;
				continue;
			}

			map<ll, ll> m;



//			print v;
//			print mx;

			forn(i, n){
				m[v[i]] = i + 1;
				s -= v[i];
				if(s < 0){
					break;
				}
			}

//			print m;

			print prev(m.end())->se;
		}
	}
};
