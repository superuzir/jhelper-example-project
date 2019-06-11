#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class BPlyusIzRisunka
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll h = read_ll();
		ll w = read_ll();

		vs s = read_vs(h);

		ll xc = -1;
		ll yc = -1;

		forn1(y, h - 1)
		forn1(x, w - 1)
		{
			if(s[y - 1].substr(x - 1, 3) == ".*." &&
			   s[y - 0].substr(x - 1, 3) == "***" &&
			   s[y + 1].substr(x - 1, 3) == ".*.")
			{
				xc = x;
				yc = y;
			}
		}

		if(xc < 0 || yc < 0)
		{
			print "NO";
			return;
		}

		ll stars = -1;

		{
			string str = s[yc];

			ll k = 0;

			itersameall(str, {
				if(*b == '*'){
					stars += e - b;
					k++;
				}
			});

			if(k != 1)
			{
				print "NO";
				return;
			}
		}

		{
			string str;

			forn(i, h)
			{
				str += s[i][xc];
			}

			ll k = 0;

			itersameall(str, {
				if(*b == '*'){
					stars += e - b;
					k++;
				}
			});

			if(k != 1)
			{
				print "NO";
				return;
			}
		}

		ll stars2 = 0;

		forn(i, h)
		{
			stars2 += count(all(s[i]), '*');
		}



		if(stars == stars2)
			print "YES";
		else
			print "NO";
	}
};
