#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class BMarchinISbori
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto a = read_vll(n);
		auto b = read_vll(n);

		vb take(n);

		forn(i, n){
			ll same = 0;

			vb t(n);

			forn(j, n){
				if((a[i] | a[j]) == a[i]){
					t[j] = true;
				}

				if(a[i] == a[j])
					same++;
			}

			if(same > 1)
			{
				forn(i, n){
					take[i] = take[i] || t[i];
				}
			}
		}

		ll ans = 0;

		forn(i, n){
			if(take[i])
				ans += b[i];
		}

		print ans;
	}
};
