// 🔸 1. Backtracking ⭐⭐⭐ (MOST IMPORTANT)
// 📘 Core Idea
// 👉 Try all possibilities + undo (backtrack)
// Answer=All valid configurations
// Used to generate all possibilities
// 🔁 Recursive Relation
// f(i)=f(i+1)+f(i+1)
// 👉 Explore both possibilities at each index
// Base case:
// f(n)=1
// When we have fixed all elements, we have found a valid configuration, so we return
// 1 to count this valid configuration; otherwise, we return 0.





// 🔹 (A) N-Queens
// 📘 Idea

// Place queens such that:

// No same row
// No same column
// No diagonal conflict
// Total configurations:
// n!
// Base case:
// When we have placed all queens, we have found a valid configuration, so we return
// 1 to count this valid configuration; otherwise, we return 0.
// f(i)=f(i+1)+f(i+1)+…+f(i+n-1)
// 👉 Explore all possibilities by placing queens at each index
// Base case:
// f(n)=1
// When we have placed all queens, we have found a valid configuration, so we return
// 1 to count this valid configuration; otherwise, we return 0.

// #include<bits/stdc++.h>
// using namespace std;
// bool issafe(int row,int col,vector<string>&board,int n){
//     int r=row,c=col;
//     // Check upper diagonal
//     while(r>=0 && c>=0){
//         if(board[r][c]=='Q') return false;
//         r--;
//         c--;
//     }
//     // Check left
//     c=col,r=row;
//     while(c>=0){
//         if(board[r][c]=='Q') return false;
//         c--;
//     }
//     // Check lower diagonal
//     r=row,c=col;
//     while(r<n && c>=0){
//         if(board[r][c]=='Q') return false;
//         r++;
//         c--;
//     }
//     return true;
// }

// void solve(int col,vector<string>&board,int n,vector<vector<string>>&ans){
//     if(col==n){
//         ans.push_back(board);
//         return;
//     }
//     for(int row=0;row<n;row++){
//         if(issafe(row,col,board,n)){
//             board[row][col]='Q';
//             solve(col+1,board,n,ans);
//             board[row][col]='.';// Backtrack
//         }
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<string>board(n,string(n,'.'));
//     vector<vector<string>>ans;
//     solve(0,board,n,ans);
//     for(auto it:ans){
//         for(auto i:it){
//             cout<<i<<endl;
//         }
//         cout<<endl;
//     }
//     return 0;
// }



// 🔹 (B) Rat in a Maze
// 📘 Idea

// Move in 4 directions → avoid visited
// Total paths:
// 4^(n*m)
// Base case:
// When we reach the destination, we have found a valid path, so we return 1 to count this valid path; otherwise, we return 0.
// f(i,j)=f(i+1,j)+f(i-1,j)+f(i,j+1)+f(i,j-1)
// 👉 Explore all possibilities by moving in 4 directions at each step
// Base case:
// f(n,m)=1
// When we reach the destination, we have found a valid path, so we return 1 to count this valid path; otherwise, we return 0.



// #include<bits/stdc++.h>
// using namespace std;
// void solveMaze(int i,int j,vector<vector<int>>&maze,vector<vector<int>>&visited,int n,int m,int &cnt,string path){
//     if(i==n-1 && j==m-1){
//         cnt++;
//         cout<<path<<endl;
//         return;
//     }
//     if(i<0 || j<0 || i>=n || j>=m || maze[i][j]==0 || visited[i][j]==1){
//         return ;
//     }

//     visited[i][j]=1;
//     // Down
//     solveMaze(i+1,j,maze,visited,n,m,cnt,path+'D');
//     // Up
//     solveMaze(i-1,j,maze,visited,n,m,cnt,path+'U');
//     // Right
//     solveMaze(i,j+1,maze,visited,n,m,cnt,path+'R');
//     // Left
//     solveMaze(i,j-1,maze,visited,n,m,cnt,path+'L');
//     visited[i][j]=0;// Backtrack
//     maze[i][j]=1;// Backtrack
    
