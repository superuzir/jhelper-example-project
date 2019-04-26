#include <iostream>

#include "../library/lib.hpp"

class BDlinnoeChislo
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		string str = read_s();
		vll fun = read_vll(9);

		bool began = false;
		
		forr(c, str)
		{
			ll ci = c - '0';
			
			if(fun[ci - 1] > ci)
			{
				c = fun[ci - 1] + '0';
				began = true;
			}
			else if(began && fun[ci - 1] == ci)
			{
			}
			else if(began)
			{
				break;
			}
		}
		
		print str;
	}
};
