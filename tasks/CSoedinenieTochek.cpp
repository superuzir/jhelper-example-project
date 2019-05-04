#include <iostream>

#include "../library/lib.hpp"

class CSoedinenieTochek
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll z = read_ll();
		vll vec = read_vll(n);

		sort(all(vec));

		deque<ll> lst;
		deque<ll> mst;
		
		lst.push_back(vec[0]);
		
		forn1(i, n)
		{
			if(vec[i] < lst[0] + z)
			{
				lst.push_back(vec[i]);
			}
			else
			{
				mst.push_back(vec[i]);
				
				if(mst[0] + z <= mst.back() && lst.size() < mst.size())
				{
					lst.push_back(mst.front());
					mst.pop_front();
				}
			}
		}
		
		ll l = 0;
		ll r = 0;
		
		ll ans = 0;
		
		while(l < lst.size() && r < mst.size())
		{
			if(lst[l] + z <= mst[r])
			{				
				ans++;
				l++;
				r++;
			}
			else
			{
				r++;
			}
		}
		
		print ans;
	}
};
