#include <iostream>

#include "../library/lib.hpp"

class BCirk
{
public:

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto sc = read_s();
		auto sa = read_s();

		ll na = 0;
		ll nb = 0;
		ll nc = 0;
		ll nd = 0;

		forn(i, n)
		{
			if(sc[i] == '1' && sa[i] == '1') na++;
			if(sc[i] == '1' && sa[i] == '0') nb++;
			if(sc[i] == '0' && sa[i] == '1') nc++;
			if(sc[i] == '0' && sa[i] == '0') nd++;
		}

		forn(a, na + 1)
		forn(b, nb + 1)
		{
			ll c = na + nc - 2 * a - b;
			ll d = n / 2 - a - b - c;

			if(c >= 0 && d >= 0 && c <= nc && d <= nd)
			{
				forn(i, n)
				{
					if(sc[i] == '1' && sa[i] == '1') { if(a){ a--; out << i + 1 << " "; } }
					if(sc[i] == '1' && sa[i] == '0') { if(b){ b--; out << i + 1 << " "; } }
					if(sc[i] == '0' && sa[i] == '1') { if(c){ c--; out << i + 1 << " "; } }
					if(sc[i] == '0' && sa[i] == '0') { if(d){ d--; out << i + 1 << " "; } }
				}

				out << endl;

				return;
			}
		}

		print -1;
	}
};
