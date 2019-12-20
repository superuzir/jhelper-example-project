#include <iostream>

#include "../library/lib.hpp"

class ASportivniiProgrammist
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();

		forn(_, t){
			auto s = read_s();

			ll c0 = 0;
			ll e = 0;
			ll sum = 0;
			
			forr(ss, s){
				if(ss == '0')
					c0++;
				
				if((ss - '0') % 2 == 0)
					e++;
				
				sum += ss - '0';
			}
			
			if(sum % 3 == 0 && c0 && e >= 2)
				print "red";
			else
				print "cyan";
		}

	}
};
