#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class DTokitsukazeCSLIIgraSKamnyami
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);

		sort(all(vec));

		ll cnt2 = 0;
		ll cnt3 = 0;
		ll pos2 = 0;

		itersameall(vec, {
			if(e - b == 2)
			{
				cnt2++;
				pos2 = b - vec.begin();
			}
			else if(e - b > 2)
				cnt3++;
		});

		if(cnt2 > 1 || cnt3 > 0)
		{
			print "cslnb";
			return;
		}
		
		if(cnt2 == 1)
		{
			if(pos2 > 0 && vec[pos2 - 1] == vec[pos2] - 1)
			{
				print "cslnb";
				return;
			}
		}
		
		ll steps = 0;
		
		forn(i, n)
		{
			if(vec[i] < i)
			{
				print "cslnb";
				return;
			}
			
			steps += vec[i] - i;
		}
		
		print steps % 2 ? "sjfnb" : "cslnb";
	}
};
