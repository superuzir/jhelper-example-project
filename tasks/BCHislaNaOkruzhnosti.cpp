#include <iostream>

#include "../library/lib.hpp"

class BCHislaNaOkruzhnosti
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		multiset<ll> set;

		forn(i, n)
			set.insert(read_ll());

		bool fr = false;
		deque<ll> ans;

		while(set.size())
		{
			if(fr)
			{
				auto it = prev(set.end());
				ans.push_back(*it);
				set.erase(it);
			}
			else
			{
				auto it = prev(set.end());
				ans.push_front(*it);
				set.erase(it);
			}

			fr = fr ? false : true;
		}

		forn1(i, ans.size() - 1)
		{
			if(ans[i] >= ans[i - 1] + ans[i + 1])
			{
				print "NO";
				return;
			}
		}

		if(ans[n - 1] >= ans[n - 2] + ans[0])
		{
			print "NO";
			return;
		}

		if(ans[0] >= ans[1] + ans[n - 1])
		{
			print "NO";
			return;
		}
		
		print "YES";
		forn(i, n)
		{
			out << ans[i] << " ";
		}
		
		out << endl;
	}
};
