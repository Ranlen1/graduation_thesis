#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int sizeOfArray;
    std::cin >> sizeOfArray;
    std::vector<int> arr(sizeOfArray);

    for(int i = 0; i < sizeOfArray; ++i)
        std::cin >> arr[i];

    std::sort(arr.begin(), arr.end());

    for(int i : arr)
        std::cout << i << " \n";

    return 0;
}
