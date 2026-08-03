#include <iostream>
#include <vector>
#include <algorithm>

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

bool validPalindrome(string s){
    int left = 0;
    int right = s.size() - 1;
    
    while(left < right){
        while (left < right && !isalnum(s[left])) left++; //if the element is not alphanumeric(a-z or 0-9) skip it
        while(left < right && !isalnum(s[right])) right--;
        if(tolower(s[left]) != tolower(s[right])) return false;
        left++;
        right--;
    }
    return true;
}

vector<vector<int>> threeSum(vector<int> arr){
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int i = 0; i < n - 2; i++){
        if(i > 0 && arr[i] == arr[i-1]) continue;
        int left = i + 1;
        int right = n - 1;

        while(left < right){
            if (i > 0 &&  arr[i] == arr[i-1]) continue;
            int sum = arr[i] + arr[left] + arr[right];
            if(sum == 0) {
                ans.push_back({arr[i], arr[left], arr[right]});
                left++;
                right--;
            }
            else if(sum < 0) left++;
            else right--;
        }
    }
    return ans;
}

int containerWMostWater(vector<int> arr){
    int left = 0;
    int right = arr.size() - 1;
    int maxArea = 0;
    while(left < right){
        int area = (right - left) * min(arr[left], arr[right]);
        maxArea = max(maxArea, area);
        if(arr[left] <= arr[right]) left++;
        else right--;
    }
    return maxArea;
}

int main(){
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

    //water container
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int solved = containerWMostWater(height);
    cout << solved;
}
