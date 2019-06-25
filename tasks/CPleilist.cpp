#include <iostream>

#include "../library/lib.hpp"

class CPleilist
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();
		vpll p = read_vpll(n);

		sort(rall(p), by(se));

		priority_queue<ll, vll, greater<ll> > q;
		ll sum = 0;
		ll ans = 0;

		forr(p, p)
		{
			sum += p.fi;
			q.push(p.fi);

			if(q.size() > k)
			{
				sum -= q.top();
				q.pop();
			}

			ans = max(ans, sum * p.se);
		}

		print ans;
	}
};
