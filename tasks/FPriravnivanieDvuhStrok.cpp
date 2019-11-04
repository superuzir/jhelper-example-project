#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"
bool parity(const string& str) {
	bool res = true;
	for (int i = 0; i < str.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (str[i] < str[j]) res ^= 1;
		}
	}
	return res;
}

class FPriravnivanieDvuhStrok
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

			{
				string s1s = s1;
				string s2s = s2;
				soa(s1s);
				soa(s2s);
				if(s1s != s2s)
				{
					print "NO";
					continue;
				}

				bool ok = false;

				itersameall(s1s, {
					if(e - b > 1)
						ok = true;
				});

				if(ok){
					print "YES";
					continue;
				}
			}

			print parity(s1) == parity(s2) ? "YES" : "NO";
		}
	}
};
