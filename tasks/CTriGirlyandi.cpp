#include <iostream>

#include "../library/lib.hpp"

class CTriGirlyandi
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		vll k = read_vll(3);

		sort(all(k));

		if(k[0] == 1
		|| (k[0] == 2 && k[1] == 2)
		|| (k[0] == 2 && k[1] == 4 && k[2] == 4)
		|| (k[0] == 3 && k[1] == 3 && k[2] == 3)
		)
		{
			print "YES";
		}
		else
		{
			print "NO";
		}

	}
};
