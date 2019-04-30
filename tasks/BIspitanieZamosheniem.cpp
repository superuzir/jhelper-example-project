#include <iostream>

#include "../library/lib.hpp"

class BIspitanieZamosheniem
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vs vec = read_vs(n);

		forn1(i, n - 1)
		{
			forn1(j, n - 1)
			{
				char & c = vec[i][j];
				char & t = vec[i - 1][j];
				char & b = vec[i + 1][j];
				char & r = vec[i][j + 1];
				char & l = vec[i][j - 1];

				if(c == '.' &&
						t == '.' &&
						b == '.' &&
						r == '.' &&
						l == '.'
					)
				{
					c = '#';
					t = '#';
					b = '#';
					r = '#';
					l = '#';
				}
			}
		}


		forn(i, n)
		{
			forn(j, n)
			{
				if(vec[i][j] == '.')
				{
					print "NO";
					return;
				}
			}
		}

		print "YES";
	}
};
