//
// Created by admin on 2022/1/30.
//

#include <mutex>
#include <shared_mutex>
#include <vector>

int main()
{
	std::mutex allIssuesMx;
	std::timed_mutex openIssuesMx;
	{
		std::scoped_lock lg(allIssuesMx, openIssuesMx);
		// do something
	}

	std::vector<int> vec{ 1, 2, 3 };
	std::shared_mutex vmutex;
	if (std::shared_lock sl(vmutex);vec.size() > 0)
	{

	}

	{
		std::scoped_lock sl(vmutex);
	}
}
