#include <iostream>

#include "../library/lib.hpp"

class CYuhaoISkobki
{
	ll balance(string s)
	{
		ll op = 0;
		ll cl = 0;

		for(char c : s)
		{
			if(c == '(') op++;
			if(c == ')') cl++;
		}

		return op - cl;
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vs str = read_vs(n);

		multiset<ll> set_l;
		multiset<ll> set_r;
		
		ll balanced = 0;

		forr(s, str)
		{
			char l = *s.begin();
			char r = *s.rbegin();
			
			if(l == ')' && r == '(')
				continue;
			else 
			{
				ll bal = balance(s);
				if(bal == 0)
					balanced++;
				else
				{
					if(l == '(' && r == '(')
						set_l.insert(bal);

					if(l == ')' && r == ')')
						set_r.insert(bal);

					if(l == '(' && r == ')')
					{
						if(bal > 0)
							set_l.insert(bal);
						else
							set_r.insert(bal);
					}
				}
			}
		}

		ll ans = balanced / 2;

		while(set_l.size())
		{
			ll a = *set_l.begin();
			set_l.erase(set_l.begin());

			if(auto b = set_r.find(-a); b != set_r.end())
			{
				set_r.erase(b);
				ans++;
			}
		}

		print ans;
	}
};
