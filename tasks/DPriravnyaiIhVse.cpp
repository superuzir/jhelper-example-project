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

		itersame(all(vec), [&](auto b, auto e)
		{
			if(e - b > md.se - md.fi)
				md = {b - vec.begin(), e - vec.begin()};
		}, eq(fi));
		
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
