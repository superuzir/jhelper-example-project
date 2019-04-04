#include <iostream>

#include "../library/lib.hpp"

class BProidenniiPut
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll v1 = read_ll();
		ll v2 = read_ll();
		ll t = read_ll();
		ll d = read_ll();

		vll vel(t);

		forn(i, t)
			vel[i] = min(v1 + d * i, v2 + d * (t - i - 1));

		print accumulate(all(vel), 0);
	}
};
