/*
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.

 

Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
 

Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.

*/

class Solution {
public:
    /*
        Sudo Code/ Algorithm
        -Create a Hash map of where the key is the element and the frequence as its value <char,int>
        -Create a priority_queue of pair<char,int> 
            -For the following fucntionwe have to write a comperator function that is based on the pair.second
            That's the freqency 
        -Now itereate through the priority queue and create a string based on the frequency and the character and then add that string 
        to the final answer
    
    
    */


    typedef pair<char,int> pc;

     static bool comparator(const pc& p1, const pc& p2) {
        return p1.second < p2.second;
    }


    string frequencySort(string s) {
        map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        // Use a vector instead of map to store the pairs for sorting
        vector<pc> v;
        for (auto i : mp) {
            v.push_back({i.first, i.second});
        }

        // Use the comparator function to define the priority_queue
        priority_queue<pc, vector<pc>, decltype(&comparator)> pq(&comparator);
        /*
            This line declares a priority queue named pq with the following template parameters:

            Element Type (pc): pc is an alias for pair<char, int>, representing a character and its frequency.

            Container Type (vector<pc>): vector<pc> is used as the underlying container to store the elements of the priority queue. The priority queue will be implemented using a vector.

            Comparator Type (decltype(&comparator)): decltype(&comparator) is a way to deduce the type of the comparator function. In this case, it's deducing the type of the function pointer to the comparator function. decltype is a feature in C++ that allows you to obtain the type of an expression at compile time.

            Comparator Function (&comparator): &comparator is a pointer to the comparator function. The comparator function is responsible for defining the order of elements in the priority queue. It takes two elements and returns true if the first should go before the second based on the defined order.

            Finally, the pq(&comparator) part initializes the priority queue with the specified comparator function.

            So, in summary, this line is creating a priority queue of pairs (pc) using a vector as the underlying container and specifying a custom comparator function (comparator) to determine the order of elements in the priority queue. The decltype is used to automatically deduce the type of the comparator function.
            The third template parameter (decltype(&comparator)) is specifying the type of the comparator function. The fourth parameter (&comparator) is actually passing the comparator function to the priority queue constructor, initializing the priority queue with this custom comparator.

            So, by providing a custom comparator, you can change the order in which elements are considered "higher" or "lower" in the priority queue. In this case, the custom comparator comparator is used to sort elements based on their frequency, from lowest to highest. This ensures that the element with the lowest frequency will be at the top of the priority queue.
        */

        for (auto i : v) {
            pq.push(i);
        }

        string ans = "";
        while (!pq.empty()) {
            char current_char = pq.top().first;
            int count = pq.top().second;
            string current_string(count, current_char);  // Create a string of length 'count' with 'current_char'
            ans += current_string;
            pq.pop();
        }

        return ans;



    }
};