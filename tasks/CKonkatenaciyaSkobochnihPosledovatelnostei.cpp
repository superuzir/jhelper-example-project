#include <iostream>

#include "../library/lib.hpp"

class CKonkatenaciyaSkobochnihPosledovatelnostei
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

		map<ll, ll> map;

		forn(i, n)
		{
			string s = read_s();

			if(isBegin(s) || isEnd(s))
				map[balance(s)]++;
		}
		
		ll ans = 0;
		
		while(map.size())
		{
			auto a = *map.begin();
			map.erase(map.begin());
			
			if(a.fi == 0)
				ans += a.se * a.se;
			else
			{
				auto b = map.find(-a.fi);
				if(b != map.end())
				{
					ans += a.se * b->se;
					map.erase(b);
				}
			}
		}
		
		print ans;
	}
};
