#include <iostream>

#include "../library/lib.hpp"

class CPeriodicIntegerNumber
{
public:
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
	void solve(std::istream& in, std::ostream& out)
	{
		ll L = read_ll();
		auto s = read_s();

		s = inc(s);
		s = string((L - s.size() % L) % L, '0') + s;

		if(s[0] == '0'){
			string p = "1" + string(L - 1, '0');
			string ans;
			forn(i, s.size() / L){
				ans += p;
			}

			print ans;
		} else {
			string p = s.substr(0, L);

			forn1(i, s.size() / L){
				string p1 = s.substr(i * L, L);
				if(less(p1, p)){
					break;
				}
				if(more(p1, p)){
					p = inc(p);
					break;
				}
			}

			string ans;
			forn(i, s.size() / L){
				ans += p;
			}

			print ans;
		}
	}
};
