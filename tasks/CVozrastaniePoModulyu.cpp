#include <iostream>

#include "../library/lib.hpp"

class CVozrastaniePoModulyu
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll m = read_ll();
		vll vec = read_vll(n);

		if(n == 1)
		{
			print 0;
			return;
		}
		
		vll minr(n, vec[n - 1]);
		
		nfor1(i, n)
		{
			minr[i] = min(vec[i], minr[i + 1]);
		}

		ll bonus = 0;

		{
			ll up = vec[0] - (minr[1] + bonus);
			ll cyc = m - vec[0];

			if(cyc < up)
			{
				bonus += cyc;
				vec[0] = 0;
			}
			
			print 0, vec;
		}
		
		forn1(i, n - 1)
		{
			if(vec[i] > minr[i + 1] + bonus)
			{
				ll up = vec[i] - (minr[i + 1] + bonus);
				ll cyc = (vec[i - 1] + m - vec[i]) % m;
				
				print cyc, up;
				
				if(cyc < up)
				{
					bonus += cyc - bonus;
					vec[i] = vec[i - 1];
				}
			}
			
			print i, vec;
		}
		
		if(vec[n - 1] < vec[n - 2])
		{
			bonus += max(0ll, vec[n - 2] - vec[n - 1] - bonus);
		}
		
		print bonus;
	}
};
