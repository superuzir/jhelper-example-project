#include <iostream>

#include "../library/lib.hpp"

class BPosledovatelnostTsifrUslozhnyonnayaVersiya
{
	ll digcnt(ll n){
		ll ans = n;

		forn1(i, n)
			ans *= 10;

		return ans * 9;
	}

	ll start(ll n){
		ll ans = 1;

		forn1(i, n)
			ans *= 10;

		return ans;
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll() - 1;

		forn1(i, 17)
		{
			ll d = digcnt(i);

			if(n < d){
				ll chi = n / i;

//				dbg(i, n, chi);

				n -= chi * i;

				ll ch = start(i) + chi;

//				dbg(n, ch);

				print to_string(ch)[n];

				return;
			}

			n -= d;
		}


	}
};
