#include <iostream>

#include "../library/lib.hpp"

class C1VozrastayushayaPodposledovatelnostUproshennayaVersiya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll vec = read_vll(n);

		ll l = 0;
		ll r = vec.size() - 1;

		ll last = 0;
		string ans ;



		while(l <= r)
		{
			ll vl = vec[l];
			ll vr = vec[r];

			if(vl > last && vr > last)
			{
				if(vl < vr)
				{
					last = vl;
					l++;
					ans += 'L';
				}
				else
				{
					last = vr;
					r--;
					ans += 'R';
				}
			}
			else if(vl > last)
			{
				last = vl;
				l++;
				ans += 'L';
			}
			else if(vr > last)
			{
				last = vr;
				r--;
				ans += 'R';
			}
			else
			{
				break;
			}
		}

		print ans.size();
		print ans;
	}
};
