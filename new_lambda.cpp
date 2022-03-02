//
// Created by admin on 2022/1/29.
//

#include <array>
#include <iostream>
#include <thread>

auto hashed = [](const char* str)
{
	std::size_t hash = 5381; // 初 始 化 哈 希 值
	while (*str != '\0')
	{
		hash = hash * 33 ^ *str++; // 根 据 下 一 个 字 符 更 新 哈 希 值 }
		return hash;
	};
};


class Data
{
private:
	std::string name;
public:
	Data(const std::string& s) : name(s)
	{
	}

	auto startThreadWithCopyOfThis() const
	{
		using namespace std::literals;
		std::thread t([*this]
		{
			std::this_thread::sleep_for(3s);
			std::cout << name << '\n';
		});
		return t;
	}
};


class C
{
private:
	std::string name_;
public:
	void bar() const
	{
		printf("bar....\n");
	}

	void foo()
	{
		auto l1 = [this_copy = *this]
		{
			this_copy.bar();
		};
		l1();

		auto l2 = [this]
		{
			this->bar();
		};
	}
};

enum Myint : char
{
};

int main()
{
	auto d {1, 2, 3};
	Myint ch{'c'};
	C c;
	c.foo();
	Data data("data");
	auto t = data.startThreadWithCopyOfThis();
	t.join();
	return 0;
}

int main33()
{
	auto squared = [](auto val) constexpr
	{
		return val * val;
	};
	std::array<int, squared(3)> array;
	std::cout << array.size() << "\n";


	enum Hashed
	{
		beer = hashed("beer"),
		wine = hashed("wine"),
		water = hashed("water"),
	};

}
