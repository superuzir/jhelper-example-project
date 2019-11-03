#include <iostream>

#include "../library/lib.hpp"

class CAnnaSvyatoslavIKarta
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		auto g = read_vs(read_ll());
		auto p = read_vll(read_ll());

		forr(pp, p) pp--;

		vector<vll> kr(g.size(), vll(g.size(), max_ll));

		forn(i, g.size()){
			queue<ll> q;

			q.push(i);
			kr[i][i] = 0;

			while(!q.empty()){
				ll j = q.front(); q.pop();

				forn(k, g[j].size()){
					if(g[j][k] == '0')
						continue;

					if(kr[i][k] == max_ll){
						q.push(k);
					}

					kr[i][k] = min(kr[i][k], kr[i][j] + 1);
				}
			}
		}

//		forr(krr, kr)
//			print krr;


		ll l = p[0];
		ll r = p[1];
		ll m = r;

		vll ans;
		ans.pb(p.front());

		ll sokp = 1;

		forlr(i, 1, p.size()){
//			dbg(l, m, r, sokp, g[l][r], kr[l][r], kr[l][r] < sokp);

			if(kr[l][r] < sokp){
				ans.pb(m);
				l = m;
				m = r;
				r = p[i + 1];
				sokp = 2;
			} else {
				m = r;
				r = p[i + 1];
				sokp++;
			}
		}

		ans.pb(p.back());

		forr(a, ans) a++;
		print ans.size();
		answer(ans, out);
	}
};
