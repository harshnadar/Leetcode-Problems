class Solution {
    
    public boolean makesquare(int[] matchsticks) {
        
        
        /*  Approach:
        
            We will use DFS to search for all combinations where my sticks can form a square
        
        */
        
        
        // If no. of matchsticks are less than 4, then cannot form square.
        
        if (matchsticks == null || matchsticks.length < 4) {
            return false;
        }
        
        // Calculate sum of length of every sticks.
        
        int sum = 0;
        for (int stick : matchsticks)    sum = sum + stick;
        
        // Every side of square should have same length, so overall sum should be multiple of 4
        
        if (sum % 4 != 0) {
            return false;
        }
        
        /*  DFS:
            
            - We will send the current length of 4 sides of the squares to DFS. 
              ( Intially we send length of all sides of squares as 0 )

            - We will send array matchsticks and sum/4 of matchsticks to DFS
              ( It will remain static always in DFS and just used for checking purpose)

            - We will send currIndex of array to DFS.
              ( Initially 0 -> arr[0].  Everytime, we use A[currIndex] and increment for further DFS)
              
              Whenever, 
            
        */
        
        int side1 = 0, side2 = 0, side3 = 0, side4 = 0, currIndex = 0;
        
        int oneSideLen = sum/4;
        
        return dfs (side1, side2, side3, side4, matchsticks, currIndex, oneSideLen);
        
    }
    
    
    // DFS function to return if len of 4 sides are equal and sum up to total_sum/4 when arr ends.
    
    public boolean dfs (int s1, int s2, int s3, int s4, int arr[], int k, int len) {
        
        // If any of the side is more than Side Length of square needed, return false.
        
        if (s1 > len || s2 > len || s3 > len || s4 > len) {
            return false;
        }
        
        // If match sticks completed, i.e. index k crosses from 0 to n-1 and reaches n.
        
        if (k == arr.length) {
            
            /* Either all sides are equal (then it automatically sums upto len. as every element is used)
               Then return true, else false (not possile as arr completes and sides are not equal)
            */
            
            return s1 == s2 && s2 == s3 && s3 == s4;
            
        }
        
        
        // Call recursive DFS by adding curr element to sides one by one. 
        // If any combination is true, return true.
        
        return (dfs (s1 + arr[k], s2         , s3         , s4         , arr, k + 1, len) ||
                dfs (s1         , s2 + arr[k], s3         , s4         , arr, k + 1, len) ||
                dfs (s1         , s2         , s3 + arr[k], s4         , arr, k + 1, len) ||
                dfs (s1         , s2         , s3         , s4 + arr[k], arr, k + 1, len));
    }
    
    
}