// }
// int main(){
//     int n,m;
//     cin>>n>>m;
//     vector<vector<int>>maze(n,vector<int>(m));
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             cin>>maze[i][j];
//         }
//     }
//     vector<vector<int>>visited(n,vector<int>(m,0));
//     int cnt=0;
//     solveMaze(0,0,maze,visited,n,m,cnt,"");
//     cout<<cnt<<endl;
//     return 0;
// }






// 🔹 (C) Sudoku Solver
// 📘 Idea

// Fill empty cells with valid digits (1–9)
// Total configurations:
// 9^(n*n)
// Base case:
// When we have filled all cells, we have found a valid configuration, so we return 1 to count this valid configuration; otherwise, we return 0.
// f(i,j)=f(i+1,j)+f(i-1,j)+f(i,j+1)+f(i,j-1)
// 👉 Explore all possibilities by filling digits at each cell
// Base case:
// f(n,n)=1
// When we have filled all cells, we have found a valid configuration, so we return 1 to count this valid configuration; otherwise, we return 0.



// #include<bits/stdc++.h>
// using namespace std;
// bool isValid(vector<vector<char>>&board,int row,int col,char c){
//     for(int i=0;i<9;i++){
//         if(board[row][i]==c) return false;
//         if(board[i][col]==c) return false;
//         if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
//     }
//     return true;
// }
// bool solveSudoku(vector<vector<char>>&board){
//     for(int i=0;i<9;i++){
//         for(int j=0;j<9;j++){
//             if(board[i][j]=='.'){
//                 for(char c='1';c<='9';c++){
//                     if(isValid(board,i,j,c)){
//                         board[i][j]=c;
//                         if(solveSudoku(board)) {
//                             return true;
//                         }
//                         board[i][j]='.'; // Backtrack
//                     }
//                 }
//                 return false; // No valid digit found, trigger backtracking
//             }
//         }
//     }
//     return true; // Solved
// }
// int main(){
//     vector<vector<char>>board(9,vector<char>(9));
//     for(int i=0;i<9;i++){
//         for(int j=0;j<9;j++){
//             cin>>board[i][j];
//         }
//     }
//     if(solveSudoku(board)){
//         for(int i=0;i<9;i++){
//             for(int j=0;j<9;j++){
//                 cout<<board[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//     }
//     else{
//         cout<<"No solution exists"<<endl;
//     }
//   return 0;
//     }





// 🔸 2. Divide and Conquer
// 📘 Idea
// Divide → Solve → Merge
// 🔁 Recursive Relation
// f(i)=f(i+1)+f(i+1)
// 👉 Explore both possibilities at each index
// Base case:
// f(n)=1
// When we have solved all subproblems, we have found a valid solution, so we return
// 1 to count this valid solution; otherwise, we return 0.
//approach is similar to backtracking but we combine results from subproblems instead of exploring all possibilities at each index.
//mathmatical Idea and implimentation is similar to backtracking but we combine results from subproblems instead of exploring all possibilities at each index.



// 🔹 1. Merge Sort
// 📘 Idea
// Divide array into halves → sort each half → merge
// Total operations:
// n log n
// Base case:





// #include<bits/stdc++.h>
// using namespace std;
// void merge(vector<int>&arr,int left,int m,int right){
//     vector<int>temp;
//     int i=left,j=m+1;
//     while(i<=m && j<=right){
//         if(arr[i]<=arr[j]){
//             temp.push_back(arr[i++]);
//         }
//         else{
//             temp.push_back(arr[j++]);
//         }
//     }
//     while(i<=m) temp.push_back(arr[i++]);
//     while(j<=right) temp.push_back(arr[j++]);
//     for(int k=left;k<=right;k++){
//         arr[k]=temp[k-left];
//     }
// }
// void mergesort(vector<int>& arr,int left,int right){
//     if(left>=right) return;
//     int mid=(left+right)/2;
//     mergesort(arr,left,mid);
//     mergesort(arr,mid+1,right);
//     merge(arr,left,mid,right);
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     mergesort(arr,0,n-1);
//     for(int x:arr){
//         cout<<x<<" ";
//     }
//     cout<<endl;
//     return 0;
// }




