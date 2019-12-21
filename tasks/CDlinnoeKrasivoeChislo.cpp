#include <iostream>

#include "../library/lib.hpp"

class CDlinnoeKrasivoeChislo
{
	string inc(string f){

		ll per = 0;

		f.back()++;
		if(f.back() > '9')
		{
			f.back() = '0';
			per = 1;
		}

		nfor(i, f.size() - 1){
			f[i] = f[i] + per;
			if(f[i] > '9'){
				f[i] = '0';
				per = 1;
			} else {
				per = 0;
			}
		}

		if(per)
			f = "1" + f;

		return f;
	}

	bool more(string a, string b){
		ll n = a.size();

		forn(i, n){
			if(a[i] < b[i])
				return false;

			if(a[i] > b[i])
				return true;
		}

		return false;
	}

	bool less(string a, string b){
		ll n = a.size();

		forn(i, n){
			if(a[i] > b[i])
				return false;

			if(a[i] < b[i])
				return true;
		}

		return false;
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		ll k = read_ll();
		auto s = read_s();

		auto f = s.substr(0, k);

		forn(i, k - (n % k)){
			s += '0';
		}

		bool all = true;

		for (ll i = k; i < n; i += k)
		{
			auto sub = s.substr(i, k);

			if(less(sub, f)){
				break;
			}

			if(more(sub, f))
			{
				all = false;
				break;
			}
		}

//		dbg(inc("1"));
//		dbg(inc("9"));
//		dbg(inc("98"));
//		dbg(inc("99"));
//		dbg(inc("1999"));
//		dbg(inc("100"));
//		dbg(inc("234"));
//		dbg(inc("239"));
//
//		dbg(less("100", "200"));
//		dbg(less("5", "6"));
//		dbg(less("6", "6"));
//		dbg(less("6", "5"));
//		dbg(less("5", "0"));
//		dbg(less("0", "5"));


		if(!all)
			f = inc(f);

		string ans;

		forn(i, n){
			ans += f[i % k];
		}

		print ans.size();
		print ans;
	}
};
