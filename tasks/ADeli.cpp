#include <iostream>

#include "../library/lib.hpp"

class ADeli
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();
		
		forn(i, q)
		{
			ll n = read_ll();
			
			ll ans = 0;
			
			while(n > 1)
			{
				if (n % 2 == 0)
					n /= 2;
				else if(n % 3 == 0)
					n = n * 2 / 3;
				else if(n % 5 == 0)
					n = n * 4 / 5;
				else
				{
					ans = -1;
					break;
				}
				
				ans++;
			}
			
			print ans;
		}
	}
};
