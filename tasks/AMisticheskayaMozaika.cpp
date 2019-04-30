#include <iostream>

#include "../library/lib.hpp"

class AMisticheskayaMozaika
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		vs vec = read_vs(n);

		forn(i, n)
		{
			string line = vec[i];

			vll used;

			forn(j, m)
				if(line[j] == '#')
					used.pb(j);

//			print used;
			
			for(ll i2 = 0; i2 < n; i2++)
			{
				string line = vec[i2];

				ll count = count_if(all(used), [&](ll idx){ return line[idx] == '#'; });
				
//				print line, count;
				
				if(count != 0 && count != used.size())
				{
					print "No";
					return;
				}
			}
		}

		print "Yes";
	}
};
