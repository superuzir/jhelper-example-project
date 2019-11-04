#include <iostream>

#include "../library/lib.hpp"

class BVamZadanaDesyatichnayaStroka
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll MX = (max_ll / 4);

		auto str = read_s();

		vvvvll ds(10, vvvll(10, vvll(10, vll(10, MX))));

		forn(from, 10)
		forn(i, 10)
		forn(j, 10)
		forn(ci, 10)
		forn(cj, 10)
		{
			if(ci + cj == 0)
				continue;
			
			ll num = from + i * ci + j * cj;
			ll to = num % 10;

			ds[i][j][from][to] = min(ds[i][j][from][to], ci + cj);
		}


		vvll ans(10, vll(10, -1));

		forn(i, 10)
			forn(j, 10)
			{
				ll cst = 0;
				bool ok = true;

				forn1(s, str.size()){
					ll from = str[s - 1] - '0';
					ll to = str[s] - '0';

					ll cnt = ds[i][j][from][to];

					if(cnt < MX){
						cst += cnt - 1;
					} else {
						ok = false;
					}
				}

				if(ok)
					ans[i][j] = cst;
			}


		forr(a, ans)
			answer(a, out);

	}
};
