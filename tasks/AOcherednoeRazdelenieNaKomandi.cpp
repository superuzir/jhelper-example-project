#include <iostream>

#include "../library/lib.hpp"

class AOcherednoeRazdelenieNaKomandi
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();
		forn(_, q)
		{
			ll n = read_ll();
			auto vec = read_vll(n);

			sort(all(vec));

			ll mn = max_ll;

			forn1(i, n){
				mn = min(vec[i] - vec[i - 1], mn);
			}

			if(mn <= 1)
				print 2;
			else
				print 1;
		}
	}
};
