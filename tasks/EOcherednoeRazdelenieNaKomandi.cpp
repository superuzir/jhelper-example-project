#include <iostream>

#include "../library/lib.hpp"

class EOcherednoeRazdelenieNaKomandi
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto v = read_vll(n);

		soa(v);

		forn1(i, n){
			dbg(i, v[i] - v[i - 1]);
		}
	}
};
