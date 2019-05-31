#include <iostream>

#include "../library/lib.hpp"

class BKostyumSGalstukom
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = 2 * read_ll();
		vll vec = read_vll(n);

		ll ans = 0;

		forn(i, n)
		{
			for(int j = i + 1; j < n; ++j)
			{
				if(vec[i] == vec[j])
				{
					vec.erase(vec.begin() + j);
					vec.insert(vec.begin() + i + 1, vec[i]);
					ans += j - (i + 1);
					break;
				}
			}
		}

		print ans;
	}
};
