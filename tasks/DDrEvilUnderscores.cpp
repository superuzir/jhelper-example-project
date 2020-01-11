#include <iostream>

#include "../library/lib.hpp"

class DDrEvilUnderscores
{
	static pll brute(std::ostream& out, const vll & v){
		ll mn = max_ll;
		ll xr = 0;

		forn(i, 1 << 10){
			ll mx = 0;
			forr(vv, v) {
				mx = max(mx, vv ^ i);
//				dbg(i, vv, vv ^ i, mx);
			}

			if(mx < mn){
				mn = mx;
				xr = i;
			}
		}

		return {mn, xr};
	}

	ll allof(const vll & v, ll bit){
		ll ors = 0;
		ll ands = (1ll << 40) - 1;

		forr(vv, v){
			ors |= vv;
			ands &= vv;
		}

		if((ands & (1ll << bit)) != 0)
			return 1;
		else if((ors & (1ll << bit)) == 0)
			return 0;
		else
			return -1;
	}

	ll rec(std::ostream& out, vll v, ll bit){

//		dbg(bit, v);

		ll b = bit;

		nfor(i, bit + 1){
			b = i;
//			dbg(i, allof(v, i));
			if(allof(v, i) == 1){
				forr(vv, v)
					vv &= ~(1 << i);
			} else if(allof(v, i) == 0){
				//
			} else {
				break;
			}
		}

		bit = b;

		if(bit == 0)
			return *max_element(all(v));

//		dbg(bit, v);

		vll v0;
		vll v1;

		forr(vv, v){
			if(vv & (1 << bit))
				v1.pb(vv);
			else
				v0.pb(vv);
		}

		forr(vv, v0){
			vv |= 1 << bit;
		}

//		dbg(v0, v1);

//		return 0;
		return min(rec(out, v0, bit - 1), rec(out, v1, bit - 1));
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto v = read_vll(n);

//		print brute(out, v).fi;

		print rec(out, v, 31);

//		print allof({94, 83}, 6);
//		print allof({94, 83}, 5);
//		print allof({94, 83}, 4);
//		print allof({94, 83}, 3);
	}
};
