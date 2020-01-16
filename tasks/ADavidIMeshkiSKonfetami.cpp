#include <iostream>

#include "../library/lib.hpp"

class ADavidIMeshkiSKonfetami
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll __q = 1;

		forn(_, __q){
			auto v = read_vll(4);

			soa(v);

			do {
				forn1(i, 4){
					if(accumulate(&v[0], &v[i], 0ll) == accumulate(&v[i], &v[4], 0ll)){
						print "YES";
						return;
					}
				}
			} while(next_permutation(all(v)));

			print "NO";
		}
	}
};
