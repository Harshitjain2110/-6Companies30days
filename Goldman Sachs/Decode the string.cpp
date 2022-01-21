/*
An encoded string (s) is given, the task is to decode it. The pattern in which the strings were encoded were as follows
original string: abbbababbbababbbab 
encoded string : 3[a3[b]1[ab]]

Example 1:

Input: s = 1[b]
Output: b
Explaination: 'b' is present only one time.
Example 2:

Input: s = 3[b2[ca]]
Output: bcacabcacabcaca
Explaination: 2[ca] means 'ca' is repeated 
twice which is 'caca' which concatenated with 
'b' becomes 'bcaca'. This string repeated 
thrice becomes the output.
Your Task:
You do not need to read input or print annything. Your task is to complete the function decodedString() which takes s as input parameter and returns the decoded string.

Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(|s|)

Constraints:
1 ≤ |s| ≤ 30 
*/


//-----------------------ALGORITHM------------------------------------------------------------------------------------------------------->
//We have used 2 stacks - one for storing multiplier and other for the string.
//we will iterate through the string s and if "]" is encoutered, we pop everything from the string stack until corresponding "[" is found
//pop out one multiplier from the stack and repeat the temp string as that much number of times
//and then push the processed string back to stack st(string stack)
class Solution{
public:
    string decodedString(string s){
        // code here
         stack<int> num;
         stack<string> st;
        
        for(int i=0;i<s.length();i++){
            
            if(s[i]==']'){
                string temp="";
                
                while(st.top()!="["){
                    temp = st.top()+temp;
                    st.pop();
                }
                st.pop();
                
                int multiplier = num.top();
                num.pop();
                
                string temp2 ="";
                while(multiplier--){
                    temp2+=temp;
                }
                
                st.push(temp2);
            }
            else if(s[i]>=48 and s[i]<=57){
                int number = stoi(s.substr(i,1));
                
                while(s[i+1]>=48 and s[i+1]<=57){
                    number=(number*10)+stoi(s.substr(i+1,1));
                    i++;
                }
                
                num.push(number);
            }
            else{
                st.push(s.substr(i,1));
            }
        }
        return st.top();
    }
};
