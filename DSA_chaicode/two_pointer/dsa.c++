#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    int left = 0;
    int right = numbers.size() - 1;

    while (left < right)
    {
        int sum = numbers[left] + numbers[right];

        if (sum == target)
        {
            return {left + 1, right + 1};
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return {};
}

bool validPalindrome(string s)
{
    int left = 0;
    int right = s.size() - 1;

    while (left < right)
    {
        while (left < right && !isalnum(s[left]))
            left++; // if the element is not alphanumeric(a-z or 0-9) skip it
        while (left < right && !isalnum(s[right]))
            right--;
        if (tolower(s[left]) != tolower(s[right]))
            return false;
        left++;
        right--;
    }
    return true;
}

vector<vector<int>> threeSum(vector<int> arr)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            if (i > 0 && arr[i] == arr[i - 1])
                continue;
            int sum = arr[i] + arr[left] + arr[right];
            if (sum == 0)
            {
                ans.push_back({arr[i], arr[left], arr[right]});
                left++;
                right--;
            }
            else if (sum < 0)
                left++;
            else
                right--;
        }
    }
    return ans;
}

int containerWMostWater(vector<int> arr)
{
    int left = 0;
    int right = arr.size() - 1;
    int maxArea = 0;
    while (left < right)
    {
        int area = (right - left) * min(arr[left], arr[right]);
        maxArea = max(maxArea, area);
        if (arr[left] <= arr[right])
            left++;
        else
            right--;
    }
    return maxArea;
}

int validTriangle(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int count = 0;
    for (int k = 2; k < arr.size(); k++)
    {
        int left = 0;
        int right = k - 1;
        while (left < right)
        {
            if (arr[left] + arr[right] > arr[k])
            {
                count += right - left;
                right--;
            }
            else
                left++;
        }
    }
    return count;
}

void moveZeroes(vector<int> &arr)
{
    int slow = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[slow]);
            slow++;
        }
    }
}

void sortColors(vector<int> &arr)
{
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
            mid++;
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int trapRainWater(vector<int> arr)
{
    int left = 0;
    int right = arr.size() - 1;
    int maxL = 0;
    int maxR = 0;
    int total = 0;

    while (left < right)
    {
        if (arr[left] < arr[right])
        {
            if (arr[left] >= maxL)
                maxL = arr[left];
            else
                total += maxL - arr[left];
            left++;
        }
        else
        {
            if (arr[right] >= maxR)
                maxR = arr[right];
            else
                total += maxR - arr[right];
            right--;
        }
    }
    return total;
}



int main()
{
    // // TwoSum
    // vector<int> arr1 = {2, 3, 5, 6, 10};
    // vector<int> ans = twoSum(arr1, 5);
    // for (int num : ans) {
    //     cout << num << " ";
    // }

    // //palindrome
    // string s = "A man, a plan, a canal: Panama";
    // cout << boolalpha << validPalindrome(s) << endl;

    // //3sum
    // vector<int> nums = {-1,0,1,2,-1,-4};
    // vector<vector<int>> ans = threeSum(nums);
    // for(vector<int> triplet : ans){
    //     for(int num : triplet){
    //        cout << num << " ";
    //     }
    //     cout << endl;
    // }

    // //water container
    // vector<int> height = {1,8,6,2,5,4,8,3,7};
    // int solved = containerWMostWater(height);
    // cout << solved;

    // //validTriangle
    // vector<int> tri = {2,2,3,4};
    // cout << validTriangle(tri);

    // //moveZeroes
    // vector<int> arr = {0,1,0,3,12};
    // moveZeroes(arr);

    // for(int num : arr){
    //     cout << num << " ";
    // }
    // cout << endl;

    // //sortColors
    // vector<int> arr = {2,0,2,1,1,0};
    // sortColors(arr);

    // for(int num : arr){
    //     cout << num << " ";
    // }
    // cout << endl;

    // // trap rain water
    // vector<int> arr = {4, 2, 0, 3, 2, 5};
    // cout << trapRainWater(arr);
}
