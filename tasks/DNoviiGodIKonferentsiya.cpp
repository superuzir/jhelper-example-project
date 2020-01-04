#include <iostream>

#include "../library/lib.hpp"

class DNoviiGodIKonferentsiya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		vpll p1;
		vpll p2;

		forn(i, n){
			{
				ll s = read_ll();
				ll e = read_ll();
				p1.pb({s, e});
			}

			{
				ll s = read_ll();
				ll e = read_ll();
				p2.pb({s, e});
			}
		}

		soa(p1);
		soa(p2);

		vvll t1;
		vvll t2;

		forn(i, n){
			t1.pb({p1[i].fi, 1, i});
			t1.pb({p1[i].se, 2, i});
			t2.pb({p2[i].fi, 1, i});
			t2.pb({p2[i].se, 2, i});
		}

		soa(t1);
		soa(t2);

//		dbg(t1);
//		dbg(t2);

		forn(i, 2 * n){
			if(t1[i][1] != t2[i][1] || t1[i][2] != t2[i][2]){
				print "NO";
				return;
			}
		}

		print "YES";
	}
};
