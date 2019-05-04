#include <iostream>

#include "../library/lib.hpp"

class C1EncryptionEasy
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll p = read_ll();
		vll vec = read_vll(n);

		ll sum = accumulate(all(vec), 0ll);

		ll cursum = 0;

		ll ans = 0;

		forn(i, n - 1)
		{
			cursum += vec[i];
			ll left = sum - cursum;

			ans = max(ans, cursum % p + left % p);
		}
		
		print ans;
	}
};
