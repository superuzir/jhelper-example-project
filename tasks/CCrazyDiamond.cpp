#include <iostream>

#include "../library/lib.hpp"

class CCrazyDiamond
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		bool gen;

		vll v, vinit;

		if(n < 0)
		{
			gen = true;
			vinit = {1, 2, 3, 4};
			n = vinit.size();
		}
		else
		{
			gen = false;
			v = read_vll(n);
		}

		do
		{
			if(gen)
				v = vinit;

			vpll ans;

			auto an = [&](ll i1, ll i2)
			{
				swap(v[i1], v[i2]);
				ans.pb({i1 + 1, i2 + 1});
			};

			while(!is_sorted(all(v)))
			{
				forn(i, n)
				{
					ll i1 = i;
					ll i2 = v[i] - 1;

					ll &v1 = v[i1];
					ll &v2 = v[i2];

					if(v1 == i + 1)
						continue;

					if(abs(i1 - i2) >= n / 2)
					{
//						print 'a', v1, v2;
						an(i1, i2);
					}
					else
					{
						if(i1 < n / 2 && i2 < n / 2)
						{
//							print 'b';
							an(i1, n - 1);
							an(i2, n - 1);
							an(i1, n - 1);
						}
						else if(i1 >= n / 2 && i2 >= n / 2)
						{
//							print 'c';
							an(i1, 0);
							an(i2, 0);
							an(i1, 0);
						}
						else if(i1 < i2)
						{
//							print 'd', i1, i2;
							an(i1, n - 1);
							an(i2, 0);
							an(0, n - 1);
							an(i1, n - 1);
							an(i2, 0);
						}
						else
						{
//							print 'e';
							an(i2, n - 1);
							an(i1, 0);
							an(0, n - 1);
							an(i2, n - 1);
							an(i1, 0);
						}
					}

//					print i, v;
				}
			}

//			print vinit, v;

			print ans.size();
			forr(p, ans)
			{
				print p.fi, p.se;
			}
		} while(gen && next_permutation(all(vinit)));
	}
};
