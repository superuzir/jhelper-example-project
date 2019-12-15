#include <iostream>

#include "../library/lib.hpp"

class CVirezanieIVstavka
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();

		forn(_, t)
		{
			ll x = read_ll();
			auto s = read_s();
			ll n = s.size();

			forn(i, x){
				ll cnt = s[i] - '1';

				auto s2 = s.substr(i + 1);

				forn(j, cnt)
				{
					s += s2;
				}

				if(s.size() > x)
					break;
			}

			ll ans = n;

			forn(i, x){
				ll cnt = s[i] - '0';
				ans += (cnt - 1) * ((ans + MOD - i - 1) % MOD);
				ans %= MOD;
			}

			print ans;
		}
	}
};
