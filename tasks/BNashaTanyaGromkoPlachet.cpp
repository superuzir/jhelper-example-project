#include <iostream>

#include "../library/lib.hpp"

class BNashaTanyaGromkoPlachet
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();
		ll a = read_ll();
		ll b = read_ll();

		if(k == 1 || k > n)
		{
			print a * (n - 1);
			return;
		}

		ll ans = 0;

		while(n > 1)
		{
			ll ost = n % k;

			if(ost)
			{
				if(ost == n)
					ost--;
				
				n -= ost;
				ans += ost * a;
			}
			else
			{
				ll nextn = n / k;
				ll suma = a * (n - nextn);

				n = nextn;
				ans += min(suma, b);
			}
			
//			print n;
		}

		print ans;
	}
};
