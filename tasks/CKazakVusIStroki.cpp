#include <iostream>

#include "../library/lib.hpp"

class CKazakVusIStroki
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		auto a = read_s();
		auto b = read_s();

		ll dif = 0;

		forn(i, b.size()){
			if(a[i] != b[i])
				dif++;
		}

		ll ans = dif % 2 == 0;

		forlr(i, b.size(), a.size()){
			if(a[i] != a[i - b.size()])
				dif++;

			if(dif % 2 == 0)
				ans++;
		}

		print ans;
	}
};
