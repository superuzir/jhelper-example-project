
template <typename T,
		typename V = typename T::value_type,
		typename Process = typename std::function<void(V)>>
static void setBorrow(T & set, Process process)
{
	for(auto it = set.begin(); it != set.end(); ++it)
	{
		V el = *it;

		set.erase(it);

		process(el);

		it = set.insert(el);
	}
}
