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
			vec[i] = { read_ll(), i };
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
		
		ll tgt_i = vec[md.fi].se;
		
		
		sort(all(vec), by(second));

		print vec.size() - (md.se - md.fi);

		
		
		for(int i = tgt_i - 1; i >= 0; i--)
		{
			ll l = vec[i].fi;
			ll r = vec[i + 1].fi;
			
			if(l != r)
			{
				print l < r ? 1 : 2, i + 1, i + 2;
				vec[i].fi = r;
			}
		}

		for(int i = tgt_i + 1; i < vec.size(); i++)
		{
			ll l = vec[i - 1].fi;
			ll r = vec[i].fi;

			if(l != r)
			{
				print l > r ? 1 : 2, i + 1, i;
				vec[i].fi = l;
			}
		}
	}
};
