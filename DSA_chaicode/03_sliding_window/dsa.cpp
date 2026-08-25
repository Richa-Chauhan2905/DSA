#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <deque>

using namespace std;

// maxSumSubarray
double maxSumSubarray(vector<int> arr, int k)
{
    // basic insight: calculate sum of first window, go on and add the next number to the window and subtract the first number from the window so we get the sum of the new window.
    int n = arr.size();
    // sum stores the sum of CURRENT window
    double sum = 0;
    // example array = [2, 1, 5, 1, 3, 2]
    for (int i = 0; i < k; i++)
    {
        // in the first loop we calculate the size of first window which is from 0 to k
        sum += arr[i];
    }
    // maxSum stores maximum sum we got till now
    double maxSum = sum;
    // another integer right starts at k (RIGHT AFTER i left) in this case right will start at 1(3rd index because k = 3) what this loop will do is it will include the current element - the element at which right pointer is pointing into the sum (add it in the existing sum) and then subtract the element [right - k] which in this case would be 3-3 = 0, so subtract the zeroth element from it.
    for (int right = k; right < n; right++)
    {
        sum += arr[right] - arr[right - k];
        maxSum = max(sum, maxSum);
    }
    return maxSum;
    // if asked for average, add average = sum/k after first loop and inside the second loop after sum calculation anf change maxSum to maxAvg
}

long long maxSubarraySumUnique(vector<int> arr, int k)
{
    // basic idea is to add the freq of each char for each window and then count the number of keys in the map and if the key equal k that means we got k different values in the subarray
    unordered_map<int, int> freq;
    long long sum = 0;
    long long best = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        // absorb arr[r] into sum, freq --> add the current value to both sum and freq
        sum += arr[i];
        freq[arr[i]]++;

        // now check for next elements which would be after the window, so basically check for the next window with new element
        if (i >= k)
        { //--> for k = 3, if i is the 3rd or the 4th element then
            // first we remove the sum of the discarded element as well as decrease it's freq one time from the map to save that the first element whatever it was is discarded
            sum -= arr[i - k];
            freq[arr[i - k]]--;
            // after that we check if the discarded element was appearing only once and after reducing it freq if it is now zero if yes then completely erase that element
            // ex array = [10, 20, 20, 30]
            // here in this case for 10, if we do arr[i-k]-- for freq, it would be zero because 10 had only 1 freq so we completely erase it's key from the map
            // same thing if we did for 20, it would still be 1 because only 20 was removed, we still have one 20 with us in the window which is index 3, so we keep it's freq as is
            if (freq[arr[i - k]] == 0)
            {
                freq.erase(arr[i - k]);
            }
        }
        // now check if the window is full or not
        // here if the current (ith) element becomes greater than k-1 (if k is 3, i becomes >= 2, then this condition is true)
        // r = 0 → [1]           1 element
        //  r = 1 → [1,2]        2 elements
        //  r = 2 → [1,2,3]      3 elements ← first full window
        //  r = 3 → [2,3,4]      3 elements ← still full
        //  r = 4 → [3,4,5]      3 elements ← still full
        if (i >= k - 1)
        { //-->Remove the element that falls out of the fixed-size window.
            // we check if the frequency size is less than 3, if yes we continue and dont count that frequency
            // so if the array has 20, 20, the freq.size for that window would be 2 because we only nhave 2 keys: 10 and 20, therefore we dont need to count that window we can move forward and continue.
            if (freq.size() < k)
                continue; //-->Check whether the window is full and all k elements are unique.
            best = max(best, sum);
        }
    }
    return best;
}

int maxPointsFromCards(vector<int> arr, int k)
{
    // the only addition here different from other sliding window questions is the calculation of total
    // other than that we do the same thing: first calculate the window's sum and then move it forward
    // the idea is to calculate the MINIMUM amount we can LEAVE OUT and then subtract it from the total so we can get MAXIMUM return
    int n = arr.size();
    // a total pointer that counts the total
    int total = 0;
    for (int i : arr)
    {
        // this total is used further to know the total amount we have in the array
        total += i;
    }

    // w is the window size we DONOT WANT
    int w = n - k;
    // winSum is the current window's sum
    int winSum = 0;

    for (int i = 0; i < w; i++)
    { //--> in this loop we take until w because we want to sum the current window
        // we calculate the current window sum
        winSum += arr[i];
    }

    int minSum = winSum;
    for (int r = w; r < n; r++)
    { //--> here we start the loop from w so we can move the window forward for the next elements
        // then move the window forward
        winSum += arr[r] - arr[r - w];
        // we take whichever is minimum so we can maximize the amount we WILL TAKE
        minSum = min(winSum, minSum);
    }
    return total - minSum;
}

