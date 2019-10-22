#include <iostream>

#include "../library/lib.hpp"

class ENaLifteIliPoLestnice
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll c = read_ll();
		auto les = read_vll(n - 1);
		auto lif = read_vll(n - 1);
		
		vll cles(n);
		vll clif(n, c);
		vll ans(n);
		
		forn1(i, n)
		{
			cles[i] = min(cles[i - 1] + les[i - 1] + 0, clif[i - 1] + les[i - 1] + 0);
			clif[i] = min(cles[i - 1] + lif[i - 1] + c, clif[i - 1] + lif[i - 1] + 0);
			ans[i] = min(cles[i], clif[i]);
		}
		
//		print cles;
//		print clif;
		
		answer(ans, out);
	}
};
