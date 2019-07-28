#include <iostream>

#include "../library/lib.hpp"

class BSrednyayaSilaSupergeroev
{
public:

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();
		ll m = read_ll();
		vll vec = read_vll(n);

		soa(vec);

		ll sum = sua(vec);

		double ans = double(sum + min(n*k, m)) / double(n);

		forn(i, min(n - 1, m))
		{
			ll nleft = n - i - 1;
			ll mleft = m - i - 1;

			ll up = min(nleft * k, mleft);
			sum -= vec[i];
			ans = max(ans, double(up + sum) / double(nleft));
		}

		out << fixed << setprecision(20) << ans << endl;
	}
};
