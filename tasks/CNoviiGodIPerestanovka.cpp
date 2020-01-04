#include <iostream>

#include "../library/lib.hpp"

ll mod;

ll fac(vll & f, ll n)
{

	ll mul = 1;

	if(f[1] == 0){
		forn1(i, f.size()){
			mul *= i;
			mul %= mod;
			f[i] = mul;
		}
	}

	return f[n];
}


class CNoviiGodIPerestanovka
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		vll f(300 * 1000);
		ll n = read_ll();
		mod = read_ll();

		ll ans = 0;

		forn1(k, n+1){
			ll m = (n - k + 1) * (n - k + 1);
			m %= mod;

			m *= fac(f, k);
			m %= mod;

			if(k < n)
			{
				m *= fac(f, n - k);
				m %= mod;
			}

			ans += m;
			ans %= mod;
		}

		print ans;
	}
};
