//
// Created by admin on 2022/1/29.
//
#include <chrono>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <iterator>

#include <iterator>
#include <array>

int mai312n()
{
	std::vector<std::string> coll;
	for (int i = 0; i < 10000; ++i)
	{
		coll.push_back(std::to_string(i));
	}
	for_each_n(coll.begin(), 5,
			[](auto& elem)
			{
				elem = "value" + elem;
			});
	for_each_n(coll.begin(), 10,
			[](const auto& elem)
			{
				std::cout << elem << '\n';
			});

	return 0;
}

int main3312()
{
	std::array coll{ 3, 1, 7, 5, 4, 1, 6, 3 };
// 计 算 元 素 之 和
	std::cout << "sum: "
			  << std::reduce(coll.cbegin(), coll.cend()) // 范 围
			  << '\n';
	return 0;
}

int main213()
{
	std::array coll{ 1, 2, 3, 4, 5 };
	auto twice = [](int v)
	{
		return v * 2;
	};

	auto once = [](int v)
	{
		return v * 1;
	};
	auto res1 = std::transform_reduce(coll.cbegin(), coll.cend(),
			0, std::plus{}, once);

	auto res2 = std::transform_reduce(coll.cbegin(), coll.cend(),
			0, std::plus{}, twice);

	return 0;
}

int main3123()
{
	std::array coll{ 3, 1, 7, 0, 4, 1, 6, 3 };
	std::cout << " inclusive_scan(): ";
	std::inclusive_scan(coll.begin(), coll.end(),
			std::ostream_iterator<int>(std::cout, " "), std::multiplies{}, 2);
	return 0;
}

int main12()
{
	auto vec = std::vector<int>(31);
	auto data = std::data(vec)[0];
	int* a = new int[31];
	auto sz{ std::size(vec) };
	std::array coll{ 3, 1, 7, 4, 4, 1, 6, 3 };
	auto twice = [](int v)
	{ return v * 2; };

	auto once = [](int v)
	{ return v * 1; };
	std::cout << " source: ";
	std::copy(coll.begin(), coll.end(),
			std::ostream_iterator<int>(std::cout, " "));


	std::cout << "\n transform_inclusive_scan(): ";
	std::transform_inclusive_scan(coll.begin(), coll.end(),
			std::ostream_iterator<int>(std::cout, " "),
			std::plus{}, twice);


	std::cout << "\n transform_inclusive_scan(): ";
	std::transform_inclusive_scan(coll.begin(), coll.end(),
			std::ostream_iterator<int>(std::cout, " "),
			std::multiplies{}, once, 1);
	return 0;
}

int main()
{
	std::map<int, std::string> m;
	m.insert({ 1, "str" });
	m.insert({ 2, "str2" });
	m.insert({ 1, "str2" });

	m.try_emplace(1, 8, 'c');
	m.try_emplace(3, 8, 'c');
	m.insert_or_assign(3, std::string("aaaa"));

	auto iter = m.extract(1);
	iter.mapped() = "11";
	m.insert(std::move(iter));
	return 0;
}

