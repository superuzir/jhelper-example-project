#include <iostream>

#include "../library/lib.hpp"

class CSdelaiKvadrat
{
public:
	ll subseq(ll seq, ll sub)
	{
		string str1 = to_string(seq);
		string str2 = to_string(sub);
		
		int j = 0;
		
		for (int i = 0; i < str1.size() && j < str2.size(); i++)
			if (str1[i] == str2[j])
				j++;

		if(j == str2.size())
			return str1.size() - str2.size();
		else
			return max_ll;
	}

	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vll quad;

		for(ll i = 1; i * i <= n; i++)
		{
			quad.pb(i * i);
		}

		ll ans = max_ll;

		nfor(i, quad.size())
		{
			ans = min(ans, subseq(n, quad[i]));
		}
		
		print ans == max_ll ? -1 : ans;
	}
};
