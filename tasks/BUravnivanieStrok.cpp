#include <iostream>

#include "../library/lib.hpp"

class BUravnivanieStrok
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll __q = read_ll();

		forn(_, __q){
			auto t1 = read_s();
			auto t2 = read_s();

			set<char> s1(all(t1));
			set<char> s2(all(t2));

			set<int> intersect;
			set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(), std::inserter(intersect,intersect.begin()));

			print intersect.empty() ? "NO" : "YES";
		}
	}
};
