#include <iostream>

#include "../library/lib.hpp"

class B1ObmenSimvolovUproshennayaVersiya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();
		forn(_, q)
		{
			ll n = read_ll();
			auto s1 = read_s();
			auto s2 = read_s();

			vs r;
			
			forn(i, n){
				if(s1[i] != s2[i])
				{
					string s;
					s += s1[i];
					s += s2[i];
					r.pb(s);
				}
				
				if(r.size() > 2)
					break;
			}
			
			if(r.size() == 2 && r[0] == r[1])
			{
				print "Yes";
			}
			else
			{
				print "No";
			}
		}
	}
};
