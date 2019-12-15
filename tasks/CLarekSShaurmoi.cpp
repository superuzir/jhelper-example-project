#include <iostream>

#include "../library/lib.hpp"

class CLarekSShaurmoi
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll sx = read_ll();
		ll sy = read_ll();
		auto v = read_vpll(n);

		ll ans = 0;
		pll coord;

		{
			ll anscand = 0;
			pll coordcand = {sx - 1, sy};

			forr(p, v)
			{
				if (p.fi <= coordcand.fi)
				{
					anscand++;
				}
			}

			if(anscand > ans){
				ans = anscand;
				coord = coordcand;
			}
		}

		{
			ll anscand = 0;
			pll coordcand = {sx + 1, sy};

			forr(p, v)
			{
				if (p.fi >= coordcand.fi)
				{
					anscand++;
				}
			}

			if(anscand > ans){
				ans = anscand;
				coord = coordcand;
			}
		}

		{
			ll anscand = 0;
			pll coordcand = {sx, sy - 1};

			forr(p, v)
			{
				if (p.se <= coordcand.se)
				{
					anscand++;
				}
			}

			if(anscand > ans){
				ans = anscand;
				coord = coordcand;
			}
		}

		{
			ll anscand = 0;
			pll coordcand = {sx, sy + 1};

			forr(p, v)
			{
				if (p.se >= coordcand.se)
				{
					anscand++;
				}
			}

			if(anscand > ans){
				ans = anscand;
				coord = coordcand;
			}
		}

		print ans;
		print coord.fi, coord.se;
	}
};