int longestSubstringNoRepeat(string s)
{
    // Here the idea is to the go on with the window, if we encounter a duplicate, we can just shrink the window as in move the Left pointer forward so window size is decreased. And then after that we can check for the new window
    unordered_map<int, char> last;
    // vector<int> last(256, -1); //Use this for faster retrieval of the element
    int L = 0;
    int max_length = 0;
    int n = s.length();

    for (int R = 0; R < n; R++)
    {
        // This condition checks 2 things
        // 1. If the element already EXISTS in the MAP
        // 2. What is the index of that value, as in if it is inside the current window or not if it is, the index WILL be GREATER or EQUAL to L bcause it is present in the window
        if (last.find(s[R]) != last.end() && last[s[R]] >= L)
        {
            //==============if(last[s[R]] >= left){ --> use this if using array indexing=============
            // if the condition is true, we can point L to the index AFTER the value
            // If a is present in the set at index 0, we can now point L to one so it can SKIP the a present in the window ans shrink the window to not contain the duplicate
            // Basically we JUMP L elements
            L = last[s[R]] + 1;
        }

        last[s[R]] = R; // add the current element to the map

        max_length = max(max_length, R - L + 1);
    }
    return max_length;
}

int longestRepeatingCharReplace(string s, int k)
{
    // The idea is to check how many replacement we will require in the current window, if it is greater than k then we shrink the window
    int left = 0;
    // The frequency of a char is stored in the map
    unordered_map<char, int> freq;
    int maxFreq = 0;
    int best = 0;

    for (int right = 0; right < s.length(); right++)
    {
        // add the current element to the map with it's frequency
        freq[s[right]]++;
        // max frequency should be max of both current and maxFreq
        maxFreq = max(maxFreq, freq[s[right]]);
        // this condition checks if the CURRENT WINDOW SIZE - the maxFreq currently is greater than k
        // If the current window size is 5 and k is 1, and the maxFreq is 3 for the letter A, we get 5-3=2 which is greater than k
        // so we can't use that window sequence so we can SHRINK the window
        if (((right - left + 1) - maxFreq) > k)
        {
            // remove the left element from the map and increase the pointer
            freq[s[left]]--;
            left++;
        }
        // the best sequence is max from best and the current window
        best = max(best, right - left + 1);
    }
    return best;
}

string minWindow(string s, string t)
// basic idea is to match the current window with the have variable and check if it satisfies it if yes check if it is the minimum length we can get
{
    // store characters from t in this map
    unordered_map<char, int> need;
    // stores whatever there is in the current window
    unordered_map<char, int> window;

    // we add characters from t to need map
    for (char c : t)
    {
        need[c]++;
    }

    // required is the characters from t that we require from s
    int required = need.size();
    // Once have == required the window is valid
    int have = 0;
    // initialize the left pointer with zero
    int left = 0;

    int bestStart = 0;
    // as we need least length we start with Max and go down
    int bestLength = INT_MAX;

    for (int right = 0; right < s.length(); right++)
    {
        // Add current character to window
        char c = s[right];
        window[c]++;

        // When we added this char, did we get the element we needed??? If yes then increase have
        if (need.find(c) != need.end() &&
            window[c] == need[c])
        {
            have++;
        }

        // Now have we got ALL the elements we need???
        while (have == required)
        {
            int currentLength = right - left + 1;

            // Is this is the smallest winodw then we make it the best length
            if (currentLength < bestLength)
            {
                bestLength = currentLength;
                // and now the bestStart is the left pointer
                bestStart = left;
            }

            // Remove left character from the window to shrink it
            char leftChar = s[left];
            window[leftChar]--;

            // Did removing leftChar make the window invalid?? as in do we not have every character then decrease have
            if (need.find(leftChar) != need.end() &&
                window[leftChar] < need[leftChar])
            {
                have--;
            }
            // increase the left pointer
            left++;
        }
    }

    // If bestLength is still INTMAX we dont have any window that satisfies us
    if (bestLength == INT_MAX)
    {
        return "";
    }

    // return substr starting from bestStart for bestLength length
    return s.substr(bestStart, bestLength);
}

