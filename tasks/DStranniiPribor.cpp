#include <iostream>

#include "../library/lib.hpp"

class DStranniiPribor
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();

		vll v;
		
		forn(i, k + 1){
			out << "? ";

			forn(j, k + 1){
				if(i == j)
					continue;

				out << j + 1 << ' ';
			}

			out << endl;

			ll pos = read_ll();
			ll a = read_ll();
			
			v.pb(a);
		}
		
		ll m = count(all(v), *max_element(all(v)));
		
		print '!', m;
	}
};
