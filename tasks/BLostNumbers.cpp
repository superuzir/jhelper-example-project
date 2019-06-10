#include <iostream>

#include "../library/lib.hpp"

class BLostNumbers
{
	vll t = {4, 8, 15, 16, 23, 42};

	pll unmul(ll mul)
	{
		forn(i, 6)
		forlr(j, i + 1, 6)
		{
			if(t[i] * t[j] == mul)
				return {t[i], t[j]};
		}
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		out << "? 1 2" << endl; ll m1 = read_ll();
		out << "? 3 2" << endl; ll m2 = read_ll();
		out << "? 4 5" << endl; ll m3 = read_ll();
		out << "? 6 5" << endl; ll m4 = read_ll();

		pll p1 = unmul(m1);
		pll p2 = unmul(m2);

		out << "! ";

		if     (p1.fi == p2.fi) out << p1.se << " " << p1.fi << " " << p2.se;
		else if(p1.fi == p2.se) out << p1.se << " " << p1.fi << " " << p2.fi;
		else if(p1.se == p2.fi) out << p1.fi << " " << p1.se << " " << p2.se;
		else if(p1.se == p2.se) out << p1.fi << " " << p1.se << " " << p2.fi;

		p1 = unmul(m3);
		p2 = unmul(m4);

		out << " ";

		if     (p1.fi == p2.fi) out << p1.se << " " << p1.fi << " " << p2.se;
		else if(p1.fi == p2.se) out << p1.se << " " << p1.fi << " " << p2.fi;
		else if(p1.se == p2.fi) out << p1.fi << " " << p1.se << " " << p2.se;
		else if(p1.se == p2.se) out << p1.fi << " " << p1.se << " " << p2.fi;

		out << endl;
	}
};
