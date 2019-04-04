#include <iostream>

#include "../library/lib.hpp"

class BApproksimizaciyaPostoyannogoDiapazona
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		multiset<ll> set;
		queue<std::multiset<ll>::iterator> queue;

		size_t max = 0;

		forn(r, n)
		{
			queue.push(set.insert(read_ll()));

			while(*set.rbegin() - *set.begin() > 1)
			{
				set.erase(queue.front());
				queue.pop();
			}

			max = std::max(max, set.size());
		}

		print max;
	}
};
