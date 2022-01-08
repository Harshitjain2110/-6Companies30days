/*
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, … shows the first 11 ugly numbers. By convention, 1 is included. Write a program to find Nth Ugly Number.

Example 1:

Input:
N = 10
Output: 12
Explanation: 10th ugly number is 12.
Example 2:

Input:
N = 4
Output: 4
Explanation: 4th ugly number is 4.
Your Task:
You don't need to read input or print anything. Your task is to complete the function getNthUglyNo() which takes an integer n as parameters and returns an integer denoting the answer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 104
*/



class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    if(n==1)
	        return 1;
    //METHOD-1:   
    //We have used the min priority queue to fetch out the minimum element
    //Pop out an element and insert it after multiplying it with 2,3 and 5
    //In order to keep track of the elements considered or not or to avoid repetition , we have used unordered_set
	    priority_queue<ull,vector<ull>,greater<ull>> pq;
	    unordered_set<ull> s;
	    pq.push(2);
	    pq.push(3);
	    pq.push(5);
	    
	    s.insert(2);
	    s.insert(3);
	    s.insert(5);
	    
	    ull min;
	    
	    for(int i=2;i<=n;i++){
	        min = pq.top();
	        pq.pop();
	        
	        if(s.find(min*2)==s.end()){
	            s.insert(min*2);
	            pq.push(min*2);
	        }
	            
	        if(s.find(min*3)==s.end()){
	            s.insert(min*3);
	            pq.push(min*3); 
	        }
	            
	       if(s.find(min*5)==s.end()){
	           s.insert(min*5);
	           pq.push(min*5);
	       }
	    }
	    return min;
	}
};







//----------------------------------------------METHOD-2------------------------------------------------------------
//Only using set

set<long long> q;
    	q.insert(1);
    	long long f;
        while(n--){
            auto it = q.begin();
            f=*it;
            q.erase(it);
            q.insert(f*2);
            q.insert(f*3);
            q.insert(f*5);
        }
        return f;





