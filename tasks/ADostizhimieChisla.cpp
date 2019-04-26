#include <iostream>

#include "../library/lib.hpp"

class ADostizhimieChisla
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		set<ll> ans;

		ans.insert(n);

		while(1)
		{
			n++;

			while(n % 10 == 0)
				n /= 10;

			if(ans.find(n) != ans.end())
				break;
			else
				ans.insert(n);
		}

		print ans.size();
	}
};
