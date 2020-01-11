#include <iostream>

#include "../library/lib.hpp"

class ASladkayaZadacha
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q) {

			auto v = read_vll(3);

			soa(v);

			if(v[2] >= v[0] + v[1]){
				print v[0] + v[1];
			} else {
				print v[2] + (v[0] + v[1] - v[2]) / 2;
			}
		}
	}
};
