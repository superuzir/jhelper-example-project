#include <iostream>

#include "../library/lib.hpp"

class CRaznoobraznayaMatritsa
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll r = read_ll();
		ll c = read_ll();

		if(r == 1 && c == 1){
			print 0;
			return;
		}

		if(c == 1){
			forn(i, r){
				out << i + 2 << endl;
			}
			return;
		}

		forn(i, r){

			forn(j, c){
				out << (j + 2) * (i == 0 ? 1 : c + 1 + i) << ' ';
			}

			out << endl;
		}
	}
};
