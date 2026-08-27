#include <iostream>
#include <stack>
#include <algorithm>

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
//here the idea is to count each parenthesis content and then multiply it by the number present at front and then add it to a decoded string, add the decoded string back to the stack and then we can access the stack to get the result
{
    stack<char> st;
    //first add all the chars to stack until we hit a ']'
    for (char c : s)
    {
        if (c != ']')
        {
            st.push(c);
        }
        else
        {
            //now we get a new string called body and add the elements of stack in it untill we reach the opening bracket '[' and then we also add the opening bracket itself to the body so have a full parenthesis element in body
            string body = "";
            while (st.top() != '[')
            {
                body += st.top();
                st.pop();
            }

            st.pop();

            //then we add the NUMBER in front in another string so we can access it when we need to multiply the body k times
            string number = "";

            while(!st.empty() && isdigit(st.top())){
                number += st.top();
                st.pop();
            }

            //we reverse the number because we pop from stack in reverse order so we gotta make it the og 
            //ex: if we add 12 to stack we will pop out 2 first and then 1 so it would become '21' but we want 12 so we reverse it
            reverse(number.begin(), number.end());
            
            //we convert the string number to int
            int k = stoi(number);
            
            //then we reverse the body as well because it's also in the reverse order when we popped it out of stack
            reverse(body.begin(), body.end());
            
            //this decoded string stores the current string multiplied k times
            string decoded = "";

            //run a loop to add the body string to decoded, k times
            for (int i = 0; i < k; i++)
            {
                decoded += body;
            }

            //and then we push the decoded string to stack so we can retrieve it later
            for(char x : decoded){
                st.push(x);
            }
        }
    }
    //result retrieves the string stored in stack
    string result = "";
    while(!st.empty()){
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());

    return result;
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

    return 0;
}
