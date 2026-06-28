#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// methed 1: using Dp Memoisation Process 
int solve(int i, int j, vector<vector<int>> &dp){
  // base case 
  if(i ==0 && j==0){
      return 1;
  }

  // boundary limit
  if(i <0 || j< 0){
      return 0;
  }

  // DP checking
  if(dp[i][j] != -1){
      return dp[i][j];
  }

  int up = solve(i-1, j, dp);    // if go up row will -1 and col will same
  int left = solve(i, j-1, dp);   // if go left col will  -1 and row will same

  return dp[i][j] = up + left;        // dp Updation : sum of both unique path
}

int main(){
  
  return 0;
}