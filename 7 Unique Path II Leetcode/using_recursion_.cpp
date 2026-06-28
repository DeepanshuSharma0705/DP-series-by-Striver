#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// method 1 : using Resursion
int solve(int i, int j, vector<vector<int>>& grid){
    if(i >=0 && j >=0 && grid[i][j] == 1){
        return 0;
    }

    if(i==0 && j==0){
        return 1;
    }

    if(i<0 || j<0){
        return 0;
    }

    int up = solve(i-1, j, grid);
    int left = solve(i, j-1, grid);

    return up + left;
}

int main(){
  
  return 0;
}