#include <iostream>

#include "../library/lib.hpp"

const ll MOD = 1000000007;

class CDvaMassiva
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
        ll n = read_ll();
        ll m = read_ll() - 1;

        if(m == 0){
            print n * (n + 1) / 2;
            return;
        }

        vvll f(n, vll(m, 1));

        forn(j, m - 1){
            ll sum = 0;
            forn(i, n){
                sum += f[i][j];
                sum %= MOD;
                f[i][j + 1] = sum;
            }
        }

        vll s(n);

        s[0] = f[0].back();

        forn1(i, n){
            s[i] = s[i - 1] + f[i].back();
            s[i] %= MOD;
        }

        ll ans = 0;

        forn(i, n){
            forlr(j, i, n){
                ans += s[i] * s[n - j - 1];
                ans %= MOD;
            }
        }

        print ans;
	}
};
