#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class ASlomannayaKlaviatura
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		forn(_, n)
		{
			auto s = read_s();
			
			set<char> ans;
			
			itersameall(s, {
				if((e-b) % 2 == 1)
					ans.insert(*b);
			});

			forr(c, ans)
			{
				out << c;
			}
			
			out << endl;
		}
	}
};
