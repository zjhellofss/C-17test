//
// Created by admin on 2022/1/29.
//
#include <string>

class [[deprecated]] MyContainer
{
public:
	[[nodiscard]] bool empty() const noexcept
	{
		return true;
	}

	void insert(int a, [[maybe_unused]] std::string message)
	{

	}
};

int main()
{
	MyContainer container;
	container.empty();
	container.insert(3,"hello");
}