#include <iostream>

#include "../library/lib.hpp"


static vll kinda_factorize(ll x)
{
	vll ans;

	for (ll i = 2; i * i <= x; i++)
	{
		ll fac = 1;

		while (x % i == 0)
		{
			fac *= i;
			x /= i;
		}

		if (fac != 1)
			ans.pb(fac);
	}

	if (x != 1)
		ans.pb(x);

	return ans;
}


class ELxnPermutationTomsk2019
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		auto ff = kinda_factorize(n);

		print accumulate(all(ff), 0ll);

		ll from = 1;

		forr(f, ff){
			out << from + f - 1 << ' ';

			for (ll i = 0; i < f - 1; ++i)
				out << from + i << ' ';

			from += f;
		}

		out << endl;
	}
};
