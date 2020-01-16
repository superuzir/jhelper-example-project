#include <iostream>

#include "../library/lib.hpp"

class B2SotsialnayaSetSlozhnayaVersiya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll __q = 1;

		forn(_, __q){
			ll n = read_ll();
			ll k = read_ll();
			auto v = read_vll(n);

			set<ll> s;
			queue<ll> q;

			forr(d, v){
				if(!s.count(d)){
					q.push(d);

					if(q.size() > k) {
						s.erase(q.front());
						q.pop();
					}

					s.insert(d);
				}
			}

			vll ans;

			while(!q.empty()){
				ans.pb(q.front());
				q.pop();
			}

			reverse(all(ans));

			print ans.size();
			answer(ans, out);
		}
	}
};
