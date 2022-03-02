//
// Created by admin on 2022/1/29.
//
#include <variant>
#include <string>
#include <vector>
#include <set>
#include <iostream>

class Base
{
public:
	virtual void Draw() = 0;
};

class Pixel1
{
public:
	void Draw() const
	{

	}
};

class Pixel2
{
public:
	void Draw() const
	{

	}
};

int main()
{
	using T = std::variant<Pixel1, Pixel2>;
	std::vector<T> vec;
	vec.push_back(Pixel1{});
	vec.push_back(Pixel2{});
	vec.push_back(Pixel1{});
	for (const auto& item: vec)
	{
		std::visit([](const auto& obj)
		{
			obj.Draw();
		}, item);
	}
	return 0;
}

int main331()
{
//	auto sc = [](int x, int y)
//	{
//		return std::abs(x) < std::abs(y);
//	};
//	std::variant<int, int, std::string> v2(std::in_place_index<1>, 23);
//
//	if (auto ip = std::get_if<1>(&v2);ip != nullptr)
//	{
//		std::cout << *ip << std::endl;
//	}
//
//	std::get<1>(v2) = 32;
//
//	if (auto p = std::get_if<0>(&v2); p)
//	{
//		*p = 42;
//	}
//
//	v2.emplace<0>(31);
//
//
//	auto printvariant = [](const auto& val)
//	{
//		std::cout << val << '\n';
//	};
//	std::visit(printvariant, v2);


//	using IntOrDouble = std::variant<int, double>;
//	std::vector<IntOrDouble> coll{ 42, 7.7, 0, -0.7 };
//	double sum{ 0 };
//	for (const auto& elem: coll)
//	{
//		sum += std::visit([](const auto& val) -> double
//		{
//			return val;
//		}, elem);
//	}


//	using Var = std::variant<int, double, std::string>;
//	std::vector<Var> values{ 42, 0.19, "hello world", 0.815 };
//	for (const Var& val: values)
//	{
//		std::visit([](const auto& v)
//		{
//			if constexpr(std::is_same_v<decltype(v), const std::string&>)
//			{
//				std::cout << '"' << v << "\" ";
//			}
//			else
//			{
//				std::cout << v << ' ';
//			}
//		}, val);
//	}
	return 0;
}
