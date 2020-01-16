#include <iostream>

#include "../library/lib.hpp"

class BAnyaIMinimizatsiya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
//		ll __q = read_ll();
		ll __q = 1;

		forn(_, __q){
			ll n = read_ll();
			ll k = read_ll();

			auto s = read_s();

			auto set = [&](char & c, char d){
				if(k && c != d) {
					c = d;
					k--;
				}
			};

			forr(c, s){
				if(&c == &s[0])
					set(c, s.size() > 1 ? '1' : '0');
				else
					set(c, '0');
			}

			print s;
		}
	}
};
