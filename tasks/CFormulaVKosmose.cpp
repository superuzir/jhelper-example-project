#include <iostream>

#include "../library/lib.hpp"

class CFormulaVKosmose
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll d = read_ll();
		vll vec = read_vll(n);
		multiset<ll> pts;

		ll rating = vec[d - 1];

		sort(all(vec));

		forn(i, n)
		{
			pts.insert(read_ll());
		}

		{
			auto it = prev(pts.end());

			rating += *it;
			pts.erase(it);
		}

		for(ll i = n - d + 1; i < n; i++)
		{
			ll dif = rating - vec[i];

			auto it = pts.lower_bound(dif);

			if(*it != dif && it != pts.begin())
				it = prev(it);

			vec[i] += *it;

			pts.erase(it);
		}

		print vec.end() - upper_bound(all(vec), rating) + 1;
	}
};
