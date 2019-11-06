#include <iostream>

#include "../library/lib.hpp"

class B2ObmenSimvolovUslozhnennayaVersiya
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();
		forn(_, q)
		{
			ll n = read_ll();
			auto s1 = read_s();
			auto s2 = read_s();

			vll freq(26);
			forr(c, s1) freq[c - 'a']++;
			forr(c, s2) freq[c - 'a']++;

			if(all_of(all(freq), [](ll i){ return i % 2 == 0 || i == 0; })){
				print "Yes";

				vpll ans;
				
				forn(i, n){
					if(s1[i] == s2[i])
						continue;
					
					forlr(j, i + 1, n){
						if(i != j && s1[i] == s1[j]){
							swap(s1[j], s2[i]);
							ans.pb({j + 1, i + 1});
							break;
						}
						if(s1[i] == s2[j]){
							swap(s1[j], s2[j]);
							swap(s1[j], s2[i]);
							ans.pb({j + 1, j + 1});
							ans.pb({j + 1, i + 1});
							break;
						}
					}
				}
				
				print ans.size();
				forr(a, ans){
					print a.fi, a.se;
				}
			} else {
				print "No";
			}

		}
	}
};
