#include <iostream>

#include "../library/lib.hpp"

class CSoedinit
{
	vs vec;

	void useCell(ll row, ll col, vpll & ans, bool recurse = true)
	{
		if(row < 0 || col < 0 || row >= vec.size() || col >= vec[0].size())
			return;

		if(vec[row][col] != '0')
			return;

		vec[row][col] = 'u';

		ans.pb({row, col});

		if(recurse)
			land(row, col, ans);
	}

	void land(ll row, ll col, vpll & ans)
	{
		useCell(row, col, ans, false);
		useCell(row - 1, col, ans);
		useCell(row + 1, col, ans);
		useCell(row, col - 1, ans);
		useCell(row, col + 1, ans);
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll r1 = read_ll() - 1;
		ll c1 = read_ll() - 1;
		ll r2 = read_ll() - 1;
		ll c2 = read_ll() - 1;
		vec = read_vs(n);

		vpll src;
		land(r1, c1, src);
		
		vpll dst;
		land(r2, c2, dst);
		
		if(dst.empty())
		{
			print 0;
			return;
		}

		ll ans = max_ll;
		
		forr(s, src)
		forr(d, dst)
		{
			ll dfi = d.fi - s.fi;
			ll dse = d.se - s.se;
			
			ll cost = dfi * dfi + dse * dse;
			
			ans = min(ans, cost);
		}
		
		print ans;
	}
};
