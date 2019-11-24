#include <iostream>

#include "../library/lib.hpp"

class D2UdalitePodstrokuSlozhnayaVersiya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		auto a = read_s();
		auto b = read_s();

		ll j = 0;

		vll v1(b.size());
		vll v2(b.size());

		forn(i, a.size()){
			if(a[i] == b[j]){
				v1[j] = i;
				j++;
			}
		}

		j--;

		nfor(i, a.size()){
			if(a[i] == b[j]){
				v2[j] = i;
				j--;
			}
		}

		ll ans = v2.front();

		ans = max(ans, ll(a.size()) - v1.back() - 1);


		forn1(i, v1.size()){
			ans = max(ans, v2[i] - v1[i - 1] - 1);
		}

//		print v1;
//		print v2;

		print ans;
	}
};
