#include <iostream>

#include "../library/lib.hpp"

class BVkusniePokupki
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q){
			ll n = read_ll();
			auto v = read_vll(n);

			ll sum = 0;
			ll mx = 0;
			ll take = 0;

			forn(i, n){
				if(sum + v[i] > 0){
					sum += v[i];
					take++;
				} else {
					sum = 0;
				}

				mx = max(mx, sum);
			}

			if(take == n){
				mx = 0;
				sum = 0;
				forn1(i, n){
					if(sum + v[i] > 0){
						sum += v[i];
						take++;
					} else {
						sum = 0;
					}

					mx = max(mx, sum);
				}

				sum = 0;
				forn(i, n - 1){
					if(sum + v[i] > 0){
						sum += v[i];
						take++;
					} else {
						sum = 0;
					}

					mx = max(mx, sum);
				}
			}

			if(*max_element(all(v)) < 0)
				mx = *max_element(all(v));

//			dbg(mx, sua(v));

			print sua(v) > mx ? "YES" : "NO";
		}
	}
};
