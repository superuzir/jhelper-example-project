#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class ATihiiKlass
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vs vec = read_vs(n);

		sort(all(vec));

		ll ans = 0;

		itersame(all(vec), [&](auto b, auto e){
			ll c = e - b;

			ll c1 = c / 2;
			ll c2 = c1;
			
			if(c % 2)
				c2++;

			ans += c1 * (c1 - 1) / 2;
			ans += c2 * (c2 - 1) / 2;
		}, [](auto a, auto b){ return a[0] == b[0]; });

		print ans;
	}
};
