#include <iostream>

#include "../library/lib.hpp"

class C2HoroshieChislaSlozhnayaVersiya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		vll v;

		for(ll st = 1; st < 1000ll*1000*1000*1000*1000*1000*3; st *= 3) {
			v.pb(st);
		}

//		print v;

		ll q = read_ll();
		forn(_,  q){
			ll n = read_ll();

			ll ans = 0;

			while(n > 0)
			{
				auto it = lower_bound(all(v), n);

				if(n > (*it) / 2)
				{
					ans += *it;
					break;
				}

				if(*it == n)
				{
					ans += *it;
					break;
				}

				n -= *(it - 1);
				ans += *(it - 1);
			}

			print ans;
//			print "next";
		}
	}
};
