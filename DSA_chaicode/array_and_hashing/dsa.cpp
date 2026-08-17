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
        if (count[c] < 0)
            return false;
        count[c]--;
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
    return 0;
}