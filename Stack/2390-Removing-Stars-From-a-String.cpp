/*
You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:

The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.
 

Example 1:

Input: s = "leet**cod*e"
Output: "lecoe"
Explanation: Performing the removals from left to right:
- The closest character to the 1st star is 't' in "leet**cod*e". s becomes "lee*cod*e".
- The closest character to the 2nd star is 'e' in "lee*cod*e". s becomes "lecod*e".
- The closest character to the 3rd star is 'd' in "lecod*e". s becomes "lecoe".
There are no more stars, so we return "lecoe".
Example 2:

Input: s = "erase*****"
Output: ""
Explanation: The entire string is removed, so we return an empty string.
 

Constraints:

1 <= s.length <= 105
s consists of lowercase English letters and stars *.
The operation above can be performed on s.

*/

class Solution {
public:
    /*
        Intution / Basic Algorithm

        Iterate over the given string and store the non-star char in the stack
            if we observe a star then we pop out one char from the stack
        Once we have iterated throught the string once we pop out each and every element from the
        stack and store it in a new string and once we are done we return the new string after reversing
         

    
    */



    string removeStars(string s) {
        stack<char> st;
        for(auto &i:s)
        {
            if(i!='*')
            {
                st.push(i);
            }
            else if(i=='*' && !st.empty())
            {
                st.pop();
            }
        }

        string result="";

        while(!st.empty())
        {
            result+=st.top();
            st.pop();
        }
        // cout<<result;
        reverse(result.begin(),result.end());

        return result;




    }
};