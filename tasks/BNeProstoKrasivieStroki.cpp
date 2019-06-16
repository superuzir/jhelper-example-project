#include <iostream>

#include "../library/lib.hpp"

class BNeProstoKrasivieStroki
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		string str = read_s();

		map<char, ll> map;

		forr(c, str)
		{
			map[c]++;
		}

		if(map.size() < 2 || map.size() > 4)
		{
			print "No";
			return;
		}

		if(map.size() == 2)
		{
			auto it = map.begin();

			auto a1 = *it++;
			auto a2 = *it++;

			print a1.se < 2 || a2.se < 2 ? "No" : "Yes";
		}
		else if(map.size() == 3)
		{
			auto it = map.begin();

			auto a1 = *it++;
			auto a2 = *it++;
			auto a3 = *it++;

			print a1.se < 2 && a2.se < 2 && a3.se < 2 ? "No" : "Yes";
		}
		else
		{
			print "Yes";
		}
	}
};
