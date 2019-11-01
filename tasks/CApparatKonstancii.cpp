#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"
#include "../library/fibMod.h"




class CApparatKonstancii
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		auto s = read_s();

		if(count(all(s), 'm') || count(all(s), 'w')) {
			print 0;
			return;
		}

		ll ans = 1;

		itersameall(s, {
			if((*b == 'n' || *b == 'u') && (e - b) > 1){
				ans *= fibMod(1, 2, (e - b), MOD);
				ans %= MOD;
			}
		});

		print ans;
	}
};
