#include <iostream>

#include "../library/lib.hpp"

class DOcherednayaZadachaNaPodotrezki
{
	ll brute(ll m, ll k, vll vec, std::ostream& out)
	{
		ll n = vec.size();

		ll ans = 0;

		forn(l, n)
		forlr(r, l, n)
		{
			ll s = accumulate(vec.begin() + l, vec.begin() + r + 1, 0);
			ans = max(ans, s - k * divceil(r - l + 1, m));
			
//			print l, r, ans;
		}

		return ans;
	}

	ll solve(ll m, ll k, vll vec, std::ostream& out)
	{
		ll n = vec.size();

		vll dp(n + 1);

		ll len = 1;

		ll ans = 0;

		forn(i, n)
		{
			ll cand = dp[i] + vec[i] - k * divceil(len, m);

			ans = max(ans, cand);

//			print i, len, ans;
			
			if((len % m && cand >= -k) || (len % m == 0 && cand > 0))
			{
				dp[i + 1] = dp[i] + vec[i];
				len++;
			}
			else
			{
				dp[i + 1] = 0;
				len = 1;
			}
		}

		return ans;
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		ll k = read_ll();
		vll vec = read_vll(n);

//		print solve(m, k, vec, out);
//		print brute(m, k, vec, out);

		forlr(n, 1, 10)
		forlr(m, 1, 10)
		forlr(k, 1, 10)
		{
			vll vec(n);
			forn(i, n)
				vec[i] = -200 + (rand() * (ll)(200 - (-200)) / RAND_MAX);

			ll b = brute(m, k, vec, out);
			ll s = solve(m, k, vec, out);

//			print vec;

			if(b != s)
			{
				print b, s, n, m, k, vec;
			}
		}
	}
};

//284 282 5 3 3 vector(-112, 2, 111, 174, -144)
//75 72 5 8 5 vector(46, 6, -49, 0, 77)
