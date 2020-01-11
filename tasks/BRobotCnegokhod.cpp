#include <iostream>

#include "../library/lib.hpp"

class BRobotCnegokhod
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q){
			auto s = read_s();

			ll ud = min(count(all(s), 'U'), count(all(s), 'D'));
			ll lr = min(count(all(s), 'L'), count(all(s), 'R'));

			if(ud == 0 && lr == 0) {
				print 0;
				continue;
			}
			if(ud == 0) lr = 1;
			if(lr == 0) ud = 1;

			string ans;

			forn(i, lr) ans += 'L';
			forn(i, ud) ans += 'U';
			forn(i, lr) ans += 'R';
			forn(i, ud) ans += 'D';

			print ans.size();
			print ans;
		}
	}
};
