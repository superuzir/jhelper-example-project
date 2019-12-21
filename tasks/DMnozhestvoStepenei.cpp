#include <iostream>

#include "../library/lib.hpp"

class DMnozhestvoStepenei
{
public:
	static vpll make(ll st, vector<ll> d)
	{
		if(d.empty())
			return vpll();

		vpll ans;

		forn(i, d[0]){
			forlr(j, st + i + 1, st + d.back() + 1){
				ans.pb({st + i, j});
			}
		}

		ll nxt = st + d[0];

		forn1(i, d.size() - 1){
			d[i] -= d[0];
		}

		d.erase(d.begin());
		if(!d.empty())
			d.pop_back();

		auto ans2 = make(nxt, d);

		forr(a, ans2)
			ans.pb(a);

		return ans;
	}

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto d = read_vll(n);

		auto ans = make(0, d);

		print ans.size();

		forr(a, ans)
			print a.fi + 1, a.se + 1;
	}
};
