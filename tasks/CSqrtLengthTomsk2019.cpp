#include <iostream>

#include "../library/lib.hpp"

class CSqrtLengthTomsk2019
{
public:
	void solve(std::istream& in, std::ostream& out)
	{
		auto s = read_s();

		string s1, s2;
		
		if(s.find('.') == string::npos){
			s1 = s;
			s2 = "";
		} else {
			s1 = s.substr(0, s.find('.'));
			s2 = s.substr(s.find('.') + 1);
		}

		double d = stod(s1 + s2);
		ll l = round(sqrt(d));

		if(l * l != stoll(s1 + s2)) {
			print -1;
		} else {
			ll v1 = to_string(l).size();
			ll v2 = s2.size() / 2 + 1;
			print max(v1, v2);
		}
	}
};
