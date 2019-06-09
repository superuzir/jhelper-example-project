#include <iostream>

#include "../library/lib.hpp"

class DDvuhcvetnayaPSP
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		string s = read_s();

		ll d = 0;

		forr(c, s)
		{
			if(c == '(')
			{
				out << d % 2;
				d++;
			}
			else
			{
				d--;
				out << d % 2;
			}
		}

		out << endl;
	}
};
