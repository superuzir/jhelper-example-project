#include <iostream>

#include "../library/lib.hpp"

class BSdelaiRavnimi
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);

		sort(all(vec));

		ll least = vec[0];

		forn(i, n)
		{
			vec[i] -= least;
		}

		vll allowed;

		if(vec.back() % 2 == 0)
		{
			allowed = {0, vec.back() / 2, vec.back()};
		}
		else
		{
			allowed = {0, vec.back()};
		}

		forn(i, n)
		{
			if(find(all(allowed), vec[i]) == allowed.end())
			{
				print -1;
				return;
			}
		}
		
		if(allowed.size() <= 2)
			print allowed.back();
		else
			print allowed.back() / 2;
	}
};
