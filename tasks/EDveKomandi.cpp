#include <iostream>

#include "../library/lib.hpp"

class EDveKomandi
{
public:

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();
		vll vec = read_vll(n);
		vpll prig(n, {-1, -1});

		vll um(n);

		string ans(n, '-');

		forn(i, n)
		{
			um[vec[i] - 1] = i;
		}

//		print um;
		
		char cmd = '1';
		
		nfor(i, n)
		{
			ll from = um[i];
			
			if(ans[from] != '-')
				continue;

			ll right_k = 0;
			ll right = from;

			ans[from] = cmd;
			
			for (ll j = from + 1; j < n && right_k < k; ++j)
			{
				if(ans[j] != '-')
					j = prig[j].se;
				else
				{
					ans[j] = cmd;
					right_k++;
				}

				right = j;
			}

			ll left_k = 0;
			ll left = from;

			for (ll j = from - 1; j >= 0 && left_k < k; --j)
			{
				if(ans[j] != '-')
					j = prig[j].fi;
				else
				{
					ans[j] = cmd;
					left_k++;
				}

				left = j;
			}
			
			prig[left] = {-1, right};
			prig[right] = {left, -1};

			cmd = cmd == '1' ? '2' : '1';
		}
		
//		print prig;
		print ans;
	}
};
