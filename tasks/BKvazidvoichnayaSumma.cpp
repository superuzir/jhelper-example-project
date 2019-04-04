#include <iostream>

#include "../library/lib.hpp"

class BKvazidvoichnayaSumma
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		auto str = read_s();

		auto n = accumulate(all(str), 0, [](int m, char c){ return max(m, c - '0'); });

		print n;

		forn(i, n)
		{
			string num;

			forn(j, str.size())
			{
				if(str[j] != '0')
				{
					num += '1';
					str[j]--;
				}
				else if(num.size())
				{
					num += '0';
				}
			}

			out << num << " ";
		}
	}
};
