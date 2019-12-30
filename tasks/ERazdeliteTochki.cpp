#include <iostream>

#include "../library/lib.hpp"

class ERazdeliteTochki
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		vll x(n);
		vll y(n);

		forn(i, n){
			x[i] = read_ll();
			y[i] = read_ll();
		}

		set<ll> r;
		vll ans;

		ans.pb(0);

		forn1(i, n){
			bool ok = true;

			forr(a, ans){
				ll dx = x[i] - x[a];
				ll dy = y[i] - y[a];

				ll d = dx * dx + dy * dy;

				if(r.count(d)){
					ok = false;
					break;
				}
			}

			if(ok){
				forr(a, ans){
					ll dx = x[i] - x[a];
					ll dy = y[i] - y[a];

					ll d = dx * dx + dy * dy;

					r.insert(d);
				}

				ans.pb(i);
			}
		}

		print ans.size();

		forr(a, ans)
			out << a + 1 << ' ';

		out << endl;
	}
};
