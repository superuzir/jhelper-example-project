#include <iostream>

#include "../library/lib.hpp"

class BJOENaTelevidenii
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
        ll n = read_ll();

        double ans = 0;

        forrl(i, 1, n + 1){
            ans += 1.0 / i;
        }

        printf("%.12f\n", ans);
	}
};
