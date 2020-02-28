#include <iostream>

#include "../library/lib.hpp"

class BSborPosilok
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll __q = read_ll();

		forn(_, __q){
			ll n = read_ll();
			auto v = read_vpll(n);

			soa(v);

			pll p;

			string ans;

			forn(i, n){
				if(v[i].se < p.se){
					ans.clear();
					break;
				}

				while(v[i].fi > p.fi){
					p.fi++;
					ans += 'R';
				}

				while(v[i].se > p.se){
					p.se++;
					ans += 'U';
				}
			}

			if(ans.empty()){
				print "NO";
			} else {
				print "YES";
				print ans;
			}
		}
	}
};
