#include <iostream>

#include "../library/lib.hpp"

class BKrasivieChisla
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();

		forn(_, t){
			ll n = read_ll();
			auto v = read_vlli(n);

			soa(v);

			set<ll> s;

			string ans;

			forn(i, n){
				s.insert(v[i].se);

				if(*(prev(s.end())) - *s.begin() == s.size() - 1)
					ans += '1';
				else
					ans += '0';
			}

			print ans;
		}
	}
};
