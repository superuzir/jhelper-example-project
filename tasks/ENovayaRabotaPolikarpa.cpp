#include <iostream>

#include "../library/lib.hpp"

class ENovayaRabotaPolikarpa
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		pll sz;

		forn(i, n)
		{
			char type; in >> type; 

			pll b = read_pll();
			if(b.se < b.fi)
				swap(b.se, b.fi);

			if(type == '+')
				sz = {max(sz.fi, b.fi), max(sz.se, b.se)};

			if(type == '?')
				print b.fi < sz.fi || b.se < sz.se ? "NO" : "YES";
		}
	}
};
