#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

// points for stack
// 1. It never returns a char, it only pops it, to have it we need to store it before popping

using namespace std;

bool validParentheses(string s)
{
    stack<char> st;
    // for every char in string
    for (int c : s)
    {
        // if the current pointer is an opening bracket add it to the stack
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else
        {
            // else check if stack is already empty if yes return false
            if (st.empty())
                return false;
            // when not empty check if the current character is a closing bracket
            // AND check if the top of the top of the stack matches ANY opening parentheses
            // If not then we dont have the valid parenthesis pair so we return false
            if ((c == ')' && st.top() != '(') || (c == ']' && st.top() != '[') || (c == '}' && st.top() != '{'))
            {
                return false;
            }
            // pop the last character and check again for the new char
            st.pop();
        }
    }
    // return if stack is empty or not if yes then we had a valid parentheses
    return st.empty();
}

string decodeString(string s)
// here the idea is to count each parenthesis content and then multiply it by the number present at front and then add it to a decoded string, add the decoded string back to the stack and then we can access the stack to get the result
{
    stack<char> st;
    // first add all the chars to stack until we hit a ']'
    for (char c : s)
    {
        if (c != ']')
        {
            st.push(c);
        }
        else
        {
            // now we get a new string called body and add the elements of stack in it untill we reach the opening bracket '[' and then we also add the opening bracket itself to the body so have a full parenthesis element in body
            string body = "";
            while (st.top() != '[')
            {
                body += st.top();
                st.pop();
            }

            st.pop();

            // then we add the NUMBER in front in another string so we can access it when we need to multiply the body k times
            string number = "";

            while (!st.empty() && isdigit(st.top()))
            {
                number += st.top();
                st.pop();
            }

            // we reverse the number because we pop from stack in reverse order so we gotta make it the og
            // ex: if we add 12 to stack we will pop out 2 first and then 1 so it would become '21' but we want 12 so we reverse it
            reverse(number.begin(), number.end());

            // we convert the string number to int
            int k = stoi(number);

            // then we reverse the body as well because it's also in the reverse order when we popped it out of stack
            reverse(body.begin(), body.end());

            // this decoded string stores the current string multiplied k times
            string decoded = "";

            // run a loop to add the body string to decoded, k times
            for (int i = 0; i < k; i++)
            {
                decoded += body;
            }

            // and then we push the decoded string to stack so we can retrieve it later
            for (char x : decoded)
            {
                st.push(x);
            }
        }
    }
    // result retrieves the string stored in stack
    string result = "";
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());

    return result;
}

int longestValidParentheses(string s)
{
    // idea is to push the opening bracket and then pop it when we find it's matching closing bracket
    stack<int> st;
    // we push the INDICES not the actual bracket, so let's start with -1
    st.push(-1);

    int best = 0;
    // for the length of s
    for (int i = 0; i < s.length(); i++)
    {
        // if the current element is opening bracket push it in stack
        if (s[i] == '(')
        {
            st.push(i);
        }
        // else --> the bracket is closing bracket, we pop the opening bracket present in there
        else
        {
            st.pop();
            // if we start at an opening bracket as first, we have to pop the -1, so we have an EMPTY stack, now empty stack itself isn't a problem but we need to calculate the distance of top element and the base element to know the length of the valid parenthesis, so we add the current element which in this case would be zero, so we can calculate the distance further
            //  so generally after we encounter a ) we'd pop it
            // but if ) is the first element itself, stack would become empty, so we add the )'s index to have a base to calculate the distance
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                // else we calculate the best
                // we use i - st.top() to calculate the distance between the current element at which i points and the top
                // so if i is 1 and st.top() is -1 because we found a valid pair, we do 1 - (-1) so 2, therefore we get the distance
                best = max(best, i - st.top());
            }
        }
    }
    return best;
}

vector<int> dailyTemperatures(vector<int> temps)
// MONOTONIC STACK conecpt
// main idea is to use monotonic stack to check which next warmer is there for current element present at the top of the stack
{
    stack<int> st;
    int n = temps.size();
    // get an array initialized with 0 and the size of the temperature array
    vector<int> answer(n, 0);

    for (int i = 0; i < n; i++)
    {
        // this is the line for decreasing monotonic stack that checks if the top is smaller than the current element, if yes we pop it out because we need a warmer day than the day present at the top
        while (!st.empty() && temps[st.top()] < temps[i])
        {
            // we store the i top index in j and then pop it
            int j = st.top();
            st.pop();

            // now to calculate the answer to the question --> "how many days after the current day till the warmer day arrives" -- we use current index --> i pointing at the index we are currently at it can be the very next element or an element way further in the array, minus the index we popped out that is stored in j

            answer[j] = i - j;
        }
        // after that we push i
        st.push(i);
    }
    return answer;
}

class MinStack
{
public:
    stack<int> main;
    stack<int> mins;

    void push(int x)
    {
        main.push(x);

        if (mins.empty())
        {
            mins.push(x);
        }
        else
        {
            mins.push(min(x, mins.top()));
        }
    }
    void pop()
    {
        main.pop();
        mins.pop();
    }

    int top()
    {
        return main.top();
    }

    int getMin()
    {
        return mins.top();
    }
};

int reversePolishNotation(vector<string> tokens)
{
    stack<int> st;
    for (string token : tokens)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            int right = st.top();
            st.pop();

            int left = st.top();
            st.pop();

            if (token == "+")
                st.push(left + right);
            else if (token == "-")
                st.push(left - right);
            else if (token == "*")
                st.push(left * right);
            else
                st.push(left / right);
        }else {
            st.push(stoi(token));
        }
    }
    return st.top();
}

int main()
{
    string s = "({[]})";

    if (validParentheses(s))
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }

    string s1 = "3[a]2[bc]";

    string result = decodeString(s1);

    cout << "Decoded string: " << result << endl;

    string s2 = ")()())";

    int result1 = longestValidParentheses(s2);

    cout << "Longest valid parentheses length: " << result1 << endl;

    vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> result2 = dailyTemperatures(temps);

    cout << "Answer: [ ";

    for (int x : result2)
    {
        cout << x << " ";
    }

    cout << "]" << endl;

    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << "Top: " << st.top() << endl;
    cout << "Minimum: " << st.getMin() << endl;

    st.pop();

    cout << "After pop:" << endl;
    cout << "Top: " << st.top() << endl;
    cout << "Minimum: " << st.getMin() << endl;

    vector<string> tokens = {"2", "1", "+", "3", "*"};

    int result3 = reversePolishNotation(tokens);

    cout << "Result: " << result3 << endl;

    return 0;
}
