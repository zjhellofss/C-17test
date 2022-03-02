//
// Created by admin on 2022/1/29.
//

#include <string>

class Base
{
public:
	virtual void foo() noexcept = 0;
};

class Derived : public Base
{
public:
	void foo() noexcept
	{

	}
};

int main()
{
	Derived d;
	d.foo();
}