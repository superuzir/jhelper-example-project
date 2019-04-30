#include <iostream>

#include "../library/lib.hpp"

class CPolikarpVosstanavlivaetPerestanovku
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n - 1);
		
		vll ans(1, 1);
		
		forn1(i, n)
			ans.pb(ans[i - 1] + vec[i - 1]);
		
		ll min = *min_element(all(ans));
		
		forn(i, n)
			ans[i] += 1 - min;
		
		auto ans2 = ans;
		sort(all(ans2));

		forn(i, n)
		if(ans2[i] != i + 1)
		{
			print -1;
			return;
		}
		
		answer(ans, out);
	}
};
