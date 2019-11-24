#include <iostream>

#include "../library/lib.hpp"

class CGryazno
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();

		forn(_, t)
		{
			ll n = read_ll();
			ll k = read_ll();
			auto s = read_s();

			string ex;

			forn(i, k - 1)
				ex += "()";

			forn(i, (n - (k - 1) * 2) / 2)
				ex += "(";

			forn(i, (n - (k - 1) * 2) / 2)
				ex += ")";

//			dbg(ex);

			vpll ans;

			forn(i, n){
				if(s[i] != ex[i]){
					forlr(j, i + 1, n){
						if(s[j] == ex[i]){
							ans.pb({i + 1, j + 1});

							if(j - i > 2){
								ans.pb({i + 2, j + 0});
							}

							swap(s[i], s[j]);

							break;
						}
					}
				}
			}
			
//			print ans.size(), ans;

			print ans.size();
			forr(p, ans) print p.fi, p.se;
		}
	}
};
