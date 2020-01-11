#include <iostream>

#include "../library/lib.hpp"

class ACopyingHomework
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto v = read_vll(n);

		forr(vv, v){
			out << n - vv + 1 << ' ';
		}

		out << endl;
	}
};
