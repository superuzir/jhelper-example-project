#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class LLexicography
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll l = read_ll();
		ll k = read_ll();
		auto s = read_s();

		sort(rall(s));

		vs ans(n);

		auto take = [&](){
			char c = s.back();
			s.pop_back();
			return c;
		};

		forn(i, k){
			ans[i] += take();
		}

		ll ok = k;

		forn1(i, l){
			string pr;

			forn(j, k){
				pr += ans[j].back();
			}

			vpll ix;

			itersameall(pr, {
				ix.pb({b - pr.begin(), e - pr.begin()});
			});

			{
				ll last = ix.back().se - ix.back().fi;
				if(last <= ok){
					ok = last;
				} else {
					pll p1 = {ix.back().fi, ix.back().se - ok};
					pll p2 = {ix.back().se - ok, ix.back().se};
					ix.pop_back();
					ix.pb({p1});
					ix.pb({p2});
				}
			}

			forlr(j, ix.back().fi, ix.back().se){
				ans[j] += take();
			}
		}

		forr(a, ans){
			while(a.size() < l)
				a += take();
		}

		forr(a, ans){
			out << a << '\n';
		}
	}
};