// 🔹 2. Quick Sort
// 📘 Idea
// Choose pivot → partition → sort partitions
// Total operations:
// n log n (average), n^2 (worst)
// Base case:
// When we have sorted all partitions, we have found a valid solution, so we return 1 to count this valid solution; otherwise, we return 0.
// f(left,right)=f(left,pivot-1)+f(pivot+1,right)
// 👉 Explore all possibilities by choosing different pivots at each step
// Base case:
// f(left,right)=1
// When we have sorted all partitions, we have found a valid solution, so we return 1 to count this valid solution; otherwise, we return 0.



// #include<bits/stdc++.h>
// using namespace std;
// void quicksort(vector<int>&arr,int left,int right){
//     if(left>=right) return;
//     int pivot=arr[right];
//     int i=left;
//     for(int j=left;j<right;j++){
//         if(arr[j]<pivot){
//             swap(arr[i],arr[j]);
//             i++;
//         }
//     }
//     swap(arr[i],arr[right]);
//     quicksort(arr,left,i-1);
//     quicksort(arr,i+1,right);
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     quicksort(arr,0,n-1);
//     for(int x:arr){
//         cout<<x<<" ";
//     }
//     cout<<endl;
//     return 0;
// }



// 🔸 3. Recursion + Memoization (DP Intro)
// 🔹 Fibonacci Optimized
// 📘 Idea
// Store previously computed results to avoid redundant calculations
// Total operations:
// n (linear)
// Base case:
// When we have computed the Fibonacci number for all n, we have found a valid solution, so we return 1 to count this valid solution; otherwise, we return 0.
// f(n)=f(n-1)+f(n-2)
// 👉 Explore all possibilities by computing Fibonacci numbers at each index and storing results
// Base case:
// f(n)=1
// When we have computed the Fibonacci number for all n, we have found a valid solution, so we return 1 to count this valid solution; otherwise, we return 0.



// #include<bits/stdc++.h>
// using namespace std;
// int fibonacci(int n,vector<int>&dp){
//     if(n==0) return 0;
//     if(n==1) return 1;
//     if(dp[n]!=-1) return dp[n];
//     return dp[n]=fibonacci(n-1,dp) +fibonacci(n-2,dp);
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>dp(n+1,-1);
//     cout<<fibonacci(n,dp)<<endl;
//     return 0;
// }




// 🔹 Climbing Stairs
// 📘 Idea
// f(n)=f(n−1)+f(n−2)
// Total ways:
// n (linear)
// Base case:
// When we have computed the number of ways to climb all stairs, we have found a valid solution, so we return 1 to count this valid solution; otherwise, we return 0.
// f(n)=f(n-1)+f(n-2)
// 👉 Explore all possibilities by computing ways to climb stairs at each index and storing results
// Base case:
// f(n)=1
// When we have computed the number of ways to climb all stairs, we have found a valid solution, so we return 1 to count this valid solution; otherwise, we return 0.



// #include<bits/stdc++.h>
// using namespace std;
// int climbStairs(int n,vector<int>&dp){
//     if(n==0) return 1;
//     if(n<0) return 0;
//     if(dp[n]!=-1) return dp[n];
//     return dp[n]=climbStairs(n-1,dp) +climbStairs(n-2,dp);
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>dp(n+1,-1);
//     cout<<climbStairs(n,dp)<<endl;
//     return 0;
// }





// 🔸 4. Recursion + Tabulation (DP Intro)
// 🔹 Fibonacci Tabulation
// 📘 Idea
// Build a table bottom-up to compute Fibonacci numbers
// Total operations:
// n (linear)
// Base case:
// When we have computed the Fibonacci number for all n, we have found a valid solution, so we return 1 to count this valid solution; otherwise, we return 0.
// f(n)=f(n-1)+f(n-2)
// 👉 Explore all possibilities by computing Fibonacci numbers at each index and storing results
// Base case:
// f(n)=1
// When we have computed the Fibonacci number for all n, we have found a valid solution, so we return 1 to count this valid solution; otherwise, we return 0.



// #include<bits/stdc++.h>
// using namespace std;
// int fibonacci(int n){
//     if(n==0) return 0;
//     if(n==1) return 1;
//     vector<int>dp(n+1);
//     dp[0]=0;
//     dp[1]=1;
//     for(int i=2;i<=n;i++){
//         dp[i]=dp[i-1]+dp[i-2];
//     }
//     return dp[n];
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<fibonacci(n)<<endl;
//     return 0;
// }





