//
// Created by admin on 2022/1/29.
//

#include <iostream>

struct Data
{
	std::string name;
	double value;
};
Data x = { "test1", 6.778 };
struct MoreData : Data
{
	bool done;
};


class MyClass
{
public:
	MyClass()
	{

	}

// 没 有 拷 贝/移 动 构 造 函 数 的 定 义
	MyClass(const MyClass&) = delete;

	MyClass(MyClass&&) = delete;

};

void foo(MyClass param)
{
}

MyClass bar()
{
	return MyClass{};
}

int main()
{
	MoreData data{{"name",3.14},true};
}