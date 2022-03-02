//
// Created by admin on 2022/1/29.
//
#include <optional>
#include <string>
#include <iostream>
#include <set>
#include <cstring>
#include <variant>
#include <vector>

std::optional<int> asInt(const std::string& s)
{
	try
	{
		return std::stoi(s);
	}
	catch (...)
	{
		return std::nullopt;
	}
}

class Demo
{
public:
	virtual ~Demo()
	{
		if (this->arr_ != nullptr)
		{
			delete[] arr_;
			this->arr_ = nullptr;
		}
	}

	Demo()
	{
		std::cout << "Demo()" << std::endl;
		this->arr_ = new int[32];
	}

	Demo(const Demo& demo)
	{
		std::cout << "Demo(const Demo& demo)" << std::endl;
		this->arr_ = new int[32];
		memcpy(this->arr_, demo.arr_, sizeof(int) * 32);
	}

	Demo(Demo&& demo)
	{
		std::cout << "Demo(Demo&& demo)" << std::endl;
		this->arr_ = demo.arr_;
		demo.arr_ = nullptr;
	}

	Demo operator=(Demo&& demo)
	{
		std::cout << "Demo operator=(Demo&& demo)" << std::endl;
		this->arr_ = demo.arr_;
		return *this;
	}

	int* getArr() const
	{
		return this->arr_;
	}

private:
	int* arr_ = nullptr;
};

auto getDemo()
{
	std::optional<Demo> demo(Demo{});
	return demo;
}

int main312()
{
//	for (auto s: { "42", " 077", "hello", "0x33" })
//	{
//		std::optional<int> oi = asInt(s);
//		if (oi)
//		{
//			std::cout << "convert: " << *oi << std::endl;
//		}
//	}
	auto ptr = getDemo()->getArr();
	return 0;
}

int mai12n()
{
	std::optional<std::string> opt_str;
	std::optional<const char*> opt_charp("hello");
	if (!opt_str.has_value())
	{
	}

	std::variant<float, double> v5{ 42.3f };
	int index = v5.index();
	auto sc = [](int x, int y)
	{
		return std::abs(x) < std::abs(y);
	};
	std::variant<std::vector<int>, std::set<int, decltype(sc)>>
			v15{ std::in_place_index<1>, { 4, 8, -7, -2, 0, 5 }, sc };

	int index2 = v15.index();


	std::variant<std::monostate, int, std::string> v1, v2{ "hello" }, v3{ 42 };
	std::variant<std::monostate, std::string, int> v4;
	v2.emplace<2>("hi");

	using IntOrDouble = std::variant<int, double>;
	std::vector<IntOrDouble> coll{ 42, 7.7, 0, -0.7 };
	double sum{ 0 };
	for (const auto& elem: coll)
	{
		std::visit([](const auto& val)
		{
			if (std::is_same_v<std::string, decltype(val)>)
			{

			}
		}, elem);
	}
	return 0;
}

int main()
{
	std::variant<std::monostate, std::string , int> v2; // OK
	std::cout << "index: " << v2.index() << '\n';

}