#include <iostream>

#include "../library/lib.hpp"

class BPari
{
	struct Mer
	{
		vll some;
		ll check;

		bool append(ll a, ll b)
		{
			if(a > b)
				swap(a, b);

			if(some.empty())
			{
				some = {a, b};
				return true;
			}

			if(some.size() == 2)
			{
				if(a == some[0] && b == some[1])
					return true;

				if(a == some[check])
					some = {a};
				else if(b == some[check])
					some = {b};
				else
					return false;

				return true;
			}
			else
			{
				if(a == some[0] || b == some[0])
					return true;
				else
					return false;
			}
		}
	};

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();

		vpll vec;

		forn(i, m)
		{
			vec.pb(read_pll());
		}

		if( getBoolean(m, vec, 0, 0) ||
			getBoolean(m, vec, 0, 1) ||
			getBoolean(m, vec, 1, 0) ||
			getBoolean(m, vec, 1, 1))
			print "YES";
		else
			print "NO";
	}

	bool getBoolean(ll m, const vpll &vec, int c1, int c2) const
	{
		Mer m1, m2;

		m1.check = c1;
		m2.check = c2;

		forr(v, vec)
		{
			if (!m1.append(v.fi, v.se) && !m2.append(v.fi, v.se))
			{
				return false;
			}
		}
		
		return true;
	}
};
