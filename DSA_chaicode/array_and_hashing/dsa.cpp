#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

//===========Arrays & hashing=======
// two sum(unsorted): approach --> a seen map that stores the elements once the pointer goes over it after that we can just minus it from the target and look if the needed variable is present in the map

vector<int> twoSumUnsorted(vector<int> arr, int target)
{
    // given arr, target;  seen ← {}   // value → index
    unordered_map<int, int> seen;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int need = target - arr[i]; // subtract the current element from the target to lookup the needed element
        // if need in seen:
        if (seen.find(need) != seen.end())
        { // basically if the current is not equal to the end of the map then it's present so return it
            // return (seen[need], i)
            return {seen[need], i}; // seen[need] is the element value and i is the index of element in the array
        }
        // seen[arr[i]] ← i
        seen[arr[i]] = i; // store the current element in the map with its index
    }
    return {};
}

int main()
{

    // twoSum hashing
    vector<int> arr = {2, 7, 11, 15};
    int target = 18;

    vector<int> result = twoSumUnsorted(arr, target);

    if (!result.empty())
    {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    }
    else
    {
        cout << "No pair found" << endl;
    }

    return 0;
}