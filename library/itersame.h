template <typename It, typename T = typename It::value_type, typename Pr = typename std::function<void(It, It)>, typename Eq = typename std::function<bool(T, T)> >
void itersame(It begin, It end, Pr process, Eq equal = std::equal_to<T>())
{
	for (auto b = begin, e = begin; e != end;)
	{
		e = find_if(b, end, [&](T pr) { return !equal(pr, *b); });
		process(b, e);
		b = e;
	}
}

#define itersameall(c, cmd) itersame(all(c), [&](auto b, auto e){ cmd })
