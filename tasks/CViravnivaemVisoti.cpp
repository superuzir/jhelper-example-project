#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"

class CViravnivaemVisoti
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();
		vll vec = read_vll(n);

		sort(all(vec));

		vll bv(vec.back(), -1);
		{
			ll prev = 0;
			ll cnt = n;

			itersameall(vec, {
				for(ll i = prev; i < *b; i++)
					bv[i] = cnt;

				cnt -= e - b;
				prev = *b;
			});

			sort(all(bv));
		}

		ll ans = 0;
		ll sum = 0;

		forr(b, bv)
		{
			if(b == n)
				break;

			sum += b;

			if(sum > k)
			{
				sum = b;
				ans++;
			}
		}

		if(sum)
			ans++;

		print ans;
	}
};
