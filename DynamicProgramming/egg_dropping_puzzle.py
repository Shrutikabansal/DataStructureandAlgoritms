'''
Suppose you have N eggs and you want to determine from which floor in a K-floor building you can drop an egg such that it doesn't break. You have to determine the minimum number of attempts you need in order find the critical floor in the worst case while using the best strategy.There are few rules given below. 

An egg that survives a fall can be used again.
A broken egg must be discarded.
The effect of a fall is the same for all eggs.
If the egg doesn't break at a certain floor, it will not break at any floor below.
If the eggs breaks at a certain floor, it will break at any floor above.
For more description on this problem see wiki page

Input:
The first line of input is  T denoting the number of testcases.Then each of the T lines contains two positive integer N and K where 'N' is the number of eggs and 'K' is number of floor in building.

Output:
For each test case, print a single line containing one integer the minimum number of attempt you need in order find the critical floor.

Constraints:
1<=T<=30
1<=N<=10
1<=K<=50

Example:
Input:
2
2 10
3 5

Output:
4
3
'''

def eggDrop(n, k):
    # code here
    INT_MAX=float("infinity")
    dp = [[0 for x in range(k+1)] for x in range(n+1)] 
  
    for i in range(1, n+1): 
        dp[i][1] = 1
        dp[i][0] = 0
 
    for j in range(1, k+1): 
        dp[1][j] = j 

    for i in range(2, n+1): 
        for j in range(2, k+1): 
            dp[i][j] = INT_MAX 
            for x in range(1, j+1): 
                res = 1 + max(dp[i-1][x-1], dp[i][j-x]) 
                if res < dp[i][j]: 
                    dp[i][j] = res 
  
    return dp[n][k] 

