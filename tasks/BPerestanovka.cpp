#include <iostream>

#include "../library/lib.hpp"

class BPerestanovka
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();

		vll vec(2 * n);

		iota(all(vec), 1);

		forn(i, k)
		{
			swap(vec[2 * i], vec[2 * i + 1]);
		}
		
		for(auto v: vec)
		{
			out << v << " ";
		}
		
		out << '\n';
	}
};
