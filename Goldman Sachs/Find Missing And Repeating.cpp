/*
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Example 1:

Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.
Example 2:

Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and 
smallest positive missing number is 2.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findTwoElement() which takes the array of integers arr and n as parameters and returns an array of integers of size 2 denoting the answer ( The first index contains B and second index contains A.)

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 105
1 ≤ Arr[i] ≤ N
*/



//----------------------------------------------------METHOD 1:------------------------------------------------------------------------------------------>
//Traverse the array. While traversing, use the absolute value of every element as an index and make the value at this index as negative to mark it visited. 
//If something is already marked negative then this is the repeating element. To find missing, traverse the array again and look for a positive value.
int *findTwoElement(int *arr, int n) {
        // code here
        int *ans = new int[2];
        for(int i=0;i<n;i++){
            int val_at_ele_as_idx; 
            if(arr[i]<0){
                val_at_ele_as_idx = arr[-arr[i]-1];
            }
            else{
                val_at_ele_as_idx = arr[arr[i]-1];
            }

            if(val_at_ele_as_idx<0){
                ans[0]= abs(arr[i]);
            }
            else{
                if(arr[i]<0){
                    arr[-arr[i]-1] = -val_at_ele_as_idx;
                }
                else{
                    arr[arr[i]-1] = -val_at_ele_as_idx;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(arr[i]>0){
               ans[1]=i+1;
               break;
            }
        }
        return ans;
    }






//--------------------------------METHOD 2:------------------------------------------------------------------------>
//HINT -
/*
Make two equations:
1.Let x be the missing and y be the repeating element.
2.Get the the sum of all numbers using formula S = n(n+1)/2 – x + y
3.Get product of all numbers using formula P = 1*2*3*…*n * y / x
4.The above two steps give us two equations, we can solve the equations and get the values of x and y.
To overcome overflow of sum and product you sholud use long long
*/



