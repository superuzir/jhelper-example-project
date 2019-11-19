#include <iostream>

#include "../library/lib.hpp"

class BTolikIDyadya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();

		forn(i, n / 2)
		forn(j, m){
			print i + 1, j + 1;
			print n - i, m - j;
		}

		if(n % 2){
			forn(j, m)
				print n / 2 + 1, j % 2 == 0 ? j / 2 + 1 : m - j / 2;
		}
	}
};
