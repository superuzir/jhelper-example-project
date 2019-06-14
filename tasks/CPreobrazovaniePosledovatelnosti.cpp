#include <iostream>

#include "../library/lib.hpp"

class CPreobrazovaniePosledovatelnosti
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		if(n <= 3)
		{
			forn1(i, n)
				out << 1 << " ";

			out << n << endl;
		}
		else
		{
			ll ans = 1;

			while(n)
			{
				if(n == 3)
				{
					out << ans << " " << ans << " " << 3 * ans << endl;
					break;
				}
				
				forn(i, n - n / 2)
					out << ans << " ";

				n /= 2;

				ans *= 2;
			}

			out << endl;
		}
	}
};
