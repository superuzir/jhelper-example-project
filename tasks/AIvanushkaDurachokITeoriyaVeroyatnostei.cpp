#include <iostream>

#include "../library/lib.hpp"

class AIvanushkaDurachokITeoriyaVeroyatnostei
{
public:
	static ll fib(ll n)
	{
		vll l(n);
		l[0] = 1;
		l[1] = 2;

		forlr(i, 2, n){
			l[i] = l[i - 2] + l[i - 1];
			l[i] %= MOD;
		}
		
		return l.back();
	}
	
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		
		ll ans = 0;
		
		ans += 2 * fib(n) + MOD - 1;
		ans += 2 * fib(m) + MOD - 1;
		ans %= MOD;

		print ans;
	}
};
