#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class CPalindromnayaMatrica
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n*n);

		sort(all(vec));

		if(n % 2 == 0)
		{
			bool ok = true;

			vll quat;

			itersameall(vec, {
				if((e - b) % 4)
					ok = false;

				forn(i, (e - b) / 4)
					quat.pb(*b);
			});

			if(!ok)
			{
				print "NO";
				return;
			}

			vector<vll> ans(n, vll(n));

			forn(i, n)
			forn(j, n)
			{
				ll ii = i < n / 2 ? i : n - i - 1;
				ll jj = j < n / 2 ? j : n - j - 1;
	
				ans[i][j] = quat[ii + jj * n / 2];
			}

			print "YES";

			forn(i, n)
			forn(j, n)
			{
				out << ans[i][j] << (j == n - 1 ? "\n" : " ");
			}
		}
		else
		{
			vll center;

			vll quat;
			vll dual;

			itersameall(vec, {
				ll l = e - b;
				ll v = *b;

				if(l % 2)
				{
					center.pb(v);
					l--;
				}

				if(l % 4 == 0)
				{
					forn(i, l / 4)
						quat.pb(v);
				}
				else if(l % 4 == 2)
				{
					dual.pb(v);

					forn(i, l / 4)
						quat.pb(v);
				}
			});

			while(!quat.empty() && dual.size() < n/2 + n/2)
			{
				dual.pb(quat.back());
				dual.pb(quat.back());
				quat.pop_back();
			}

//			print vec;
//			print quat;
//			print dual;
//			print center;

			if(center.size() != 1 || quat.size() != (n/2) * (n/2) || dual.size() != n/2 + n/2)
			{
				print "NO";
				return;
			}

			vector<vll> ans(n, vll(n));

			forn(i, n)
			forn(j, n)
			{
				ll ii = i < n / 2 ? i : n - i - 1;
				ll jj = j < n / 2 ? j : n - j - 1;

				if(ii == n / 2 && jj == n / 2)
					ans[i][j] = center[0];
				else if(ii == n / 2)
					ans[i][j] = dual[jj];
				else if(jj == n / 2)
					ans[i][j] = dual[ii + n / 2];
				else
					ans[i][j] = quat[ii + jj * (n / 2)];
			}

			print "YES";

			forn(i, n)
			forn(j, n)
			{
				out << ans[i][j] << (j == n - 1 ? "\n" : " ");
			}
		}
	}
};
