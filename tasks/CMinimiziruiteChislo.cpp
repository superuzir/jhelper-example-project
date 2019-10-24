#include <iostream>

#include "../library/lib.hpp"

class CMinimiziruiteChislo
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();
		forn(_, q) {
			auto s = read_s();

			string s0, s1;

			forr(c, s) {
				if(c % 2 == 0)
					s0 += c;
				else
					s1 += c;
			}

//			print s0, s1;

			ll c0 = 0;
			ll c1 = 0;

			string ans;

			while(c0 < s0.size() || c1 < s1.size()) {
				if(c0 < s0.size() && c1 < s1.size())
				{
					if(s0[c0] < s1[c1])
						ans += s0[c0++];
					else
						ans += s1[c1++];
				}
				else if(c0 < s0.size())
					ans += s0[c0++];
				else
					ans += s1[c1++];
			}

			print ans;
		}
	}
};
