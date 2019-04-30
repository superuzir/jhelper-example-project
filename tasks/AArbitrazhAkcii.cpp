#include <iostream>

#include "../library/lib.hpp"

class AArbitrazhAkcii
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		ll r = read_ll();
		vll buy = read_vll(n);
		vll sell = read_vll(m);
		
		ll bestbuy = *min_element(all(buy));
		ll bestsell = *max_element(all(sell));
		
		if(bestbuy < bestsell)
		{
			ll count = r / bestbuy;
			ll left = r % bestbuy;
			ll ans = count * bestsell + left;
			print ans;			
		}
		else
		{
			print r;
		}
	}
};
