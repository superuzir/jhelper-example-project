template<class ForwardIt, class T> ForwardIt static binsearch(ForwardIt first, ForwardIt last, const T& value)
{
	first = std::lower_bound(first, last, value);

	if(first == last) return last;

	return *first == value ? first : last;
}
