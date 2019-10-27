#include <iostream>

#include "../library/lib.hpp"

class B1PokupkaPodpisokNaSerialiUproshennayaVersiya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();
		forn(_, q)
		{
			ll n = read_ll();
			ll k = read_ll();
			ll d = read_ll();
			auto vec = read_vll(n);

			deque<ll> deq(vec.begin(), vec.begin() + d);

			ll ans = set<ll>(all(deq)).size();

			forlr(i, d, n)
			{
				deq.push_back(vec[i]);
				deq.pop_front();
				ans = min(ans, ll(set<ll>(all(deq)).size()));
			}
			
			print ans;
		}
	}
};
