/*
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order, we get the following sequence for n = 3:

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

 

Example 1:

Input: n = 3, k = 3
Output: "213"
Example 2:

Input: n = 4, k = 9
Output: "2314"
Example 3:

Input: n = 3, k = 1
Output: "123"
 

Constraints:

1 <= n <= 9
1 <= k <= n!
*/
class Solution {
public:
    /*
        The follownging the brute force approch of the for calculating the kth permulation 
        sequence we basically calculate all the permulation and retunr the kth permulation 
        after sorting the resulatant array 

        NOte the follwing array will give the TLE error as it is not the efficent solution
         

    */
    void solve(string current_string,vector<int>& freq,vector<int>& n_set,vector<string> &ans,int n){
        if(current_string.size()==n){
            ans.push_back(current_string);
            return;
        }

        for(int i=0;i<n;i++){
            if(freq[i]==0){
                /*
                    we are string the element that are include and not included throught the frequency array
                    and for each index.iteration we iterate throught the whole array and then decide if we have 
                    to include the following or not

                */
                current_string+=to_string(n_set[i]);
                freq[i]=1;
                /*
                    once we have included the array we add it to the current string and then
                    make the frequency/visited vector as false 
                */
                solve(current_string,freq,n_set,ans,n);

                /*
                    the traditional method or considering the not include case we basically element our last addition and
                    the mark the frequency/visited array as false
                */
                int length=current_string.length();
                current_string=current_string.substr(0,length-1);
                freq[i]=0;
            }
        }


    }




    string getPermutation(int n, int k) {
        vector<int> n_set(n);

        for(int i=0;i<n;i++){
            n_set[i]=i+1;
           
        }
        string current_string="";
        
        vector<string> ans;
        vector<int> freq(n,0);
        string s="abcd";
        
        /*
            we sort the ans array so that we get the ;exiographical array incorrect order
        */
        solve(current_string,freq,n_set,ans,n);

        sort(ans.begin(),ans.end());
        // for(auto i:ans){
        //     cout<<i<<" "<<endl;
        // }
        //return the k-1th index as the vector is zero indexed
        return ans[k-1];
        



    }
};
class Solution {
public:
    string getPermutation(int n, int k) {
        /*
            The follwing is the non-recursive solution for the problem 
            for better understanding refer 
            https://www.youtube.com/watch?v=wT7gcXLYoao&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=21&ab_channel=takeUforward
        
        */
        int fact=1;
        vector<int> numbers;

        for(int i=1;i<n;i++){
            fact=fact*i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans;
        k=k-1;
        while(true){
            ans=ans+to_string(numbers[k/fact]);
            numbers.erase(numbers.begin()+k/fact);
            if(numbers.size()==0){
                break;
            }
            k=k%fact;
            fact=fact / numbers.size();

        }

        return ans;



    }
};

