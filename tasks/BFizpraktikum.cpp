#include <iostream>

#include "../library/lib.hpp"

class BFizpraktikum
{
public:
	void solve(std::istream& in0, std::ostream& out0)
	{
		ifstream in;
		in.open("input.txt");

		ofstream out;
		out.open("output.txt");

		ll n = read_ll();
		vll vec = read_vll(n);

		sort(all(vec));

		ll ans = max_ll;

		forn(i, n)
		{
			ll r = vec.end() - upper_bound(vec.begin() + i, vec.end(), vec[i] * 2);
			ans = min(ans, i + r);
		}

		print ans;
	}
};
