#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class COcherednayaSlomannayaKlaviatura
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();
		auto s = read_s();

		set<char> set;

		forn(i, k){
			set.insert(read<char>(in));
		}

		ll ans = 0;
		itersame(all(s),
			[&](auto b, auto e) { if(set.count(*b)) { ll m = e - b; ans += m * (m + 1) / 2; } },
			[&](auto a, auto b) { return set.count(a) == set.count(b); });

		print ans;
	}
};
