#include <iostream>

#include "../library/lib.hpp"
#include "../library/factorize.h"
#include "../library/itersame.h"

class CProizvedenieTrekhChisel
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll __q = read_ll();

		forn(_, __q){
			ll n = read_ll();

			auto f = factorize(n);

			f.resize(unique(all(f)) - f.begin());

			if(f.size() >= 2){
				vll a = {f[0], f[1], n / f[0] / f[1]};

				if(a[0] == a[2] || a[1] == a[2] || a[2] < 2)
					print "NO";
				else {
					print "YES";
					answer(a, out);
				}
			} else {
				vll a = {f[0], f[0] * f[0], n / f[0] / f[0] / f[0]};

				if(a[0] == a[2] || a[1] == a[2] || a[2] < 2)
					print "NO";
				else {
					print "YES";
					answer(a, out);
				}
			}
		}
	}
};
