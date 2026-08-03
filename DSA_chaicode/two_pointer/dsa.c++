#include <iostream>
#include <vector>

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

int main(){
    // // TwoSum
    // vector<int> arr1 = {2, 3, 5, 6, 10};
    // vector<int> ans = twoSum(arr1, 5);
    // for (int num : ans) {
    //     cout << num << " ";
    // }

    //palindrome
    string s = "A man, a plan, a canal: Panama";
    cout << boolalpha << validPalindrome(s) << endl;
}
