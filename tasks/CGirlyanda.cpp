#include <iostream>

#include "../library/lib.hpp"
#include "../library/itersame.h"


class CGirlyanda
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll n = read_ll();
		auto v = read_vll(n);

		if(n == 1){
			print 0;
			return;
		}

		if(count(all(v), 0) == n){
			print 1;
			return;
		}

		vvll dr;

		set<ll> s0;
		set<ll> s1;

		forn1(i, n + 1){
			if(i % 2)
				s1.insert(i);
			else
				s0.insert(i);
		}

		itersameall(v, {
			if(*b == 0 && b > v.begin() && e < v.end()){
				if(*(b - 1) % 2 == *e % 2){
					vll f(3);

					f[0] = e - b;
					f[1] = b - v.begin();
					f[2] = *(b - 1);

					dr.pb(f);
				}
			}

			if(*b != 0){
				if(*b % 2)
					s1.erase(*b);
				else
					s0.erase(*b);
			}
		});




		sort(all(dr));

//		dbg(s0, s1);
//		dbg(dr);

		forr(d, dr){
			if(d[2] % 2 && d[0] <= s1.size()){
				forlr(i, d[1], d[1] + d[0]){
					v[i] = *s1.begin();
					s1.erase(s1.begin());
				}
			}

			if(d[2] % 2 == 0 && d[0] <= s0.size()){
				forlr(i, d[1], d[1] + d[0]){
					v[i] = *s0.begin();
					s0.erase(s0.begin());
				}
			}
		}

		dr.clear();

//		dbg(v);

		if(v[0] == 0)
		{
			forn(i, n)
			{
				if (v[i] != 0)
				{
					vll f(3);

					f[0] = i;
					f[1] = 0;
					f[2] = v[i];

					dr.pb(f);

					break;
				}
			}
		}

		if(v[n - 1] == 0)
		{
			nfor(i, n)
			{
				if (v[i] != 0)
				{
					vll f(3);

					f[0] = n - i - 1;
					f[1] = i + 1;
					f[2] = v[i];

					dr.pb(f);

					break;
				}
			}
		}

		sort(all(dr));

//		dbg(v);
//		dbg(dr);
//		dbg(s0, s1);

		forr(d, dr){
			if(d[2] % 2 && d[0] <= s1.size()){
//				print "asd";
//				dbg(d);

				forlr(i, d[1], d[1] + d[0]){
					v[i] = *s1.begin();
					s1.erase(s1.begin());
				}
			}

			if(d[2] % 2 == 0 && d[0] <= s0.size()){
//				print "sg";
//				dbg(d);

				forlr(i, d[1], d[1] + d[0]){
					v[i] = *s0.begin();
					s0.erase(s0.begin());
				}
			}
		}

//		dbg(v);


//		dbg(s0, s1);

		while(s0.size() || s1.size()){
			forn1(i, n){
				if(v[i] == 0 && v[i - 1] != 0){
					if(v[i - 1] % 2){
						if(s1.size()){
							v[i] = *s1.begin();
							s1.erase(s1.begin());
						} else {
							v[i] = *s0.begin();
							s0.erase(s0.begin());
						}
					} else {
						if(s0.size()){
							v[i] = *s0.begin();
							s0.erase(s0.begin());
						} else {
							v[i] = *s1.begin();
							s1.erase(s1.begin());
						}
					}
				}
			}

			nfor1(i, n){
				if(v[i] == 0 && v[i + 1] != 0){

					if(v[i + 1] % 2){
						if(s1.size()){
							v[i] = *s1.begin();
							s1.erase(s1.begin());
						} else {
							v[i] = *s0.begin();
							s0.erase(s0.begin());
						}
					} else {
						if(s0.size()){
							v[i] = *s0.begin();
							s0.erase(s0.begin());
						} else {
							v[i] = *s1.begin();
							s1.erase(s1.begin());
						}
					}
				}
			}
		}

//		dbg(v);

		ll ans = 0;

		forn1(i, n){
			if(v[i] % 2 != v[i - 1] % 2)
				ans++;
		}

		print ans;
	}
};
