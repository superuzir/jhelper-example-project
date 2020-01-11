#include <iostream>

#include "../library/lib.hpp"

class BGiperset
{
	static string merge(const string& a, const string& b){
		string ans = a;

		forn(i, a.size()){
			if(a[i] == 'S' && b[i] == 'E') ans[i] = 'T';
			if(a[i] == 'E' && b[i] == 'S') ans[i] = 'T';
			if(a[i] == 'T' && b[i] == 'S') ans[i] = 'E';
			if(a[i] == 'S' && b[i] == 'T') ans[i] = 'E';
			if(a[i] == 'E' && b[i] == 'T') ans[i] = 'S';
			if(a[i] == 'T' && b[i] == 'E') ans[i] = 'S';
		}

		return ans;
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();

		auto v = read_vs(n);
		auto s = unordered_set<string>(all(v));

		set<set<string>> ss;

		forn(i, n){
			forlr(j, i + 1, n){
				auto m = merge(v[i], v[j]);

//				dbg(v[i], v[j], m, s.count(m));

				if(s.count(m))
				{
					ss.insert({v[i], v[j], m});
				}
			}
		}

		print ss.size();
	}
};
