#include <iostream>

#include "../library/lib.hpp"

class ASDnyomRozhdeniyaPolikarp
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();

		vll g;

		forn1(i, 10){
			string s;
			forn1(j, 11){
				s += '0' + i;
//				print s;
				g.pb(stoll(s));
			}
		}

		soa(g);
		
		forn(_, t){
			ll n = read_ll();

			auto it = lower_bound(all(g), n+1);
			
			print it - g.begin();
		}

	}
};
