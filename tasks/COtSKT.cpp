#include <iostream>

#include "../library/lib.hpp"

class COtSKT
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();

		forn(_, q)
		{
			auto s = read_s();
			auto t = read_s();
			auto p = read_s();

			if(s.size() > t.size())
			{
				print "NO";
				continue;
			}

			vll cnt(26);

			ll ti = 0;

			bool bad = false;

			forn(i, s.size())
			{
				auto next = t.find(s[i], ti);
				if(next == string::npos)
				{
					bad = true;
					break;
				}

//				print "next", next;
				
				forlr(j, ti, next)
				{
					cnt[t[j] - 'a']++;
				}

				ti = next + 1;
			}

			if(bad)
			{
				print "NO";
				continue;
			}

			forlr(j, ti, t.size())
			{
				cnt[t[j] - 'a']++;
			}


//			print cnt;

			forr(c, p)
			{
				cnt[c - 'a']--;
			}

			print *max_element(all(cnt)) > 0 ? "NO" : "YES";
		}
	}
};
