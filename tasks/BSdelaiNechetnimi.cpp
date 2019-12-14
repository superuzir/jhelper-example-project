#include <iostream>

#include "../library/lib.hpp"

class BSdelaiNechetnimi
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();

		forn(_, t)
		{
			ll n = read_ll();
			auto v = read_vll(n);
			set<ll> s(all(v));

			ll ans = 0;

			while(!s.empty()){
				ll el = *prev(s.end());
				s.erase(el);

				if(el % 2 == 0){
					ans++;
					s.insert(el / 2);
				}
			}

			print ans;
		}
	}
};
