//
// Created by Fushenshen on 2022/1/30.
//

#include <utility>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

struct Demo
{
	int x, y;
};

template<typename CB>
class CountCalls
{
private:
	CB callback;
	long calls = 0;
public:
	CountCalls(CB cb) : callback(cb)
	{
	}

	template<typename... Args>
	decltype(auto) operator()(Args&& ... args)
	{
		++calls;
		return callback(std::forward<Args>(args)...);
	}

	long count() const
	{
		return calls;
	}
};

int ma312in()
{
	std::vector v{ 1, -22, 2, 3, -1, 99, -31 };
	CountCalls sc{ [](auto x, auto y)
				   { return x > y; }};
	for (int i = 0; i < 10; ++i)
	{
		std::sort(v.begin(), v.end(),
				std::ref(sc));
	}
	std::cout << "sorted with " << sc.count() << " calls\n";
	return 0;
}

class People
{
public:
	People(const std::string name) : name_(name)
	{

	}

	std::string getName() const
	{
		return this->name_;
	}

private:
	std::string name_;
};

int mai312n()
{
	auto compare_func = [](const People& x, const People& y)
	{
		return x.getName() > y.getName();
	};
	std::set<People, decltype(compare_func)> coll(compare_func);
	People p0("a1a12");
	coll.insert(p0);
	People p1("n112");
	coll.insert(p1);
	People p2("a21122");
	coll.insert(p2);
	People p4("a112");
	coll.insert(p4);

	return 0;
}


template<typename T>
struct S
{
	T val;
};
S(const char*) -> S<std::string>;

template<typename T>
struct A
{
	T val;
};

A(const char*)->A<std::string>;
A(int)->A<int>;


template<typename T1, typename T2>
struct Pair2
{
	T1 first;
	T2 second;

	Pair2(const T1& x, const T2& y) : first{ x }, second{ y }
	{
	}
};

//template<typename T1, typename T2>
//Pair2(T1, T2) -> Pair2<T1, T2>;


template<typename T>
struct C1
{
	C1(const T&)
	{
	}
};

int main()
{
	C1 c(31);
	std::vector v4("hi", "world");
}


int mai123n()
{
	Pair2 p3{ 1, 2 };
	S s{ "hello" };
	A s2{ "hi" };
	A s3{ 31 };
	return 0;
}