bool permutationInString(string s1, string s2)
{
    // s1 is the smaller string and s2 is the larger string so we first check if s1 is greater than s2 if yes we cant work with it
    int k = s1.length();
    if (k > s2.length())
        return false;
    unordered_map<char, int> target;
    unordered_map<char, int> window;

    // add all the smaller string chars to target map
    for (int c : s1)
    {
        target[c]++;
    }

    // add THE NUMBER OF CHAR PRESENT IN S1(smaller string) from s2 to current window
    // so here if k is 2 then we add 2 characters from s2(longer string) to the window so window size itself remains k and not exceed it
    // we need this because the permutation needs to be contagious
    // so there has to be only k elements in the window at most
    for (int i = 0; i < k; i++)
    {
        window[s2[i]]++;
    }

    // if both maps are same then we found our target and we return true
    if (window == target)
        return true;

    // slide the window forward if not found
    // so we point right at k in this case at index 1 because k = 2 so we have the window size of 0..1 right now
    // so we start at k and go on until the end
    for (int right = k; right < s2.length(); right++)
    {
        // remove the left char from the window
        char leftChar = s2[right - k];
        window[leftChar]--;

        // if it is occuring only once, erase it from the window
        if (window[leftChar] == 0)
        {
            window.erase(leftChar);
        }

        // add the new char from the right to the window
        char rightChar = s2[right];
        window[rightChar]++;

        // if target found, return true
        if (window == target)
            return true;
    }
    return false;
}

vector<int> slidingWindowMax(vector<int> nums, int k)
{
    vector<int> answer;
    deque<int> dq;

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        // check in the queue if there is anything to compare with, if yessss then we compare that VALUE(nums[dq.back()]) with the current number else just go on
        while (!dq.empty() && nums[dq.back()] <= nums[i])
        {
            dq.pop_back();
        }
        // push back the current indices in the queue
        dq.push_back(i);

        // now check if the indices that id present at the front has already been passed out by the window
        // for ex: if the first is an index 1 and the current window is 234
        // we dont need the one in the queue
        // to check the index we do i - k
        // so i would be 4 for now and if k is 3, we get 4-3 = 1 which IS less than the current window indices so we POP the FRONT
        if (dq.front() <= i - k)
        {
            dq.pop_front();
        }

        // now when i pointer has successfully covered ONE window
        // that is 012 and then moved forward with 3
        // we can say that i is greater than current k
        // and that the element has already passed out of the window
        // so we just add THAT element to the answer array
        if (i >= k - 1)
        {
            answer.push_back(nums[dq.front()]);
        }
    }
    return answer;
}

int main()
{
    vector<int> arr = {2, 1, 5, 1, 3, 2};
    int k = 3;

    int result = maxSumSubarray(arr, k);

    cout << "Maximum sum: " << result << endl;

    vector<int> arr1 = {1, 5, 4, 2, 9, 9, 9};
    int k1 = 3;

    int result1 = maxSubarraySumUnique(arr1, k1);

    cout << "Maximum unique subarray sum: " << result1 << endl;

    vector<int> cards = {1, 2, 3, 4, 5, 6, 1};
    int k2 = 3;

    long long result2 = maxPointsFromCards(cards, k2);

    cout << "Maximum score: " << result2 << endl;

    string s = "bbbb";
    cout << "Longest substr without repeat is: " << longestSubstringNoRepeat(s) << endl;

    string s1 = "AABABBA";
    cout << "Longest Repeating Char Replace is: " << longestRepeatingCharReplace(s1, 1) << endl;

    string s2 = "ABDCEABDEDABCAB";
    string t = "ABC";
    cout << "MinimumWindow possible for string is: " << minWindow(s2, t) << endl;

    string s3 = "ab";
    string s4 = "eidbaooo";
    cout << permutationInString(s3, s4) << endl;

    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k3 = 3;

    vector<int> result3 = slidingWindowMax(nums, k3);

    cout << "Maximum of each window: [ ";

    for (int x : result3)
    {
        cout << x << " ";
    }

    cout << "]" << endl;

    return 0;
}
