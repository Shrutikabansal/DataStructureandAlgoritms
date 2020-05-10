'''
Subset Sum Problem
Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.

Input:
The first line contains an integer 'T' denoting the total number of test cases. Each test case consists of two lines. First-line contains 'N', representing the number of elements in the set and the second line contains the elements of the set.

Output:
For each test case, print YES if the partition is possible, otherwise print NO.

User Task:
You don't need to read input or print output, taking inputs and printing is done by the driver code. Your task is to complete the findPartition() function and return true if the given set can be partitioned into two subsets such that the sum of elements in both subsets is equal, else return false.

Constraints:
1 <= T <= 100
1 <= N <= 100
0 <= arr[i] <= 1000

Example:
Input:
2
4
1 5 11 5
3
1 3 5 
Output:
YES
NO

Explanation:
Testcase 1: There exists two subsets such that {1, 5, 5} and {11}.
'''


def findPartition(arr,n):
    
    #return True or False
    
    #Your code here
    s_um=0
    for i in range (0,n):
        s_um=s_um+arr[i]
        
    if s_um%2!=0:
        return 0
        
    col=int((s_um/2))+1
    #print(col)
    
    dp =  [[0 for _ in range (col)] for _ in range (n+1)]
    
    #for i in range (0,col):
    #    dp[0][i]=0
        
    for i in range (0,n+1):
        dp[i][0]=1
        
    #arr.sort()
    #print(len(dp))
    for i in range (1,n+1):
        #print(i)
        for j in range (1,col):
            #print(j)
            if j<arr[i-1]:
               dp[i][j]=dp[i-1][j]
            else:
               dp[i][j]= (dp[i-1][j] or dp[i-1][j-arr[i-1]])
                
    if dp[n-1][col-1]==1:
        return 1
    return 0
