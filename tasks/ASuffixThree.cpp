#include <iostream>

#include "../library/lib.hpp"

class ASuffixThree
{
	bool is(const string& s, const string& suf){
		return s.substr(s.size() - suf.size()) == suf;
	}

public:
	void solve(std::istream& in, std::ostream& out)
	{
		ll t = read_ll();

		forn(_, t){
			auto s = read_s();

			if(is(s, "po"))
				print "FILIPINO";
			else if(is(s, "desu"))
				print "JAPANESE";
			else if(is(s, "masu"))
				print "JAPANESE";
			else if(is(s, "mnida"))
				print "KOREAN";
		}
	}
};
