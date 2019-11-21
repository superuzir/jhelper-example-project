#include <iostream>

#include "../library/lib.hpp"

class CMagicheskayaTablitsa
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		ll a = 0;

		forn(i, n / 2)
		{
			forn(j, n)
			{
				out << a << ' ';
				a += 2;
			}

			out << '\n';
		}

		a = 1;

		forn(i, n / 2)
		{
			forn(j, n)
			{
				out << a << ' ';
				a += 2;
			}

			out << '\n';
		}
	}
};
