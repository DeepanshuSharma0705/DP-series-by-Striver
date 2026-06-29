#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int solve(int i, int j, int n, vector<vector<int>>& triangle){
  // base case
  if(i == n-1){
      return triangle[n-1][j];
  }

  int down = triangle[i][j] + solve(i+1, j, n, triangle);
  int daigonal = triangle[i][j] + solve(i+1, j+1, n, triangle);

  return min(down, daigonal);
}


int main(){

  vector<vector<int>> triangle;
  int n = triangle.size();
  int ans = solve(0,0,n,triangle);

  
  return 0;
}