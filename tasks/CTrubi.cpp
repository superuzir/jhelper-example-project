#include <iostream>

#include "../library/lib.hpp"

class CTrubi
{
public:
	void solv(std::istream& in, std::ostream& out){
		ll n = read_ll();
		auto s0 = read_s();
		auto s1 = read_s();

		string s[2] = {s0, s1};

		ll e = 0;
		ll d = 0;

		forn(i, n){
			if(s[e][i] == '1' || s[e][i] == '2'){
				if(d != 0){
					print "NO";
					return;
				} else {

				}
			} else {
				if(d == 0){
					if(e == 0){
						e = 1;
						d = 1;
					} else {
						e = 0;
						d = -1;
					}
					i--;
				} else {
					d = 0;
				}
			}
		}

		print d == 0 && e == 1 ? "YES" : "NO";
	}

	void solve(std::istream& in, std::ostream& out)
	{
		ll __q = read_ll();

		forn(_, __q){
			solv(in, out);
		}
	}
};
