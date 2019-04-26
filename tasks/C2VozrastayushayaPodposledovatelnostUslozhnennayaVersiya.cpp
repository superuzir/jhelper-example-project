#include <iostream>

#include "../library/lib.hpp"

class C2VozrastayushayaPodposledovatelnostUslozhnennayaVersiya
{
	vll vec;

	string dyn(ll l, ll r, ll last)
	{
		if(l > r)
			return "";
		
		ll vl = vec[l];
		ll vr = vec[r];

		if(vl > last && vr > last)
		{
			if(vl < vr)
			{
				return dyn(l + 1, r, vl) + "L";
			}
			else if(vl > vr)
			{
				return dyn(l, r - 1, vr) + "R";
			}
			else if(vl == vr)
			{
				string ans_l = dyn(l + 1, r, vl);
				string ans_r = dyn(l, r - 1, vr);
				
				if(ans_l.size() > ans_r.size())
					return ans_l + "L";
				else
					return ans_r + "R";
			}
		}
		else if(vl > last)
		{
			return dyn(l + 1, r, vl) + "L";
		}
		else if(vr > last)
		{
			return dyn(l, r - 1, vr) + "R";
		}
		else
		{
			return "";
		}
	}


public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vec = read_vll(n);

		string ans = dyn(0, vec.size() - 1, 0);

		reverse(all(ans));

		print ans.size();
		print ans;
	}
};
