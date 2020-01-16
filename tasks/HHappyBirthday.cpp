#include <iostream>

#include "../library/lib.hpp"

class HHappyBirthday
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q) {
			auto v = read_vll(10);

			if(auto it = min_element(v.begin() + 1, v.end()); *it == 0){
				print it - v.begin();
				continue;
			}

			if(auto it = min_element(v.begin() + 1, v.end()); *it > v[0]){
				out << 1;
				forn(i, v[0] + 1){
					out << 0;
				}
				out << endl;
			} else {
				forn(i, *it + 1){
					out << it - v.begin();
				}

				out << endl;
			}
		}
	}
};
