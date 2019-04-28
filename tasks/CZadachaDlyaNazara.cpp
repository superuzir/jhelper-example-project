#include <iostream>

#include "../library/lib.hpp"
const long long MOD = 1e9 + 7;
class CZadachaDlyaNazara
{
	ll top (ll num)
	{
		ll ans = 0;

		while(num)
		{
			num >>= 1;
			ans++;
		}

		return ans - 1;
	}

	ll sumChet(ll n)
	{
		return (n % MOD) * ((n + 1) % MOD) % MOD;
	}

	ll sumNeChet(ll n)
	{
		return (n % MOD) * (n % MOD) % MOD;
	}

	ll sum(ostream &out, ll r)
	{
		ll z = top(r);
		ll sum;

		if (z % 2)
		{
			ll count_nechet = 0;

			for (ll i = 0; i < z; i += 2)
			{
				count_nechet += 1ll << i;
			}

			ll count_chet = r - count_nechet;

			sum = (sumChet(count_chet) + sumNeChet(count_nechet)) % MOD;

//			print count_nechet, count_chet;
//			print "z nech", z, sum;
		}
		else
		{
			ll count_chet = 0;

			for (ll i = 1; i < z; i += 2)
			{
				count_chet += 1ll << i;
			}

			ll count_nechet = r - count_chet;

			sum = (sumChet(count_chet) + sumNeChet(count_nechet)) % MOD;

//			print count_nechet, count_chet;
//			print "z chot", z, sum;
		}

		return sum;
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll l = read_ll();
		ll r = read_ll();

		ll sr = sum(out, r);
		ll sl = sum(out, l - 1);

		ll ans = sr - sl;
		if (ans < 0) ans += MOD;
		print ans;
	}
};
