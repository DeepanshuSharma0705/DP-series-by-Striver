#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
  // base case
  if(i == 0 && j ==0 ) return grid[0][0];
  if(i <0 || j < 0) return 1e9;

  if(dp[i][j] != -1){
      return dp[i][j];
  }

  int up = grid[i][j] + solve(i-1, j, grid, dp);
  int left = grid[i][j] + solve(i, j-1, grid, dp);

  return dp[i][j] = min(up, left);
}

int main(){
  
  return 0;
}