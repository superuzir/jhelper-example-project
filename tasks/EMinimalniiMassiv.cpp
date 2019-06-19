#include <iostream>

#include "../library/lib.hpp"

class EMinimalniiMassiv
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll a = read_vll(n);
		vll b = read_vll(n);

		multiset<ll> set;

		forn(i, n)
		{
			set.insert(b[i]);
		}

		forn(i, n)
		{
			auto it = set.lower_bound(n - a[i]);
			if(it == set.end())
				it = set.begin();
			
			out << (a[i] + *it) % n << " ";
			
			set.erase(it);
		}
		
		out << endl;
	}
};
