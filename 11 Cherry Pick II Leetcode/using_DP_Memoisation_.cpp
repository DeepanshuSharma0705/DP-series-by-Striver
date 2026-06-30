#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
  // base case : boundry
  if(j1 <0 || j1 >= m || j2 <0 || j2 >= m){
      return -1e9;
  }

  // returning base case
  if(i == n-1){
      if(j1 == j2) return grid[i][j1];
      else{
          return grid[i][j1] + grid[i][j2];
      }
  }

  if(dp[i][j1][j2] != -1){
      return dp[i][j1][j2];
  }

  

  int maxi = -1e9;

  for(int alic = -1; alic <=1; alic++){
    for(int bob = -1; bob<=1; bob++){
      if(j1 == j2){
          maxi = max(maxi, grid[i][j1] + solve(i+1, j1 + alic, j2 + bob, n, m, grid, dp));
      }
      else{
          maxi = max(maxi, grid[i][j1] + grid[i][j2] + solve(i+1, j1 + alic, j2 + bob, n, m, grid, dp));
      }
    }
  }
  return dp[i][j1][j2] = maxi;

}

int cherryPickup(vector<vector<int>>& grid) {
  // solution using memoisation
  
  int n =grid.size();
  int m =grid[0].size();

  vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));

  return solve(0,0,m-1,n,m,grid, dp);
    
}

int main(){
  
  return 0;
}