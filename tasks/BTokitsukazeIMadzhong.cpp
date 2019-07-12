#include <iostream>

#include "../library/lib.hpp"

class BTokitsukazeIMadzhong
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		auto vs = read_vs(3);

		sort(all(vs));

		if(vs[0] == vs[1])
		{
			print vs[1] == vs[2] ? 0 : 1;
			return;
		}
		else if(vs[1] == vs[2])
		{
			print 1;
			return;
		}

		if(vs[0][0] + 1 == vs[1][0] && vs[0][1] == vs[1][1])
		{
			print (vs[1][0] + 1 == vs[2][0] && vs[1][1] == vs[2][1]) ? 0 : 1;
			return;
		}
		else if(vs[1][0] + 1 == vs[2][0] && vs[1][1] == vs[2][1])
		{
			print 1;
			return;
		}

		if(vs[0][0] + 2 == vs[1][0] && vs[0][1] == vs[1][1])
		{
			print 1;
			return;
		}
		else if(vs[1][0] + 2 == vs[2][0] && vs[1][1] == vs[2][1])
		{
			print 1;
			return;
		}
		
		print 2;
	}
};
