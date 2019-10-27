#include <iostream>

#include "../library/lib.hpp"

class B2PokupkaPodpisokNaSerialiUslozhnennayaVersiya
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

			map<ll, ll> m;

			forr(e, deq){
				m[e]++;
			}

			ll ans = m.size();

			forlr(i, d, n)
			{
				deq.push_back(vec[i]);

				m[vec[i]]++;
				m[deq.front()]--;

				if(m[deq.front()] == 0)
					m.erase(deq.front());

				deq.pop_front();
				ans = min(ans, ll(m.size()));
			}

			print ans;
		}
	}
};
