#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

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

bool containsDuplicate(vector<int> arr)
{
    // again have a seen SET that stores the already seen elements
    // why a set? => Because we just need to look up the element not return it's indices or element itself
    unordered_set<int> seen;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        // check the element in the set
        if (seen.find(arr[i]) != seen.end())
        {
            return true;
        }
        // insert the element in the set
        seen.insert(arr[i]);
    }
    return false;
}

bool validAnagram(string s, string t)
{
    // find out if s and t are anagram of each other
    // first we check the length if that's not same they're definitely not anagrams
    if (s.length() != t.length())
        return false;
    unordered_map<char, int> count;

    // if a character is present in s we increase the count if also in t we decrease it
    // so if the count is less than 0 it's not an anagram
    for (char c : s)
    {
        count[c]++;
    }
    for (char c : t)
    {
        count[c]--;
        if (count[c] < 0)
            return false;
    }

    return true;
}

vector<vector<string>> groupAnagrams(vector<string> words)
{
    unordered_map<string, vector<string>> groups;
    // create a map with key as the string and the value as the group of words that match the string
    int n = words.size();
    for (int i = 0; i < n; i++)
    {
        // sig is the first or the ith word of the ARRAY OF STRINGS --> words
        // we stored it in a variable for reference
        string sig = words[i];
        // after storing the ith word in sig, we sort it
        sort(sig.begin(), sig.end());
        // groups is the map, sig is the KEY here which is further used to determine in which group the word belongs to
        // so if the sorted word is aet, all it's anagrams will become aet after sort, thus we can say that
        // all the words that give answer aet after sorting belong to the same group
        // so we append it all
        groups[sig].push_back(words[i]);
    }
    vector<vector<string>> result;
    for (auto &pair : groups)
    {
        result.push_back(pair.second);
    }
    return result;
}

vector<int> kMostFreq(vector<int> arr, int k)
{
    // we create buckets of each value in the array and then try to count the frequency of each element
    unordered_map<int, int> count;
    int n = arr.size();
    for (int v : arr)
    {
        // find the key named v and increse it's value by 1
        count[v]++;
    }

    // declare 2D array bucket of size arr+1(an array containing multiple arrays)
    vector<vector<int>> buckets(arr.size() + 1);

    // auto extracts the key and value from the map --> "For every entry in count, give me its number as value and its frequency as frequency"
    for (auto &[value, freq] : count)
    {
        // we create buckets of frequencies, so here put the value (ex: 1) inside the frequency (ex: 3) bucket
        buckets[freq].push_back(value);
    }

    vector<int> result;

    for (int f = arr.size(); f >= 1; f--)
    {

        // for values in buckets with frequency f, push back the value in the results array, therefore the 1, or 2 or 5 whichever element is there will be pushed back in the result array
        for (int value : buckets[f])
        {
            result.push_back(value);

            // if the result's size reaches k, return the result which is the array of k most frequently occuring characters.
            if (result.size() == k)
            {
                return result;
            }
        }
    }
    return result;
}

vector<int> productExceptSelf(vector<int> arr)
{
    // basic idea is to have a prefix and a suffix and then multiply them to get the product except self
    int n = arr.size();

    // output array should be initilized with n elements else we can't add anything at a particular index
    vector<int> output(n);

    // initialize prefix with 1;
    int prefix = 1;

    for (int i = 0; i < n; i++)
    {
        // output[i] is the prefix, so firstly output[0] would be 1;
        output[i] = prefix;

        // then we multiply the prefix with the current element to get the next prefix
        prefix = prefix * arr[i];
    }

    int suffix = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        // we multiply the current element with the suffix as we go on to create the output array we need
        output[i] = output[i] * suffix;

        // same as prefix keep on multplying for next element
        suffix = suffix * arr[i];
    }
    return output;
}

int longestConsecutiveSequence(vector<int> arr)
{
    // basic idea for optimized approach is to store the length of the consecutive sequence and then return it
    // put all elements in the set and sort
    unordered_set<int> nums(arr.begin(), arr.end());
    int best = 0;
    // check every number in set
    for (int n : nums)
    {
        // if the previous number is present in the set then this is not the start of the sequence
        if (nums.find(n - 1) != nums.end())
            continue;
        // n is the start of the sequence
        int length = 1;
        // keep checking for consecutive numbers and increase the length if we find any
        while (nums.find(n + length) != nums.end())
            length++;
        best = max(best, length);
    }
    return best;
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

    // ===== Contains Duplicate =====
    vector<int> arr1 = {1, 2, 3, 1};

    if (containsDuplicate(arr1))
    {
        cout << "Duplicate found" << endl;
    }
    else
    {
        cout << "No duplicate found" << endl;
    }

    // ===== Valid Anagram =====
    string s = "anagram";
    string t = "nagaram";

    if (validAnagram(s, t))
    {
        cout << "Valid anagram" << endl;
    }
    else
    {
        cout << "Not an anagram" << endl;
    }

    // groupAnagrams
    vector<string> words = {
        "eat",
        "tea",
        "tan",
        "ate",
        "nat",
        "bat"};

    vector<vector<string>> ans = groupAnagrams(words);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[ ";

        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }

        cout << "]" << endl;
    }

    // kMostFrequent
    vector<int> nums = {1, 1, 1, 1, 2, 2, 2, 3, 4, 4, 4, 6, 6, 6, 7, 7, 8, 8, 8, 9, 9, 9, 9};
    int k = 5;

    vector<int> result1 = kMostFreq(nums, k);

    cout << "[ ";

    for (int num : result1)
    {
        cout << num << " ";
    }

    cout << "]" << endl;

    // productExceptSelf
    vector<int> arr2 = {1, 2, 3, 4};

    vector<int> result2 = productExceptSelf(arr2);

    cout << "[ ";

    for (int x : result2)
    {
        cout << x << " ";
    }

    cout << "]" << endl;

    vector<int> arr3 = {100, 4, 200, 1, 3, 2};

    int result3 = longestConsecutiveSequence(arr3);

    cout << result3 << endl;

    return 0;
}