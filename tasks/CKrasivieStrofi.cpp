#include <iostream>

#include "../library/lib.hpp"

class CKrasivieStrofi
{
	static ll vowcnt(const string &a)
	{
		string w = "aeuoi";

		ll c1 = 0;
		forr(c, w) c1 += count(all(a), c);

		return c1;
	}

	static char lastvow(const string &a)
	{
		auto pos = a.find_last_of("aeuoi");
		return pos == string::npos ? '_' : a[pos];
	}

	struct my_compare
	{
		bool operator()(const string &a, const string &b)
		{
			ll c1 = vowcnt(a);
			ll c2 = vowcnt(b);

			char v1 = lastvow(a);
			char v2 = lastvow(b);

			if(v1 != v2)
				return v1 < v2;

			return c1 < c2;
		}
	};

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		vs s = read_vs(n);

//		multiset<string, my_compare> set;

		multimap<pair<char, ll>, string> map;

		forn(i, n)
		{
//			print s[i], vowcnt(s[i]), lastvow(s[i]);

			if(vowcnt(s[i]))
			{
//				set.insert(s[i]);
				map.insert(make_pair(make_pair(lastvow(s[i]), vowcnt(s[i])), s[i]));
			}
		}

//		forr(s, map)
//		{
//			print s;
//		}

		vector<vector<string>> vec_vow_cnt;
		vector<vector<string>> vec_cnt2;
		vector<string> vec_cnt;
		
		for(auto it = map.begin(); it != map.end();)
		{
			auto range = map.equal_range(it->first);

//			print it->fi;

			vector<string> vs;
			
			for(auto it = range.fi; it != range.se; ++it)
			{
				vs.pb(it->se);
				if(vs.size() == 2)
				{
					vec_vow_cnt.pb(vs);
					vs.clear();
				}
//				print *it;
			}
			
			if(vs.size())
				vec_cnt.pb(vs[0]);
				
			
			it = range.se;
		}
		
		
		multimap<ll, string> map2;
		
//		print vec_cnt;

		forr(s, vec_cnt)
		{
			map2.insert(make_pair(vowcnt(s), s));
		}

		for(auto it = map2.begin(); it != map2.end();)
		{
			auto range = map2.equal_range(it->first);

//			print *it;

			vector<string> vs;

			for(auto it = range.fi; it != range.se; ++it)
			{
				vs.pb(it->se);
				if(vs.size() == 2)
				{
					vec_cnt2.pb(vs);
					vs.clear();
				}
//				print *it;
			}

			it = range.se;
		}
		
		while(vec_vow_cnt.size() > vec_cnt2.size())
		{
			vec_cnt2.pb(vec_vow_cnt.back());
			vec_vow_cnt.pop_back();
		}


//		print vec_vow_cnt;
//		print vec_cnt2;
		
		{
			ll mn = min(vec_vow_cnt.size() ,vec_cnt2.size());
			
			print mn;
			
			forn(i, mn)
			{
				print vec_cnt2[i][0], vec_vow_cnt[i][0];
				print vec_cnt2[i][1], vec_vow_cnt[i][1];
			}
		}
	}
};
