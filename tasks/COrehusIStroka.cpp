#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"

class COrehusIStroka
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		string s1 = read_s();

		string s;

		forr(c, s1)
			if(c == 'a' || c == 'b')
				s += c;

		ll ans = 1;

		itersameall(s, {
			if(*b == 'a')
			{
				ans *= (e - b) + 1;
				ans %= MOD;
			}
		});

		ans--;

		if(ans < 0)
			ans += MOD;

		print ans;
	}
};
