#include <iostream>

#include "../library/lib.hpp"

class CPrefiksiISuffiksi
{
	static bool startsWith(const string & big, const string & sub)
	{
		return big.substr(0, sub.size()) == sub;
	}

	static bool endsWith(const string & big, const string & sub)
	{
		return big.substr(big.size() - sub.size()) == sub;
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto vec = vini<string>(2*n-2, in);

		sort(all(vec), by(fi.size()));

		auto lmb = [&](string &pref1, string &pref2, string &suf1, string &suf2)
		{
			if(pref1 + suf1 == pref2 + suf2)
			{
				return pref1 + suf1;
			}
			else if(pref1 + suf2 == pref2 + suf1)
			{
				return pref1 + suf2;
			}
			return string();
		};

		auto & s1 = vec[0].fi;
		auto & s2 = vec[1].fi;
		auto & l1 = vec[vec.size() - 2].fi;
		auto & l2 = vec[vec.size() - 1].fi;

//		print startsWith("abcd", "ab");
//		print startsWith("abab", "ab");
//		print endsWith("abcd", "ab");
//		print endsWith("abab", "ab");
//		print startsWith("abab", "abab");
//		print endsWith("abab", "abab");
	
		vs ss;

		if(auto s = lmb(s1, l1, s2, l2); !s.empty()) ss.pb(s); 
		if(auto s = lmb(s1, l2, s2, l1); !s.empty()) ss.pb(s); 
		if(auto s = lmb(s2, l1, s1, l2); !s.empty()) ss.pb(s); 
		if(auto s = lmb(s2, l2, s1, l1); !s.empty()) ss.pb(s);

		forr(s, ss)
		{
			auto vec2 = vec;
			
			bool ok = true;
			
			forn(i, vec.size())
			{
				if (startsWith(s, vec[i].fi) && endsWith(s, vec[i + 1].fi))
				{
					vec[i].fi = "P";
					vec[i + 1].fi = "S";
				}
				else if (startsWith(s, vec[i + 1].fi) && endsWith(s, vec[i].fi))
				{
					vec[i + 1].fi = "P";
					vec[i].fi = "S";
				}
				else
				{
					ok = false;
				}

				i++;
			}
			
			if(!ok)
			{
				vec = vec2;
				continue;
			}
		}

		sort(all(vec), by(se));
		
		forr(p, vec)
		{
			out << p.fi;
		}
		
		out << endl;
	}
};
