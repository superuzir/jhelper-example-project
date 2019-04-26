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
	
	bool isBegin(string s)
	{
		if(s[0] == ')')
			return false;
		
		ll op = 0;
		
		forr(c, s)
		{
			if(c == '(')
				op++;
			else
				op--;
			
			if(op < 0)
				return false;
		}
		
		return true;
	}

	bool isEnd(string s)
	{
		if(s.back() == '(')
			return false;

		ll op = 0;

		nfor(i, s.size())
		{
			char c = s[i];
			
			if(c == ')')
				op++;
			else
				op--;

			if(op < 0)
				return false;
		}

		return true;
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vs str = read_vs(n);

		multiset<ll> set;
		
		ll balanced = 0;

		forr(s, str)
		{
			bool beg = isBegin(s);
			bool end = isEnd(s);
			
			if(beg)
				set.insert(balance(s));
			else if(end)
				set.insert(balance(s));
		}

		ll ans = 0;

		while(set.size())
		{
			ll a = *set.begin();
			set.erase(set.begin());

			if(auto b = set.find(-a); b != set.end())
			{
				set.erase(b);
				ans++;
			}
		}

		print ans;
	}
};
