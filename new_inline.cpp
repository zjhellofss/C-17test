//
// Created by admin on 2022/1/29.
//
#include <iostream>
#include <string>

class MyClass
{
public:
	static constexpr int n_ = 5;
};

int twice(const int& i)
{
	std::cout << "twice: " << i << "\n";
	return 0;
}

struct MyData
{
	inline static std::string gName = "global"; // 整 个 程 序 中 只 有 一 个
	inline static thread_local std::string tName = "tls"; // 每 个 线 程 有 一 个
	std::string lName = "local"; // 每 个 实 例 有 一 个
	void print(const std::string& msg) const
	{
		std::cout << msg << '\n';
		std::cout << "- gName: " << gName << '\n';
		std::cout << "- tName: " << tName << '\n';
		std::cout << "- lName: " << lName << '\n';
	}
};

inline thread_local MyData myThreadData;


int main()
{
	twice(MyClass::n_);
	const int* p = &MyClass::n_;
}
