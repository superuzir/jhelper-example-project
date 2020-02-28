#include <iostream>

#include "../library/lib.hpp"

class DMaksimizatsiyaMEX
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll __q = read_ll();
		ll x = read_ll();

		map<ll, ll> map;
		set<ll> set;

		forn(i, x){
			set.insert(i);
		}

		ll add = 0;

		forn(_, __q){
			ll y = read_ll() % x;

//			dbg(y);
//			dbg(map);
//			dbg(set);

			set.erase(y);
			map[y]++;

			if(map.size() == x){
				add += x;

				for(auto it = map.begin(); it != map.end(); )
				{
					it->se--;
					if(it->se == 0){
						set.insert(it->fi);
						it = map.erase(it);
					} else {
						++it;
					}
				}
			}


			print add + *set.begin();
		}
	}
};
