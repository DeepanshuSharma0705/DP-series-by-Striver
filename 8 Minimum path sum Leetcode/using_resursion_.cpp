#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve(int i, int j, vector<vector<int>>& grid){
  // base case
  if(i == 0 && j ==0 ) return grid[0][0];
  if(i <0 || j < 0) return 1e9;

  int up = grid[i][j] + solve(i-1, j, grid);
  int left = grid[i][j] + solve(i, j-1, grid);

  return min(up, left);
}

int main(){

  vector<vector<int>> grid;
  int m= grid.size();
  int n= grid[0].size();


  int ans = solve(m-1, n-1, grid);
  
  return 0;
}