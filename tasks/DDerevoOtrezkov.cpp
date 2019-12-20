#include <iostream>

#include "../library/lib.hpp"

class DDerevoOtrezkov
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto v = read_vpll(n);

		vll z(2*n+1);

		forr(p, v){
			z[p.fi]++;
			z[p.se]--;
		}

		vll z2(2*n + 1);

		z2[0] = 1;

		forn1(i, 2*n+1){
			z2[i] = z2[i - 1] + z[i];
		}

		ll ans = sua(z2);

		print ans % 2 == 1 ? "YES" : "NO";

//		print z2;
	}
};
