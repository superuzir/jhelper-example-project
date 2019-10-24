#include <iostream>

#include "../library/lib.hpp"

class BDvoichniePalindromi
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			ll n = read_ll();
			auto vs = read_vs(n);

			ll c0 = 0;
			ll c1 = 0;
			ll codd = 0;

			forr(s, vs){
				c0 += count(all(s), '0');
				c1 += count(all(s), '1');
				codd += s.size() % 2;
			}
			
			if(codd == 0){
				if(c0 % 2)
					print n - 1;
				else
					print n;
			}
			else if(codd % 2)
			{
				print n;
			}
			else
			{
				if(c0 % 2 && c1 % 2)
					print n;
				else if(c0 % 2 == 0 && c1 % 2 == 0)
					print n;
				else
					print n - 1;
			}
		}
	}
};
