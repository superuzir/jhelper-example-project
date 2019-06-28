#include <iostream>

#include "../library/lib.hpp"

class ANeboskrebi
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();

		vector<vpll> byrow(n, vpll(m));
		vector<vpll> bycol(m, vpll(n));
		
		vll maxrow(n);
		vll maxcol(m);

		forn(i, n)
		forn(j, m)
		{
			ll v = read_ll();
			byrow[i][j] = {v, j};
			bycol[j][i] = {v, i};
		}
		
		auto byrow2 = byrow;
		auto bycol2 = bycol;

		forn(i, n)
		{
			sort(all(byrow[i]));
			sort(all(byrow2[i]));

			ll v = 1;

			forn(j, m)
			{
				if(j && byrow[i][j].fi != byrow[i][j - 1].fi)
					v++;

				byrow2[i][j].fi = v;
				maxrow[i] = max(maxrow[i], v);
			}
			sort(all(byrow2[i]), by(se));
		}

		forn(i, m)
		{
			sort(all(bycol[i]));
			sort(all(bycol2[i]));

			ll v = 1;

			forn(j, n)
			{
				if(j && bycol[i][j].fi != bycol[i][j - 1].fi)
					v++;

				bycol2[i][j].fi = v;
				maxcol[i] = max(maxcol[i], v);
			}
			sort(all(bycol2[i]), by(se));
		}

//		print byrow;
//		print bycol;
//		print maxrow;
//		print maxcol;

		forn(i, n) {
			forn(j, m) {
				ll rv = byrow2[i][j].fi;
				ll cv = bycol2[j][i].fi;

//				print i, j, rv, cv;

				if(rv > cv)
				{
					ll ans = max(maxrow[i], maxcol[j] + rv - cv);
//					print ans;
					out << ans << " ";
				}
				else if(cv > rv)
				{
					ll ans = max(maxcol[j], maxrow[i] + cv - rv);
//					print ans;
					out << ans << " ";
				} else
				{
					ll ans = max(maxcol[j], maxrow[i]);
//					print ans;
					out << ans << " ";
				}
			}
			
			out << endl;
		}
	}
};
