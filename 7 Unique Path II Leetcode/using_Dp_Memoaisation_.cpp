#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
  // this is the condintion if(indexs are valid but the element is present 1) then we not do cosider that path.
  if(i >=0 && j >=0 && grid[i][j] == 1){
      return 0;
  }

  if(i==0 && j==0){
      return 1;
  }

  if(i<0 || j<0){     // index vadiation
      return 0;   
  }

  if(dp[i][j] != -1) return dp[i][j];    // dp condition checking

  int up = solve(i-1, j, grid, dp);
  int left = solve(i, j-1, grid, dp);

  return dp[i][j] = up + left;    // dp updation
}

int main(){
  
  return 0;
}