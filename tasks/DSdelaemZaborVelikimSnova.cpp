#include <iostream>

#include "../library/lib.hpp"

class DSdelaemZaborVelikimSnova
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
#define hgt fi
#define cst se

		ll q = read_ll();

		forn(_, q)
		{
			ll n = read_ll();
			auto v = read_vpll(n);

			vll pp(3);
			vll pc(3);

			pp[0] = 0;
			pp[1] = v[0].cst;
			pp[2] = v[0].cst * 2;

//			dbg(pp);

			forn1(i, n){
				forn(curdh, 3){
					ll mn = max_ll;

					forn(prevdh, 3)
					{
						if(v[i].hgt + curdh != v[i - 1].hgt + prevdh)
							mn = min(mn, pp[prevdh]);
					}

					pc[curdh] = mn + curdh * v[i].cst;
				}

				pp = pc;

//				dbg(pc);
			}

			print min3(pc[0], pc[1], pc[2]);
		}
	}
};
