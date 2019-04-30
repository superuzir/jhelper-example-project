#include <iostream>

#include "../library/lib.hpp"

class AIgraNaTablice
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		string str = read_s();

		ll vertpos = 1;
		ll horzpos = 1;

		forr(c, str)
		{
			if(c == '0')
			{
				print vertpos, 1;
				vertpos += 2;
				if(vertpos > 4)
					vertpos = 1;
			}
			else
			{
				print horzpos, 3;
				horzpos++;
				if(horzpos > 4)
					horzpos = 1;
			}
		}
	}
};
