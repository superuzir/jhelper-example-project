#include <iostream>

#include "../library/lib.hpp"

class AKostyumi
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll a = read_ll();
		ll b = read_ll();
		ll c = read_ll();
		ll d = read_ll();
		ll e = read_ll();
		ll f = read_ll();

		ll ans = 0;
		
		if(e > f){
			ll cos = min(a, d);
			d -= cos;
			ans += cos * e;
			
			cos = min3(b, c, d);
			ans += cos * f;
		} else {
			ll cos = min3(b, c, d);
			d -= cos;
			ans += cos * f;

			cos = min(a, d);
			ans += cos * e;
		}
		
		print ans;
	}
};
