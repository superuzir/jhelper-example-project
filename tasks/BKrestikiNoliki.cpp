#include <iostream>

#include "../library/lib.hpp"

class BKrestikiNoliki
{
	void sign(string & s)
	{
		forr(c, s)
		{
			if(c == '.')
				c = '!';
		}
	}
	
public:
	void solve(std::istream& in, std::ostream& out)
	{
		vs pole = read_vs(27);
		ll x = (read_ll() - 1) % 3;
		ll y = (read_ll() - 1) % 3;

		bool found = false;

		forn(i, 3)
		{
			ll idx = 9 * x + y + i * 3;
			if(pole[idx].find('.') != string::npos)
			{
				forn(i, 3)
				{
					ll idx = 9 * x + y + i * 3;
					sign(pole[idx]);
				}

				found = true;

				break;
			}
		}
		
		if(!found)
			forn(i, 27) 
				sign(pole[i]);
		
		forn(i, 27)
		{
			out << pole[i] << " ";
			if(i % 3 == 2)
				out << "\n";
			if(i % 9 == 8)
				out << "\n";
		}
	}
};
