#include <iostream>

#include "../library/lib.hpp"

class DPolikarpIDiv3
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		string str = read_s();

		ll ans = 0;
		ll b = 0;
		forn(i, str.size())
		{
			if(str[i] == '0'
			|| str[i] == '3'
			|| str[i] == '6'
			|| str[i] == '9')
			{
				ans++;
				b = i + 1;
				continue;
			}

			for(ll j = i - 1; j >= b; j--)
			{
				string cand = str.substr(j, i - j + 1);

				if(stoll(cand) % 3 == 0)
				{
					ans++;
					b = i + 1;
					break;
				}
			}
		}

		print ans;
	}
};
