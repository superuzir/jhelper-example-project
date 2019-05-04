#include <iostream>

#include "../library/lib.hpp"

class AMashaIMedvedi
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		vll vec = read_vll(4);

		pll med = { vec[2], 2 * vec[2] };
		pll mas = { vec[3], 2 * vec[3] };

		if(med.fi > mas.se || med.se < mas.fi)
			print -1;
		else
		{
			ll veh = max(med.fi, mas.fi);
			
			ll bolveh = max(mas.se + 1, vec[0]);
			ll sreveh = max(mas.se + 1, vec[1]);
			
			if(bolveh == sreveh)
				bolveh++;
			
			if(bolveh > vec[0] * 2)
			{
				print -1;
				return;
			}
			
			if(sreveh > vec[1] * 2)
			{
				print -1;
				return;
			}
			
			print bolveh;
			print sreveh;
			print veh;
		}

	}
};
