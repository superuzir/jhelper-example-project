#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"

const ll MOD2 = 998244353;

class BUdaleniePodstroki
{

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		string str = read_s();

		string beg;
		string end;

		itersame(all(str), [&](auto b, auto e){
			if(b == str.begin()) beg = string(b, e);
			if(e == str.end())   end = string(b, e);
		});

		ll ans = 0;

		if(beg.size() == n)
		{
			forn(i, n)
			{
				ans += i + 1;
				ans %= MOD2;
			}
		}
		else if(beg[0] == end[0])
		{
			ans = ll(beg.size() + 1) * ll(end.size() + 1);
			ans %= MOD2;
		}
		else
		{
			ans = ll(beg.size() + 1) + ll(end.size() + 1) - 1;
			ans %= MOD2;
		}

		print ans;
	}
};
