#include <iostream>

#include "../library/lib.hpp"

class BMinimalnoeChisloShagov
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		string str = read_s();

		ll bcount = 0;
		ll ans = 0;

		nfor(i, str.size())
		{
			if(str[i] == 'b')
				bcount++;
			else
			{
				ans += bcount;
				bcount *= 2;
			}

			ans %= MOD;
			bcount %= MOD;
		}

		print ans;
	}
};
