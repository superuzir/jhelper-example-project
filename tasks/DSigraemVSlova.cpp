#include <iostream>

#include "../library/lib.hpp"

class DSigraemVSlova
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();

		forn(_, t)
		{
			ll n = read_ll();
			auto s = read_vs(n);

			set<string> set;

			forr(ss, s){
				auto r = ss;
				reverse(all(r));

				set.insert(r);
			}

			ll x00 = 0;
			ll x01 = 0;
			ll x10 = 0;
			ll x11 = 0;

			ll v01 = 0;
			ll v10 = 0;

			forr(ss, s){
				if(ss.front() == ss.back()){
					if(ss[0] == '0')
						x00++;
					else
						x11++;
				} else {
					if(set.count(ss)){
						if(ss[0] == '0')
							x01++;
						else
							x10++;
					} else {
						if(ss[0] == '0')
							v01++;
						else
							v10++;
					}
				}
 			}

// 			print set;

// 			dbg(x00);
//			dbg(x01, v01);
//			dbg(x10, v10);
// 			dbg(x11);

 			if(x01 - 1 - x10 > v01 + v10){
 				// net v testah
 				print -1;
 				continue;
 			}

 			if(x10 - 1 - x01 > v01 + v10){
				// net v testah
				print -1;
				continue;
 			}

 			if(x00 && x11 && (x01 + v01 + x10 + v10 == 0)){
				print -1;
				continue;
 			}

 			if(x01 + v01 > x10 + v10){
 				ll dir = (x01 + v01) - 1 - (x10 + v10);

 				ll perev = (dir + 1) / 2; // budem perev v01

// 				dbg(perev);

 				if(perev > v01){
					print -1;
					continue;
 				}

 				vll ans;

 				forn(i, n){
 					auto & ss = s[i];

 					if(!perev)
 						break;

 					if(ss.front() == '0' && ss.back() == '1'){
						if(!set.count(ss)){
							ans.pb(i + 1);
							perev--;
						}
 					}
 				}

 				print ans.size();
 				answer(ans, out);
 			} else {
				ll dir = (x10 + v10) - 1 - (x01 + v01);

				ll perev = (dir + 1) / 2; // budem perev v10

//				dbg(perev);

				if(perev > v10){
					print -1;
					continue;
				}

				vll ans;

				forn(i, n){
					auto & ss = s[i];

					if(!perev)
						break;

					if(ss.front() == '1' && ss.back() == '0'){
						if(!set.count(ss)){
							ans.pb(i + 1);
							perev--;
						}
					}
				}

				print ans.size();
				answer(ans, out);
			}
		}
	}
};
