#include <iostream>

#include "../library/lib.hpp"

class AKanikuli
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto vec = read_vll(n);

		vll dp_otd(n, max_ll);
		vll dp_con(n, max_ll);
		vll dp_zal(n, max_ll);

		if(vec[0] == 0) dp_otd[0] = 1;
		if(vec[0] & 1)  dp_con[0] = 0;
		if(vec[0] & 2)  dp_zal[0] = 0;

		forn1(i, n)
		{
			dp_otd[i] = 1 + min3(dp_otd[i - 1], dp_con[i - 1], dp_zal[i - 1]);

			if(vec[i] & 1) dp_con[i] = min(dp_otd[i - 1], dp_zal[i - 1]);
			if(vec[i] & 2) dp_zal[i] = min(dp_otd[i - 1], dp_con[i - 1]);
		}

		print min3(dp_otd.back(), dp_con.back(), dp_zal.back());
	}
};
