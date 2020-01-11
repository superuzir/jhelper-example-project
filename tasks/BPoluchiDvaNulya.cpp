#include <iostream>

#include "../library/lib.hpp"

class BPoluchiDvaNulya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q){
			ll a = read_ll();
			ll b = read_ll();

			if(a > b)
				swap(a, b);

			ll d = 2 * a - b;

			if(d < 0){
				print "NO";
			} else if(d % 3 == 0) {
				print "YES";
			} else {
				print "NO";
			}
		}
	}
};
