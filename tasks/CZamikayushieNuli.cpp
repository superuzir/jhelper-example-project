#include <iostream>

#include "../library/lib.hpp"
#include "../library/factorize.h"
#include "../library/itersame.h"


class CZamikayushieNuli
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll b = read_ll();

		auto fac = factorize(b);

		ll ans = max_ll;
		
		itersameall(fac, {
			ll cnt = 0;
			ll div = *b;
			
			for(ll mul = n / div; mul; mul /= div)
			{
				cnt += mul;
			}
			
			ans = min(ans, cnt / (e - b));
		});

		print ans;
	}
};
