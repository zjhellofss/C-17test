#include <iostream>

template<typename T, bool = std::is_pointer_v<T>>
class C
{
public:
	C()
	{
		std::cout << "C" << std::endl;
	}
};

template<typename T>
class C<T, true>
{
public:
	C()
	{
		std::cout << "Special C" << std::endl;
	}
};

template<typename T>
struct IsPtr : std::disjunction<std::is_null_pointer<T>,
		std::is_member_pointer<T>,
		std::is_pointer<T>>
{
};

int main()
{
	bool res = IsPtr<int*>::value;
	return 0;
}