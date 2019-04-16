#include <iostream>

#include "../library/lib.hpp"

class DIdushiiRobot
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll b = read_ll();
		ll a = read_ll();
		ll a_max = a;
		vll vec = read_vll(n);
		
		forn(i, n)
		{
			if(a == 0 && b == 0)
			{
				print i;
				return;
			}
			
			if(vec[i] == 1)
			{
				if(b > 0)
				{
					if(a == a_max)
					{
						a--;
					}
					else
					{
						a++;
						b--;
					}
				}
				else
				{
					a--;
				}
			}
			else
			{
				if (a > 0)
				{
					a--;
				}
				else
				{
					b--;
				}
			}
		}
		
		print n;
	}
};
