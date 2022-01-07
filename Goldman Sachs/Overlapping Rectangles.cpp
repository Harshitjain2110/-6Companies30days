/*
Given two rectangles, find if the given two rectangles overlap or not. A rectangle is denoted by providing the x and y coordinates of two points: the left top corner and the right bottom corner of the rectangle. Two rectangles sharing a side are considered overlapping. (L1 and R1 are the extreme points of the first rectangle and L2 and R2 are the extreme points of the second rectangle).

Note: It may be assumed that the rectangles are parallel to the coordinate axis.

rectanglesOverlap

Example 1:

Input:
L1=(0,10)
R1=(10,0)
L2=(5,5)
R2=(15,0)
Output:
1
Explanation:
The rectangles overlap.
Example 2:

Input:
L1=(0,2)
R1=(1,1)
L2=(-2,0)
R2=(0,-3)
Output:
0
Explanation:
The rectangles do not overlap.

Your Task:
You don't need to read input or print anything. Your task is to complete the function doOverlap() which takes the points L1, R1, L2, and R2 as input parameters and returns 1 if the rectangles overlap. Otherwise, it returns 0.


Expected Time Complexity:O(1)
Expected Auxillary Space:O(1)


Constraints:
-109<=x-coordinate,y-coordinate<=109
*/



class Solution {
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        // code here\
        //Non- overlapping cases-
        //1.If one rectangle is completely above the other
        int yu = R1[1];
        int yl = L2[1];
        
        if(yu>yl)
            return 0;
        
        yu = R2[1];
        yl = L1[1];
        
        if(yu>yl)
            return 0;
        
        //2.If one rectangle is completely left to the other
        int xl = R1[0];
        int xr = L2[0];
        if(xl<xr)
            return 0;
            
        xl = R2[0];
        xr = L1[0];
        
        if(xl<xr)
           return 0;
    
       return 1;
    }
};
