#include <iostream>

#include "../library/lib.hpp"

class FDataCenter
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();

		ll mn = max_ll;

		for(ll i = 1; i * i <= n; i++){
			if(n % i == 0){
				mn = min(mn, 2 * (i + n / i));
			}
		}

		print mn;
	}
};
