#include <iostream>

#include "../library/lib.hpp"

class CVozrastaniePoModulyu
{
	ll minimize(ll a, ll b, ll k, ll m)
	{
		if(a == b)
			return a;

		if(b > a)
		{
			if(b - m + k >= a)
				return a;
			else
				return b;
		}

		if(b < a)
		{
			if(b + k >= a)
				return a;
			else
				return b + k;
		}
	}


public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		vll vec = read_vll(n);

//		print minimize(2, 5, 0, 6);
//		print minimize(2, 5, 1, 6);
//		print minimize(2, 5, 2, 6);
//		print minimize(2, 5, 3, 6);
//		print minimize(2, 5, 4, 6);
//		print minimize(2, 5, 5, 6);
//		print 111;
//		print minimize(5, 2, 0, 6);
//		print minimize(5, 2, 1, 6);
//		print minimize(5, 2, 2, 6);
//		print minimize(5, 2, 3, 6);
//		print minimize(5, 2, 4, 6);
//		print minimize(5, 2, 5, 6);

		if (n == 1)
		{
			print 0;
			return;
		}

//		forn(k, m)
//		{
//			if(check(n, m, vec, k))
//			{
//				print k;
//				return;
//			}
//		}

		ll low = 0;
		ll high = m;
		ll ans = max_ll;

		while (low <= high)
		{
			ll k = low + (high - low) / 2;

			if(check(n, m, vec, k))
			{
				ans = min(ans, k);
				high = k - 1;
			}
			else
			{
				low = k + 1;
			}
		}

		print ans;
	}


	bool check(ll n, ll m, const vll &vec, ll k)
	{
		ll prev = minimize(0, vec[0], k, m);

		forn1(j, n)
		{
			ll cur = minimize(prev, vec[j], k, m);
			if (cur < prev)
				return false;
			prev = cur;
		}

		return true;
	}
};
