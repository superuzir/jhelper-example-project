#include <iostream>

#include "../library/lib.hpp"

class CRazdelenieMassiva
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();
		vll vec = read_vll(n);

		vll dif;

		forn1(i, n)
		{
			dif.pb(vec[i] - vec[i - 1]);
		}

		sort(rall(dif));
		
		ll sum = accumulate(dif.begin(), dif.begin() + k - 1, 0);

		print vec.back() - vec.front() - sum;
	}
};
