#include <iostream>

#include "../library/lib.hpp"

class BVamZadanaDesyatichnayaStroka
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		auto s = read_s();

//		ll x = 3;
//		ll y = 5;

		vvll ans(10, vll(10));


		forn(x, 10)
		{
			forn(y, 10)
			{
				vll d(10, max_ll);

				vb q(10);

				q[x] = true;
				q[y] = true;

				d[x] = 1;
				d[y] = 1;

				bool got_new = true;

//				forn(_, 5)
				while (got_new)
				{
					got_new = false;

					vb q2(10);

					forn(a, 10)
					{
						if(!q[a])
							continue;

						ll nx = (a + x) % 10;
						ll ny = (a + y) % 10;

//						dbg(got_new, nx, ny, d[nx], d[ny]);

						if(d[nx] == max_ll || d[ny] == max_ll)
							got_new = true;

						d[nx] = min(d[nx], d[a] + 1);
						d[ny] = min(d[ny], d[a] + 1);

						q2[nx] = true;
						q2[ny] = true;
					}

					q = q2;
				}

//				dbg(x, y, d);
//				if(x == 0 && y == 1)
//					dbg(x, y, d);

				ll cnt = 0;

				forn1(i, s.size()){
					ll dif = (s[i] - s[i - 1] + 10) % 10;
					ll c = d[dif];

//					if(x == 0 && y == 1)
//						dbg(i, dif, c);

					if(c == max_ll){
						cnt = -1;
						break;
					} else {
						cnt += c - 1;
					}
				}

				ans[x][y] = cnt;
			}
		}


		forn(x, 10)
		{
			forn(y, 10)
			{
				out << ans[x][y] << (y == 9 ? " \n" : " ");
			}
		}
	}
};
