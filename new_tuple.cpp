#include <iostream>
#include <string>
#include <utility>

struct MyStruct
{
	int i = 0;
	std::string s;
};
MyStruct ms{ 1, "hello" };

class Customer
{
private:
	std::string first;
	std::string last;
	long val;
public:
	Customer(std::string f, std::string l, long v)
			: first{ std::move(f) }, last{ std::move(l) }, val{ v }
	{
	}

	std::string getFirst() const
	{
		return first;
	}

	std::string getLast() const
	{
		return last;
	}

	long getValue() const
	{
		return val;
	}
};

template<>
struct std::tuple_size<Customer>
{
	static constexpr int value = 3;
};

template<>
struct std::tuple_element<2, Customer>
{
	using type = long; // 最 后 一 个 属 性 的 类 型 是long
};
template<std::size_t Idx>
struct std::tuple_element<Idx, Customer>
{
	using type = std::string; // 其 他 的 属 性 都 是string
};

// 定 义 特 化 的getter：
template<std::size_t>
auto get(const Customer& c);

template<>
auto get<0>(const Customer& c)
{
	return c.getFirst();
}

template<>
auto get<1>(const Customer& c)
{
	return c.getLast();
}

template<>
auto get<2>(const Customer& c)
{
	return c.getValue();
}

int main()
{
	Customer c{"Tim", "Starr", 42};
	const auto& [f, l, v] = c;

//	auto[m, v] = ms;
//	auto &&[v, n] = std::move(ms);
//	std::cout << ms.s << std::endl;
	return 0;
}
