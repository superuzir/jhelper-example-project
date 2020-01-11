#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class AOdinPodem
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q) {
			ll n = read_ll();
			auto a = read_vll(n);
			auto b = read_vll(n);

			bool ok = true;

			forn(i, n){
				b[i] -= a[i];
				if(b[i] < 0)
					ok = false;
			}

			if(!ok){
				print "NO";
				continue;
			}

			ll c = 0;

			itersameall(b, {
				if(*b != 0)
					c++;
			});

			print c > 1 ? "NO" : "YES";
		}
	}
};
