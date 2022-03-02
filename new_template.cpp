//
// Created by Fushenshen on 2022/1/30.
//
#include <iostream>
#include <string>

template<typename... T>
auto foldSumL(T... args)
{
	return (0 + ... + args); // ((arg1 + arg2) + arg3)...
}

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


//void foo(int a)
//{
//	print("int");
//}
//
//void foo(const char* a)
//{
//	print("const char*");
//}
//
//void foo(double a)
//{
//	print("double");
//}

//template<typename... Types>
//void callFoo(const Types& ... args)
//{
//	(..., foo(args));
//}

/**
 * 折叠基类的使用
 */

template<typename... Bases>
class MultiBase : private Bases ...
{
public:
	void print()
	{
		(..., Bases::print());
	}
};

struct A
{
	void print()
	{
		std::cout << "A::print()\n";
	}
};

struct B
{
	void print()
	{
		std::cout << "B::print()\n";
	}
};

struct C
{
	void print()
	{
		std::cout << "C::print()\n";
	}
};


template<typename T1, typename ...TN>
constexpr bool isHomogeneous(T1, TN...)
{

	return (std::is_same_v<T1, TN>, ...);
}

int main312()
{
	auto sum = foldSumL(1, 2, 3, 4);
	printf("sum: %d\n", sum);
	print(1, 2, 3, 'c', "ddd", 3.f);
//	callFoo(1.0, "ss", 3);
	MultiBase<A, B, C> mb;
	mb.print();

	bool is_equal = isHomogeneous(43, -1);
	return 0;
}

template<typename T>
std::string asString(T x)
{
	if constexpr(std::is_same_v<T, std::string>)
	{
		return x;
	}
	else if constexpr(std::is_arithmetic_v<T>)
	{
		if (x > 10)
		{
			return std::to_string(x + 10);
		}
		return std::to_string(x);
	}
	else
	{
		return std::string(x);
	}
}

class Demo2
{

};


template<typename T>
std::string asString2(T x)
{
	if constexpr(std::is_same_v<T, std::string>)
	{
		return x;
	}
	else if constexpr(std::is_arithmetic_v<T>)
	{
		return std::to_string(x);
	}
	else
	{
		return std::string(x);
	}
}

template<typename T>
constexpr auto bar(const T& val)
{
	if constexpr (std::is_integral<T>::value && T{} < 10)
	{
		return val * 2;
	}
	return val;
}

double foo(double a)
{
	return 2.0;
}

template<typename T>
void bar2(const T x)
{
	if constexpr (auto obj = foo(x); std::is_same_v<decltype(obj), T>)
	{
		std::cout << "foo(x) yields same type\n";
	}
	else
	{
//		static_assert(false, "no integral");
		std::cout << "foo(x) yields different type\n";
	}
}

int main()
{
	if constexpr(std::numeric_limits<unsigned char>::is_signed)
	{
		print("yes");
	}
	print(bar(3));
	bar2(2.0);
}