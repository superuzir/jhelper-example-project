#include <iostream>

#include "../library/lib.hpp"

class AKanatohodci
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		vll v = read_vll(3);
		ll d = read_ll();

		sort(all(v));

		ll ans = 0;

		if(v[1] - v[0] < d)
			ans += d - (v[1] - v[0]);
		
		if(v[2] - v[1] < d)
			ans += d - (v[2] - v[1]);

		print ans;
	}
};
