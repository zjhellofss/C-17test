//
// Created by admin on 2022/1/29.
//
#include <any>
#include <string>
#include <vector>
#include <iostream>
#include <string_view>

std::string getStr()
{
	return "gexxxtStr";
}

class Demo2
{
	std::string name = "name";
public:
	std::string_view getName() const
	{
		return name;
	}
};

std::string operator+(std::string_view sv1, std::string_view sv2)
{
	return std::string(sv1) + std::string(sv2);
}

template<typename T>
auto concat(const T& x, const T& y)
{
	return x + y;
}


int main()
{
	auto func = std::string("func");
	std::string_view sv = func;
	func = "axas";
	auto res2 = concat(sv,sv);
	std::any a; // a为 空
	std::any b = 4.3; // b有 类 型 为double的 值4.3
	a = 42; // a有 类 型 为int的 值42
	b = std::string{ "hi" };

//	b = 32;

//	auto s = std::any_cast<std::string&>(b);
//	s = "demo";
//	auto s2  = std::any_cast<std::string>(b);
//
//	std::string str3 = "hello";
//	auto p = std::any_cast<std::string>(&str3);


	std::vector<std::any> v;
	v.push_back(42);
	std::string s = "hello";
	v.push_back(s);
	for (const auto& a: v)
	{
		if (auto pa = std::any_cast<const std::string>(&a); pa != nullptr)
		{
			std::cout << "string: " << *pa << '\n';
		}
		else if (auto pa = std::any_cast<const int>(&a); pa != nullptr)
		{
			std::cout << "int: " << *pa << '\n';
		}
	}
	std::any any_string = std::string("demo");
	std::any_cast<std::string&>(any_string) = "world";
	if (auto p = std::any_cast<std::string>(&any_string); p != nullptr)
	{
		std::cout << *p << std::endl;
	}
	std::cout << sv << "\n";

	return 0;
}