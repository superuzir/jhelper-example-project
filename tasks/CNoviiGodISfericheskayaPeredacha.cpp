#include <iostream>

#include "../library/lib.hpp"
#include "../library/divisors.h"
#include "../library/ariphSum.h"


class CNoviiGodISfericheskayaPeredacha
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll div = divisors(n);

		transform(all(div), div.begin(), [&](ll d){ return ariphSum(1, n / d, d); });

		sort(all(div));

		answer(div, out);
	}
};
