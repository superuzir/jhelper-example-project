#include <iostream>

#include "../library/lib.hpp"

class AKheshirovaniePeremeshivaniem
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll q = read_ll();
		
		forn(_, q){
			auto p = read_s();
			auto h = read_s();
			
			if(p.size() > h.size()){
				print "NO";
				continue;
			}
			
			soa(p);
			
			string ans = "NO";
			
			forn(i, h.size() - p.size() + 1){
				auto ps = h.substr(i, p.size());
				
				soa(ps);
				
				if(p == ps)
				{
					ans = "YES";
					break;
				}
			}
			
			print ans;
		}
	}
};
