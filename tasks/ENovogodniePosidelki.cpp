#include <iostream>

#include "../library/lib.hpp"

class ENovogodniePosidelki
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
        ll n = read_ll();
        auto v = read_vll(n);

        soa(v);

        ll posl = 1;
        ll can = 0;
        ll can_before = 1;

        ll ans_min = 0;
        ll ans_max = 0;

        forn1(i, n){
            if(v[i - 1] == v[i]){
                can++;
            } else if(v[i - 1] + 1 == v[i]){
                posl++;
            } else if(v[i - 1] + 2 == v[i]){
                ans_min += divceil(posl, 3);

                if(can_before && can){
                    ans_max++;
                    can--;
                }

                if(can){
                    ans_max++;
                    can_before = 0;
                } else {
                    can_before = 1;
                }

                if(posl % 3 == 1){
                    posl = 0;
                } else {
                    posl = 1;
                }

                can = 0;
            } else {
                ans_min += divceil(posl, 3);

                if(can_before && can){
                    ans_max++;
                    can--;
                }

                if(can){
                    ans_max++;
                }

                can = 0;
                can_before = 1;
            }
        }

        ans_min += divceil(posl, 3);

        vll freq(n);

        forr(vv, v){
            freq[vv - 1]++;
        }

        ans_min = 0;

        forn(i, n){
            if(freq[i]){
                ans_min++;
                i += 2;
            }
        }


        if(can_before && can){
            ans_max++;
            can--;
        }

        if(can){
            ans_max++;
        }

        print ans_min, ans_max + unique(all(v)) - v.begin();
	}
};
