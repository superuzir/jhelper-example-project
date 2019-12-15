#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class BAzamonWebServices
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();

		forn(_, t)
		{
			auto a = read_s();
			auto b = read_s();

			if(a < b)
			{
				print a;
				continue;
			}

			string sa = a;

			soa(sa);

			forn(i, a.size()){
				if(a[i] != sa[i]){
					auto it = find(rall(a), sa[i]);
					swap(a[i], *it);
					break;
				}
			}

			if(a < b)
				print a;
			else
				print "---";
		}
	}
};
