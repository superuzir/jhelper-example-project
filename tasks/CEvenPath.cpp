#include <iostream>

#include "../library/lib.hpp"

class CEvenPath
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll __q = read_ll();

		auto r = read_vll(n);
		auto c = read_vll(n);

		vll rr(n);
		vll cc(n);

		forn1(i, n){
			if(r[i - 1] % 2 == r[i] % 2) rr[i] = rr[i - 1]; else rr[i] = rr[i - 1] + 1;
			if(c[i - 1] % 2 == c[i] % 2) cc[i] = cc[i - 1]; else cc[i] = cc[i - 1] + 1;
		}

		forn(_, __q){
			ll ra = read_ll() - 1;
			ll ca = read_ll() - 1;
			ll rb = read_ll() - 1;
			ll cb = read_ll() - 1;

			if(rr[ra] == rr[rb] && cc[ca] == cc[cb])
				print "YES";
			else
				print "NO";
		}
	}
};
