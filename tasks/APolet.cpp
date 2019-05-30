#include "../library/lib.hpp"


class APolet
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		vll a = read_vll(n);
		vll b = read_vll(n);

		if(find(all(a), 1) != a.end() || find(all(b), 1) != b.end())
		{
			print -1;
			return;
		}

		vll ab;

		ab.pb(b[0]);

		for(ll i = n - 1; i >= 1; --i)
		{
			ab.pb(a[i]);
			ab.pb(b[i]);
		}

		ab.pb(a[0]);

		double ans = 0;

		forr(a, ab)
		{
			ans += (ans + m) / (a - 1);
		}

		print ans;
	}
};
