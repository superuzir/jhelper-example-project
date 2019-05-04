#include <iostream>

#include "../library/lib.hpp"

class DPodeliNaTriUmnozhNaDva
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);

		multiset<ll> set(all(vec));
		deque<ll> ans;

		ans.pb(*set.begin());
		set.erase(set.begin());

		while(set.size())
		{
			ll b = ans.back();
			
			if(ll cand = b / 3; b % 3 == 0 && set.count(cand))
			{
				auto it = set.find(cand);
				ans.pb(*it);
				set.erase(it);
			}
			else if(ll cand = b * 2; set.count(cand))
			{
				auto it = set.find(cand);
				ans.pb(*it);
				set.erase(it);
			}
			
			b = ans.front();
			if(ll cand = b / 2; b % 2 == 0 && set.count(cand))
			{
				auto it = set.find(cand);
				ans.push_front(*it);
				set.erase(it);
			}
			else if(ll cand = b * 3; set.count(cand))
			{
				auto it = set.find(cand);
				ans.push_front(*it);
				set.erase(it);
			}
		}
		
		answer(vll(all(ans)), out);
	}
};
