#include <iostream>

#include "../library/lib.hpp"

class CKotikGurman
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll a = read_ll();
		ll b = read_ll();
		ll c = read_ll();
		
		ll weeks = min3(a / 3, b / 2, c / 2);
		
		a -= weeks * 3;
		b -= weeks * 2;
		c -= weeks * 2;
		
		string korm("abcacba");
		korm += korm;
		
		ll max_days = 0;
		
		forn(i, korm.size())
		{
			ll days = 0;
			ll a1 = a, b1 = b, c1 = c;
			
			for (int j = i; j < korm.size(); ++j)
			{
				if(korm[j] == 'a')
				{
					if(a1 == 0)
						break;
					else
						a1--;
				}
				
				if(korm[j] == 'b')
				{
					if(b1 == 0)
						break;
					else
						b1--;
				}
				
				if(korm[j] == 'c')
				{
					if(c1 == 0)
						break;
					else
						c1--;
				}

				days++;
			}
			
			max_days = max(days, max_days);
		}
		
		print weeks * 7 + max_days;
	}
};
