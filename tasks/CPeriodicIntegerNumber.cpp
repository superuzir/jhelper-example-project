#include <iostream>

#include "../library/lib.hpp"

class CPeriodicIntegerNumber
{
public:
	string getString(string s) const
	{
		s.back()++;
		nfor(i, s.size())
		{
			if(s[i] == '9' + 1){
				s[i] = '0';
				s[i - 1]++;
			}
		}
		return s;
	}

	void solve(std::istream& in, std::ostream& out)
	{
		ll l = read_ll();
		auto s = read_s();

		if(s.size() == l)
		{
			if(all_of(all(s), [](char c){ return c == '9'; })) {
				forn(_, s.size() / l + 1) {
					out << '1';
					forn(__, l - 1)
						out << '0';
				}
				out << endl;
			} else {
				s = getString(s);
				print s;
			}
		} else if(s.size() % l){
			forn(_, s.size() / l + 1) {
				out << '1';
				forn(__, l - 1)
					out << '0';
			}
			out << endl;
		} else if(all_of(all(s), [](char c){ return c == '9'; })) {
			forn(_, s.size() / l + 1) {
				out << '1';
				forn(__, l - 1)
					out << '0';
			}
			out << endl;
		} else {
			auto fi = s.substr(0, l);

			ll willinc = 0;

			forn1(i, s.size() / l){
				auto sub = s.substr(i * l, l);
				if(sub >= fi)
					willinc++;
			}

			if(willinc < s.size() / l - 1){
				forn(i, s.size() / l)
					out << fi;
				out << endl;
			} else {
				auto incs = getString(fi);

				forn(i, s.size() / l)
					out << incs;
				out << endl;
			}
		}
	}
};
