/*
Given a pattern containing only I's and D's. I for increasing and D for decreasing.
Devise an algorithm to print the minimum number following that pattern.
Digits from 1-9 and digits can't repeat.

 

Example 1:

Input:
D
Output:
21
Explanation:
D is meant for decreasing,
So we choose the minimum number
among 21,31,54,87,etc.
 

Example 2:

Input:
IIDDD
Output:
126543
Explanation:
Above example is self- explanatory,
1 < 2 < 6 > 5 > 4 > 3
  I - I - D - D - D
 

 

Your Task:

You don't need to read input or print anything. Your task is to complete the function printMinNumberForPattern() which takes the string S and returns a string containing the minimum number following the valid pattern.

 

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

 

Constraints:
1 ≤ Length of String ≤ 8
*/





//----------------------------------------------------------Method 1:------------------------------------------------------------>
//From the observation, we can say that if length of String S is len ,then ans string will contain digits from 1->(len+1)
//So we have first stored the digits in ans string 
//Then we come to know we the pattern of digits is reversed for the corresponding (consecutive) D's
//if 2 consecutive D's are found in S string ,reverse ans string starting from index of D in S string and take 3 characters/digits
//That means for N consecutive D's reverse corresponding N+1 digits/chars in ans string.
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        string ans = "";
        
        int len = S.length();
        
        for(int i=1;i<=len+1;i++){
            ans+=to_string(i);
        }
        
        for(int i=0;i<len;){
            
            if(S[i]=='D'){
                int cnt=0;
                int start = i;
                while(S[i]=='D' and i<len){
                   cnt++;
                   i++;
                }
            
                string left = ans.substr(0,start);
                string process = ans.substr(start,cnt+1);
                string right = ans.substr(start+cnt+1);
                reverse(process.begin(),process.end());
                ans = left+process+right;
            }
            else{
                i++;
            }
              
        }
        return ans; 
    }
};






//-------------------------------------METHOD 2:------------------------------------------------------------------->
//Using STACK
//Algorithm:-
//1.Push 1 in stack st
//2.Iterate through string S and 
//     2.1.If "I" is found empty the stack elements and put them into ans string
//3.And push the next element into the stack which will be initial top before emptying the stack +1
//4.If at the end of for loop ,stack is not empty, empty it by poping elements one by one and putting it into ans string.
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
    string ans = "";

    int len = S.length();

    stack<int> st;
    st.push(1);

    for(int i=0;i<len;i++){
        int next_ele = st.top()+1;
        if(S[i]=='I'){
            
            while(!st.empty()){
                int ele = st.top();
                st.pop();
                ans+=to_string(ele);
            }
            
        }
        st.push(next_ele);
    }

    while(!st.empty()){
        int ele = st.top();
        st.pop();
        ans+=to_string(ele);
    }
    return ans;  
    }
};





