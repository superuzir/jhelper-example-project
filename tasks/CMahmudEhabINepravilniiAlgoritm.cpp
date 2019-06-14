#include <iostream>

#include "../library/lib.hpp"

class CMahmudEhabINepravilniiAlgoritm
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		if(n < 6)
		{
			print -1;
		}
		else
		{
			forlr(i, 2, 5)
				print 1, i;

			forlr(i, 5, n + 1)
				print 2, i;
		}

		forn1(i, n)
			print 1, i + 1;
	}
};
