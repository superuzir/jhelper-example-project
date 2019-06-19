#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class BPismoOtPolikarpa
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		
		forn(i, n)
		{
			auto s1 = read_s();
			auto s2 = read_s();
			
			vector<pair<char, ll> > v1, v2;
			
			itersameall(s1, { v1.pb({*b, e - b}); });
			itersameall(s2, { v2.pb({*b, e - b}); });
			
//			print v1;
//			print v2;
			
			if(v1.size() != v2.size())
			{
				print "NO";
			}
			else
			{
				bool ok = true;
				
				forn(i, v1.size())
				{
					if(v1[i].fi != v2[i].fi || v1[i].se > v2[i].se)
					{
						ok = false;
						print "NO";
						break;
					}
				}
				
				if(ok)
					print "YES";
			}
		}
	}
};
