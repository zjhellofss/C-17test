//
// Created by admin on 2022/1/30.
//

#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <map>
#include <string>

int mai331n()
{
	std::vector<int> coll{ 1, 2, 5, 1, 99, 2, 3 };
	auto size{ std::size(coll) };
	std::cout << size << " elems: ";
	auto pos{ std::begin(coll) };
	if (size > 5)
	{
		std::advance(pos, size - 5);
	}
	for (; pos != std::end(coll); ++pos)
	{
		std::cout << *pos << ' ';
	}
	std::cout << '\n';


	for (std::size_t idx{ 0 }; idx < std::size(coll); ++idx)
	{
		if (idx % 2 == 0)
		{
			std::cout << std::data(coll)[idx] << ' ';
		}
	}
	std::cout << '\n';
	return 0;
}

int mai231n()
{
	std::vector<int> coll{ 1, 2, 5, 1, 99, 2, 3 };
	[&coll = std::as_const(coll)]
	{
		std::cout << "coll: ";
		for (int elem: coll)
		{
			std::cout << elem << ' ';
		}
		std::cout << '\n';
	}();

	return 0;
}

int ma312in()
{
	std::vector<std::string> coll;
	for (int i = 0; i < 10000; ++i)
	{
		coll.push_back("value" + std::to_string(i));
	}
	std::random_device rd; // 随 机 数 种 子 （如 果 支 持 的 话）
	std::mt19937 eng{ rd() }; // Mersenne Twister引 擎
	std::vector<std::string> subset;
	subset.resize(100);
	auto end = std::sample(coll.begin(), coll.end(),
			subset.begin(),
			10,
			eng);
	std::for_each(subset.begin(), end,
			[](const auto& s)
			{
				std::cout << "random elem: " << s << '\n';
			});
	return 0;
}

template<typename T1, typename T2>
void print(const T1& coll1, const T2& coll2)
{
	std::cout << "values:\n";
	for (const auto&[key, value]: coll1)
	{
		std::cout << " [" << key << ":" << value << "]";
	}
	std::cout << "\n-----------------\n";
	for (const auto&[key, value]: coll2)
	{
		std::cout << " [" << key << ":" << value << "]";
	}
	std::cout << '\n';
}

int mai2313n()
{
	std::map<int, std::string> m{{ 1, "mango" },
								 { 2, "papaya" },
								 { 3, "guava" }};
	auto nh = m.extract(2);
	nh.key() = 4;
	m.insert(std::move(nh));
	for (const auto&[key, value]: m)
	{
		std::cout << key << ": " << value << '\n';
	}

	return 0;
}

int mai412n()
{
	std::multimap<double, std::string> src{{ 1.1, "one" },
										   { 2.2, "two" },
										   { 3.3, "three" }};
	std::map<double, std::string> dst{{ 3.3, "old data" }};

	dst.insert(src.extract(2.2));

	dst.emplace(4.4, "four");
	print(src, dst);

	return 0;
}

int main()
{

}