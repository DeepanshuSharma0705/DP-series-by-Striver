#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// methed 1: using Resursion 
int solve(int i, int j){
  // base case 
  if(i ==0 && j==0){
    return 1;
  }

  // boundary limit
  if(i <0 || j< 0){
    return 0;
  }

  int up = solve(i-1, j);    // if go up row will -1 and col will same
  int left = solve(i, j-1);   // if go left col will  -1 and row will same

  return up + left;        // sum of both unique path
}

int main(){
  
  return 0;
}