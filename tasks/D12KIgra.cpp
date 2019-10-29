#include <iostream>

#include "../library/lib.hpp"

class D12KIgra
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			ll n = read_ll();
			ll k = read_ll();

			if(k == n)
			{
				print "Alice";
			}
			else
			{
				if(k % 3){
					if((n + 1) % 3 == 1)
						print "Bob";
					else
						print "Alice";
				} else {
					ll ost = (n + 1) % (k + 1);
					
					if(ost == 0)
						print "Alice";
					else if(ost % 3 == 1)
						print "Bob";
					else
						print "Alice";
				}
			}
		}
	}
};
