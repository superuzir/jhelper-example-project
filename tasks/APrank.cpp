#include <iostream>

#include "../library/lib.hpp"

class APrank
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);

		vll used(1002, 0);
		vll used2(1002, 0);

		forn(i, n)
			used[vec[i]] = 1;

		used[0] = 1;
		used[1001] = 1;

		forn1(i, used.size() - 1)
			used2[i] = used[i - 1] && used[i] && used[i + 1];

		ll ans = 0;

		itersame(all(used2), [&](auto b, auto e)
		{
			if(*b == 1)
				ans = max(ans, ll(e - b));
		});

		print ans;
	}
};
