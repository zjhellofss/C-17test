#include <iostream>
#include <string>
#include <map>
#include <mutex>

template<typename First, typename... Args>
void print(const First& firstarg, const Args& ... args)
{
	std::cout << firstarg;
	auto spaceBefore = [](const auto& arg)
	{
		std::cout << ' ';
		return arg;
	};
	(std::cout << ... << spaceBefore(args)) << '\n';
}

class Demo
{
private:
	inline static std::string str = "demo";
};

int main()
{
	Demo d1;
	Demo e2;
	using std::string;
	if (string str = "str";!str.empty())
	{

	}
	std::mutex m;
	std::string str = "str";
	if (std::lock_guard<std::mutex>{ m };!str.empty())
	{
		print("no empty");
	}
}