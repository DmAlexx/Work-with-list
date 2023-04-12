#include <iostream>
#include <list>
#include <algorithm>

void fillList(std::list<int>& intList)
{
    for (int i = 0; i < 25; ++i)
    {
        intList.push_back(std::rand() % 15000);
    }
}

void consoleOutput(const std::list<int>& intList)
{
	for (auto& it : intList)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

void conditionDelete(std::list<int>& intList)
{
    intList.erase(std::remove_if(intList.begin(), intList.end(),
        [](int i) { return i < 1000 || i > 9999; }), intList.end());
}

int main()
{
    srand(time(0));
    std::list<int> intList;
    fillList(intList);
    std::cout << "List before sorting\n";
    consoleOutput(intList);
    intList.sort();
    std::cout << "List after sorting\n";
    consoleOutput(intList);
    conditionDelete(intList);
    std::cout << "List after deleting elements < 1000 and > 9999\n";
    consoleOutput(intList);

    return 0;
}