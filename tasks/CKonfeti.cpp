#include <iostream>

#include "../library/lib.hpp"

class CKonfeti
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);
		
		vll sum(n + 1);
		
		forn(i, n)
		{
			sum[i + 1] = sum[i] + vec[i];
		}

//		print vec;
//		print sum;
		
		ll q = read_ll();

		forn(_, q)
		{
			ll l = read_ll();
			ll r = read_ll();
			
			ll s = sum[r] - sum[l - 1];
			
			print s / 10;
		}
	}
};
