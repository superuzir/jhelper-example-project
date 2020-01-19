#include <iostream>

#include "../library/lib.hpp"

class DRozhdestvenskieDerevya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
        ll n = read_ll();
        ll m = read_ll();
        auto x = read_vll(n);

        soa(x);

        vvll v;

        v.push_back({x[0], -1, ll(1e9), 1});

        forn1(i, n){
            ll d = x[i] - x[i - 1] - 1;

            if(d > 0){
                v.push_back({x[i - 1], +1, divceil(d, 2), 1});
                if(d - divceil(d, 2))
                    v.push_back({x[i], -1, d - divceil(d, 2), 1});
            }
        }

        v.push_back({x.back(), +1, ll(1e9), 1});

        list<vll> l(all(v));

        ll res = 0;
        vll y;

        while(m){
            for(auto it = l.begin(); it != l.end() && m;){
                auto & vv = *it;

                res += vv[3];

                y.pb(vv[0] + vv[1] * vv[3]);

                vv[3]++;
                m--;

                if(vv[3] > vv[2]){
                    it = l.erase(it);
                } else {
                    ++it;
                }
            }
        }

        soa(y);

        print res;
        answer(y, out);
	}
};
