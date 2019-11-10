#include <iostream>

#include "../library/lib.hpp"

class DOstrovSokrovish
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		auto vs = read_vs(n);

		forn(k, n + m - 1){
			ll start_col =  max(0ll, k + 1 - n);
			ll count = min3(k + 1, (m - start_col), n);

			forn(kk, count){
				ll i = min(n, k + 1) - kk - 1;
				ll j = start_col + kk;

				auto inrange = [&](ll i, ll j){ return i >= 0 && i < n && j >= 0 && j < m; };
				auto access = [&](ll i, ll j){ return vs[i][j] == '.' || vs[i][j] == 'a'; };

				bool t = inrange(i - 1, j) && access(i - 1, j);
				bool l = inrange(i, j - 1) && access(i, j - 1);

				if(inrange(i, j) && (i || j) && vs[i][j] != '#')
					vs[i][j] = (t || l) ? 'a' : '#';
			}
		}

		nfor(k, n + m - 1){
			ll start_col =  max(0ll, k + 1 - n);
			ll count = min3(k + 1, (m - start_col), n);

			forn(kk, count){
				ll i = min(n, k + 1) - kk - 1;
				ll j = start_col + kk;

				auto inrange = [&](ll i, ll j){ return i >= 0 && i < n && j >= 0 && j < m; };
				auto access = [&](ll i, ll j){ return vs[i][j] == '.' || vs[i][j] == 'a'; };

				bool t = inrange(i + 1, j) && access(i + 1, j);
				bool l = inrange(i, j + 1) && access(i, j + 1);

				if(inrange(i, j) && (i != n - 1 || j != m - 1) && vs[i][j] != '#')
					vs[i][j] = (t || l) ? 'a' : '#';
			}
		}


		ll mina = max_ll;

		forn1(k, n + m - 2){
			ll start_col =  max(0ll, k + 1 - n);
			ll count = min3(k + 1, (m - start_col), n);

			ll acnt = 0;

			forn(kk, count){
				ll i = min(n, k + 1) - kk - 1;
				ll j = start_col + kk;

				auto inrange = [&](ll i, ll j){ return i >= 0 && i < n && j >= 0 && j < m; };

				if(inrange(i, j) && vs[i][j] == 'a')
				{
					acnt++;
				}
			}

			mina = min(mina, acnt);
		}

		if(mina <= 2)
			print mina;
		else
			print 2;

//		forr(s, vs)
//			print s;
	}
};
