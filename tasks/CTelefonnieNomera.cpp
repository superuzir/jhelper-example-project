#include <iostream>

#include "../library/lib.hpp"

class CTelefonnieNomera
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();
		auto str = read_s();
		
		set<char> set;

		forr(c, str)
		{
			set.insert(c);
		}

		if(k > n)
		{
			str += string(k - n, *set.begin());
			print str;
			return;
		}
		
		string ans = str.substr(0, k);

		ll peren = 0;		
		
		nfor(i, k)
		{
			auto it = set.find(ans[i]);
			++it;
			
			if(it != set.end())
			{
				ans[i] = *it;
				for(int j = i + 1; j < k; ++j)
				{
					ans[j] = *set.begin();
				}
				
				break;
			}
		}

		print ans;
	}
};
