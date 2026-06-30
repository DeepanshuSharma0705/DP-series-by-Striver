#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve(int i, int j1, int j2, int n, int m, vector<vector<int>>& grid){
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

  int maxi = -1e9;

  for(int alic = -1; alic <=1; alic++){
      for(int bob = -1; bob<=1; bob++){
          if(j1 == j2){
              maxi = max(maxi, grid[i][j1] + solve(i+1, j1 + alic, j2 + bob, n, m, grid));
          }
          else{
              maxi = max(maxi, grid[i][j1] + grid[i][j2] + solve(i+1, j1 + alic, j2 + bob, n, m, grid));
          }
      }
  }
  return maxi;
}

int cherryPickup(vector<vector<int>>& grid) {
  int n =grid.size();
  int m =grid[0].size();

  return solve(0,0,m-1,n,m,grid);
    
}

int main(){
  
  return 0;
}