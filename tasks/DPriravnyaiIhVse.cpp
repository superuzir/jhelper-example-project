#include <iostream>

#include "../library/lib.hpp"

class DPriravnyaiIhVse
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vpll vec(n);
		
		forn(i, n)
		{
			vec[i] = { read_ll(), i + 1 };
		}
		
		sort(all(vec));

		auto md = make_pair(0, 0);
		
		for(auto b = 0, e = 0; e < vec.size();)
		{
			e = find_if(vec.begin() + e, vec.end(), [&](pll pr){ return pr.first != vec[b].first; }) - vec.begin();
			
			auto dist = e - b;
			
			if(e - b > md.se - md.fi)
				md = {b, e};
			
			b = e;
		}

		print vec.size() - (md.se - md.fi);

		nfor(i, md.fi)
		{
			print 1, vec[i].second, vec[i + 1].second;
		}

		for(int i = md.se; i < vec.size(); i++)
		{
			print 2, vec[i].second, vec[i - 1].second;
		}
	}
};
