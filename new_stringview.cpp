//
// Created by admin on 2022/1/29.
//
#include <string_view>
#include <iostream>

template<typename T>
void printElems(const T& coll, std::string_view prefix = {})
{
	for (const auto& elem: coll)
	{
		if (prefix.data())
		{
			std::cout << prefix << ' ';
		}
		std::cout << elem << '\n';
	}
}

class Demo
{

public:
	std::string_view Do()
	{
		return this->str_;
	}

private:
	std::string str_;
};

std::string getStr()
{
	return "str";
}

template<typename T>
auto concat(const T& x, const T& y)
{
	return x + y;
}

int main()
{
	auto str = Demo().Do();
	std::string str2(str);
	//	std::string str1 = "str1";
//	std::string str2 = "str2";
//
//	auto res = concat(str1, str2);
//	std::string_view hi = getStr();
//	if (hi.data())
//	{
//		std::cout << hi << std::endl;
//	}
	return 0;
}
