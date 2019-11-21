#include <iostream>

#include "../library/lib.hpp"

class EXORUgadaika
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		vll v1(100);
		vll v2(100);

		iota(all(v1), 1);
		
		forn(i, 100)
			v2[i] = v1[i] * 128;

		out << "? "; answer(v1, out); ll a1 = read_ll();
		out << "? "; answer(v2, out); ll a2 = read_ll();

		print "!", (a1 & 0x3F80) | (a2 & 0x7F);
	}
};
