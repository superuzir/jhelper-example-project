#include <iostream>

#include "../library/lib.hpp"

class BNoviiGodIVoskhodyashchayaPosledovatelnost
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		vvll v;

		forn(i, n){
			ll l = read_ll();
			v.pb(read_vll(l));
		}

		soa (v);

		ll hor = 0;

		vll f;

		forr(vv, v){
			bool ishor = false;
			forn1(i, vv.size()){
				if(vv[i] > vv[i - 1]){
					ishor = true;
					break;
				}
			}

			if(ishor)
				hor++;
			else
				f.pb(vv.front());
		}

//		dbg(hor);


//		dbg(f);

		ll ans = 0;

		forr(vv, v){
			bool ishor = false;
			forn1(i, vv.size()){
				if(vv[i] > vv[i - 1]){
					ishor = true;
					break;
				}
			}

			if(ishor){
				ans += n;
			} else {
				ans += hor;
				auto it = lower_bound(all(f), vv.back() + 1);
				ans += f.end() - it;
			}
		}

		print ans;
	}
};
