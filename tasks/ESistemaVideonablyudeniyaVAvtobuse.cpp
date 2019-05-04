#include <iostream>

#include "../library/lib.hpp"

class ESistemaVideonablyudeniyaVAvtobuse
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll w = read_ll();
		vll vec = read_vll(n);

		vll mom(n + 1);

		mom[0] = 0;

		forn1(i, n + 1)
		{
			mom[i] = mom[i - 1] + vec[i - 1];
		}

//		print mom;

		ll mm = *max_element(all(mom)) - *min_element(all(mom));

		ll ans = w - mm + 1;
		
		print ans >= 0 ? ans : 0;
	}

};
