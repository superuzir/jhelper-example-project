#include <iostream>

#include "../library/lib.hpp"
#include "../library/matrix.h"


class DZadachaMinimaks
{
public:
    bool check(std::ostream& out, ll n, ll m, const vector<uint8_t> &vb, const unordered_set<uint8_t> &set) const {
//        dbg(vb);
        forn(i, n) {
            forn1(b, 1 << m) {
//                dbg(i, b, vb[i], vb[i] | b);
                if((vb[i] | b) == (1 << m) - 1 && set.count(b)){
                    return true;
                }
            }
        }

        return false;
    }


    void solve(std::istream& in, std::ostream& out)
	{
        ll n = read_ll();
        ll mm = read_ll();
        auto v = read_mll(n, mm);

        vvll comp(256);

//        forn(i, 1 << mm){
//            forn(j, 1 << mm){
//                if((i | j) == (1 << mm)
//            }
//        }

        ll mx = -1;

        ll l = 0;
        ll r = 1e9 + 1;

        while(l < r){
            ll m = (l + r) / 2;

            vector<uint8_t> vb;
            unordered_set<uint8_t> set;

            forn(i, n){
                uint8_t b = 0;

                forn(j, mm){
                    if(v[i][j] > m)
                        b |= 1 << j;
                }

                vb.pb(b);
                set.insert(b);
            }

//            dbg(m, vb);

            if(!check(out, n, mm, vb, set)){
                r = m;
            } else {
                mx = max(mx, m);
                l = m + 1;
            }
        }

//        print mx;

        if(mx == -1){
            print 1, 1;
            return;
        }

        vector<uint8_t> vb;
        unordered_map<uint8_t, vll> map;

        forn(i, n){
            uint8_t b = 0;

            forn(j, mm){
                if(v[i][j] > mx)
                    b |= 1 << j;
            }

            vb.pb(b);
            map[b].pb(i);
        }

        forn(i, n) {
            forn1(b, 1 << mm) {
//                dbg(i, b, vb[i], vb[i] | b);
                if((vb[i] | b) == (1 << mm) - 1 && map.count(b) && !map[b].empty()){
                    print i + 1, map[b].front() + 1;

                    return;
                }
            }
        }

	}
};
