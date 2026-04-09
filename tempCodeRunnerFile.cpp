#include<bits/stdc++.h>
using namespace std;
void solveMaze(int i,int j,vector<vector<int>>&maze,vector<vector<int>>&visited,int n,int m,int &cnt,string path){
    if(i==n-1 && j==m-1){
        cnt++;
        cout<<path<<endl;
        return;
    }
    if(i<0 || j<0 || i>=n || j>=m || maze[i][j]==0 || visited[i][j]==1){
        return ;
    }

    visited[i][j]=1;
    // Down
    solveMaze(i+1,j,maze,visited,n,m,cnt,path+'D');
    // Up
    solveMaze(i-1,j,maze,visited,n,m,cnt,path+'U');
    // Right
    solveMaze(i,j+1,maze,visited,n,m,cnt,path+'R');
    // Left
    solveMaze(i,j-1,maze,visited,n,m,cnt,path+'L');
    visited[i][j]=0;// Backtrack
    maze[i][j]=1;// Backtrack
    
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>maze(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
        }
    }
    vector<vector<int>>visited(n,vector<int>(m,0));
    int cnt=0;
    solveMaze(0,0,maze,visited,n,m,cnt,"");
    cout<<cnt<<endl;
    return 0;
}