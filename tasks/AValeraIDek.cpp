#include <iostream>

#include "../library/lib.hpp"

class AValeraIDek
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll q = read_ll();
		auto vec = read_vll(n);

		deque<ll> deq(all(vec));

		vpll ans105;

		forn(i, n)
		{
			ll a1 = deq[0];
			ll a2 = deq[1];

			deq.pop_front();
			deq.pop_front();

			ans105.pb({a1, a2});
			
			if(a1 > a2)
			{
				deq.push_front(a1);
				deq.push_back(a2);
			} else
			{
				deq.push_front(a2);
				deq.push_back(a1);
			}
		}

		ll mx = deq[0];
		deq.pop_front();
		
		forn(_, q)
		{
			ll m = read_ll();

			if(m <= n)
			{
				print ans105[m - 1].fi, ans105[m - 1].se;
			}
			else 
			{
				print mx, deq[(m - n - 1) % (n - 1)];
			}
		}
	}
};
