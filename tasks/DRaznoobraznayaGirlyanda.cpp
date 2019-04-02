#include <iostream>

#include "../library/lib.hpp"

class DRaznoobraznayaGirlyanda
{
	char rotate(char c)
	{
		switch(c)
		{
			case 'R':
				return 'G';
			case 'G':
				return 'B';
			case 'B':
				return 'R';
			default:
				return '-';
		}
	}

	char other(char a, char b)
	{
		if(a != 'R' && b != 'R') return 'R';
		if(a != 'G' && b != 'G') return 'G';
		if(a != 'B' && b != 'B') return 'B';
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto str = read_s();

		ll steps = 0;
		
		if(n == 1)
		{
		}
		else if(n == 2)
		{
			if(str[0] == str[1])
			{
				str[1] = rotate(str[1]);
				steps++;
			}
		}
		else
		{
			forn(i, n - 2)
			{
				if(str[i] == str[i+1])
				{
					str[i+1] = other(str[i], str[i+2]);
					steps++;
				}
			}
			
			if(str[n-2] == str[n-1])
			{
				str[n-1] = other(str[n-2], str[n-2]);
				steps++;
			}
		}

		print steps;
		print str;
	}
};
