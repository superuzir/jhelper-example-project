#include <iostream>

#include "../library/lib.hpp"

class CIgrovoiLabirintNeko
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll __q = read_ll();

		vector<vb> v(2, vb(n));

		auto ok = [&](ll i){
		    bool up = v[0][i] || v[0][i + 1];
		    bool dw = v[1][i] || v[1][i + 1];
            return (up && dw);
		};

		ll total = 0;

		forn(_, __q){
		    ll r = read_ll() - 1;
		    ll c = read_ll() - 1;

		    ll before_l = -1;
		    ll before_r = -1;

		    if(c - 1 >= 0) before_l = ok(c - 1);
		    if(c + 1 < n) before_r = ok(c);

//			dbg(before_l, before_r);

		    v[r][c] = !v[r][c];

//			forn(k, 2)
//				dbg(v[k]);

            ll after_l = -1;
            ll after_r = -1;

            if(c - 1 >= 0) after_l = ok(c - 1);
            if(c + 1 < n) after_r = ok(c);

//			dbg(after_l, after_r);

//            dbg(total);

            if(before_l >= 0)
                total += after_l - before_l;

            if(before_r >= 0)
                total += after_r - before_r;

//            dbg(total);

			print total ? "No" : "Yes";
		}
	}
};
