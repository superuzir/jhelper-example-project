#include <iostream>

#include "../library/lib.hpp"

class APrazdnikIKonfeti
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		vll b = read_vll(n);
		vll g = read_vll(m);

		ll mx = *max_element(all(b));
		ll mn = *min_element(all(g));

		if(mx > mn)
		{
			print -1;
			return;
		}

		sort(rall(b));

		print accumulate(all(b), -b[0]) * m
			+ accumulate(all(g), 0ll)
			+ (mn > mx ? b[0] - b[1] : 0);
	}
};
