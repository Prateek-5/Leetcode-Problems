/*
You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

 

Example 1:

Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.
Example 2:

Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
 

Constraints:

1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] is a lowercase letter.
equations[i][1] is either '=' or '!'.
equations[i][2] is '='.
equations[i][3] is a lowercase letter.

*/

class Solution {
public:
    /*
        Basic Intutuin / Algorithm

        The actual implementation of the following problem involves the creating a union of the letter and then checking if 
        they belong to the same union or not 

        -Since in the input we are been provided with smallerCase letter and it is difficult to create vertices using alphabates we
            can use the advantage tah all aout input will be lower caseletter only and we can initialized an array 
            for the purpose of parent and rank of 26 because the ASCII values of all the lower case letter will be within 26 only
            and for that we can subtract the ASCII value of "a" from the input to bring them within 26
        -Now therever we have an input vector like a==b we nned to call the union operation as the following vector indicates that
            the following two letter belong to the same union or thry will hav the same parent
            Note:WE need to iterate throught the whole input vector as the decision making if to return true of false will be on the 
                inequality equation so it's better to create all union before only
        -Once we have created alllthe union we nned to iterate for the inequality equation like a!=b basically in the following vectors 
            what we have to check is the fact if whay the input is saying is true or not throught the followng statement of 
            a!=b the input is trying to say that a and b belong to to the different clustor / they have different parent so to check that
            we already have the union created with us we cal all the find operation on these 2 vertex and check for the responce if the responce 
            say's that they are belonging to different parents they continue to the next vector if it say they have same parents then return false
             
    
    
    
    */


    vector<int> parent;
    vector<int> rank;

    int findNode(int a,vector<int>& parent)
    {
        if(a==parent[a])
        {
            return a;
        }

        return parent[a]=findNode(parent[a],parent);
    }

    void unionNode(int a,int b,vector<int>& parent,vector<int>& rank)
    {
        int x=findNode(a,parent);
        int y=findNode(b,parent);

        if(x==y)    return;

        if(rank[x]<rank[y])
        {
            parent[y]=x;
        }
        else if(rank[x]>rank[y])
        {
            parent[x]=y;
        }
        else{
            parent[y]=x;
            rank[x]++;
        }
    }






    bool equationsPossible(vector<string>& equations) {

        parent.resize(26);
        rank.resize(26);
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }



        for(auto &i:equations)
        {
            if(i[1]=='=')
            {
                int node1=i[0]-'a';
                int node2=i[3]-'a';
                cout<<node1<<" "<<node2<<endl;
                unionNode(node1,node2,parent,rank);
            }
        }
        
        
       

        for(auto &i:equations)
        {
            if(i[1]=='!')
            {
                int node1=i[0]-'a';
                int node2=i[3]-'a';
                if(findNode(node1,parent)==findNode(node2,parent))
                {
                    return false;
                }
            }
        }
        return true;




    }
};