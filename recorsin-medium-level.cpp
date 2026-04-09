// 🔸 2. Parameterized vs Functional Recursion
// ✅ (A) Parameterized Recursion
// 📘 Mathematical Idea
// Carry answer along:
// S(n,sum)=S(n−1,sum+n)
// 👉 Answer stored in parameter
// Each call updates the sum and waits for the smaller problem to solve.
// S(n,sum)=S(n−1,sum+n)
// Base case:
// S(0,sum)=sum
// Each call updates the sum and waits for the smaller problem to solve.
// S(n,sum)=S(n−1,sum+n)



// #include<bits/stdc++.h>
// using namespace std;
// void sum(int n,int s){
//     if(n==0){
//         cout<<s<<endl;
//         return;
//     }
//     sum(n-1,s+n);
// }
// int main(){
//     int n;
//     cin>>n;
//     sum(n,0);
//     return 0;
// }




// ✅ (B) Functional Recursion
// 📘 Mathematical Idea
// S(n)=n+S(n−1)
// 👉 Return answer
// Each call waits for the answer of the smaller problem.
// S(n)=n+S(n−1)
// Base case:
// S(0)=0
// Each call waits for the sum of the first n-1 numbers.
// S(n)=n+S(n−1)




// #include<bits/stdc++.h>
// using namespace std;
// int sum(int n){
//     if(n==0) return 0;
//     return n+sum(n-1);
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<sum(n)<<endl;
//     return 0;
// }




// 🔸 3. Backtracking Basics
// 📘 Core Idea
// 👉 “Do → Explore → Undo”
// Used to generate all possibilities
// 🔁 Pick / Not Pick Pattern
// At each index:
// Pick element
// Do not pick element
// 👉 Explore both possibilities
// 🔁 Recursive Relation
// f(i)=f(i+1)+f(i+1)
// 👉 Explore both possibilities at each index
// Base case:
// f(n)=1
// When we reach the end of the array, we have found a valid combination, so we return 1.







// 🔹 1. Subsequence Pattern ⭐
// 📘 Mathematical Idea

// For each element:
// choices={pick,not pick}

// Total subsequences:
//2^n;




// #include<bits/stdc++.h>
// using namespace std;
// void subsequence(int i,vector<int>&arr,vector<int>&ds){
//     if(i==arr.size()){
//         for(auto it:ds){
//             cout<<it<<" ";
//         }
//         cout<<endl;
//         return;
//     }
//     // Pick the element
//     ds.push_back(arr[i]);
//     subsequence(i+1,arr,ds);
//     // Not pick the element
//     ds.pop_back();
//     subsequence(i+1,arr,ds);
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     vector<int>ds;
//     subsequence(0,arr,ds);
//     return 0;
// }




// 🔹 Subsequence Sum = K
// mathmatical Idea
// For each element:
// choices={pick,not pick}
// Total subsequences:
//2^n;
// Base case:
// When we reach the end of the array, we check if the sum of the current subsequence equals K. If it does, we return 1 to count this valid subsequence; otherwise, we return 0.
// f(i,sum)=f(i+1,sum+arr[i])+f(i+1,sum)
// 👉 Explore both possibilities at each index and keep track of the sum
// Base case:
// f(n,sum)=1 if sum==K else 0
// When we reach the end of the array, we check if the sum of the current subsequence equals K. If it does, we return 1 to count this valid subsequence; otherwise, we return 0.
//






// #include<bits/stdc++.h>
// using namespace std;
// int subsequenceSumK(int i,vector<int>&arr,int sum,int k){
//     if(i==arr.size()){
//         return sum==k?1:0;
//     }
//     // Pick the element
//     sum+=arr[i];
//     int pick=subsequenceSumK(i+1,arr,sum,k);
//     // Not pick the element
//     sum-=arr[i];
//     int notPick=subsequenceSumK(i+1,arr,sum,k);
//     return pick+notPick;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int k;
//     cin>>k;
//     cout<<subsequenceSumK(0,arr,0,k)<<endl;
//     return 0;
// }




//🔹 Count Subsequences = K
// mathmatical Idea
// For each element:
// choices={pick,not pick}
// Total subsequences:
//2^n;
// Base case:
// When we reach the end of the array, we check if the sum of the current subsequence equals K. If it does, we return 1 to count this valid subsequence; otherwise, we return 0.
// f(i,sum)=f(i+1,sum+arr[i])+f(i+1,sum)
// 👉 Explore both possibilities at each index and keep track of the sum
// Base case:
// f(n,sum)=1 if sum==K else 0





// #include<bits/stdc++.h>
// using namespace std;

// int countSubsequence(int i,vector<int>&arr,int sum,int k){
//     if(i==arr.size()){
//         return (sum==k);
//     }
//     // Pick the element
//     int pick=countSubsequence(i+1,arr,sum+arr[i],k);
//     // Not pick the element
//     int notPick=countSubsequence(i+1,arr,sum,k);
//     return pick+notPick;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int k;
//     cin>>k;
//     cout<<countSubsequence(0,arr,0,k)<<endl;
//     return 0;
// }





// 🔹 2. Subset / Power Set
// 👉 Same as subsequence
// Total subsets:
//2^n;


// #include<bits/stdc++.h>
// using namespace std;
// vector<vector<int>>ans;
// void subset(int i,vector<int>&arr,vector<int>&ds){
//     if(i==arr.size()){
//         ans.push_back(ds);
//         return;
//     }
//     // Pick the element
//     ds.push_back(arr[i]);
//     subset(i+1,arr,ds);
//     // Not pick the element
//     ds.pop_back();
//     subset(i+1,arr,ds);
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     vector<int>ds;
//     subset(0,arr,ds);
//     for(auto it:ans){
//         for(auto i:it){
//             cout<<i<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }




// 🔹 3. Permutations
// 📘 Idea
// Fix one element, permute rest
// Total permutations:
// n!
// Base case:
// When we have fixed all elements, we have found a valid permutation, so we return 1 to count this valid permutation; otherwise, we return 0.
// f(i)=f(i+1)+f(i+1)+…+f(i+n-1)
// 👉 Explore all possibilities by swapping elements at each index
// Base case:
// f(n)=1
// When we have fixed all elements, we have found a valid permutation, so we return 1 to count this valid permutation; otherwise, we return 0.





// #include<bits/stdc++.h>
// using namespace std;
// int cnt=0;
// void permute(int i,vector<int>&arr){
//     if(i==arr.size()){
//         for(int x:arr){
//             cout<<x<<" ";
//         }
//         cnt++;
//         cout<<endl;
//     }
//     for(int j=i;j<arr.size();j++){
//         swap(arr[i],arr[j]);
//         permute(i+1,arr);
//         swap(arr[i],arr[j]);// Backtrack to restore original array
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     permute(0,arr);
//     cout<<cnt<<endl;
//     return 0;
// }




// 🔹 4. Combinations
// 💻 Combination Sum
// 📘 Idea
// Fix one element, combine with rest
// Total combinations:
// 2^n
// Base case:
// When we have fixed all elements, we have found a valid combination, so we return 1 to count this valid combination; otherwise, we return 0.
// f(i)=f(i+1)+f(i+1)+…+f(i+n-1)
// 👉 Explore all possibilities by including elements at each index
// Base case:
// f(n)=1
// When we have fixed all elements, we have found a valid combination, so we return 1 to count this valid combination; otherwise, we return 0.



// #include<bits/stdc++.h>
// using namespace std;
// int cnt=0;
// void combSum(int i,vector<int>&arr,int target,vector<int>&ds){
//     if(i==arr.size()){
//        if(target==0){
//         for(int x:ds){
//             cout<<x<<" ";
//         }
//         cnt++;
//         cout<<endl; 
//     }
//    return;
// }
// // Pick the element
// if(arr[i]<=target){
//     ds.push_back(arr[i]);
//     combSum(i,arr,target-arr[i],ds);
//     ds.pop_back();
// }
// // Not pick the element
// combSum(i+1,arr,target,ds);
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int target;
//     cin>>target;
//     vector<int>ds;
//     combSum(0,arr,target,ds);
//     cout<<cnt<<endl;
//     return 0;
// }




// 🔹 5. String Recursion
// 🔹 Reverse String
//mathmatical Idea
// For each character:
// choices={pick,not pick}
// Total subsequences:
//2^n;
// Base case:
// When we reach the end of the string, we have found a valid reversed string, so
// we return 1 to count this valid reversed string; otherwise, we return 0.
// f(i)=f(i+1)+f(i+1)
// 👉 Explore both possibilities at each index and build the reversed string
// Base case:
// f(n)=1
// When we reach the end of the string, we have found a valid reversed string, so
// we return 1 to count this valid reversed string; otherwise, we return 0.


// #include<bits/stdc++.h>
// using namespace std;
// void reverseString(string &s,int i,int j){
//     if(i>=j)return;
//     swap(s[i],s[j]);
//     reverseString(s,i+1,j-1);
// }
// int main(){
//     string s;
//     cin>>s;
//     reverseString(s,0,s.size()-1);
//     cout<<s<<endl;
//     return 0;
// }






// 🔹 Palindrome Check
// mathmatical Idea
// For each character:
// choices={pick,not pick}
// Total subsequences:
//2^n;
// Base case:
// When we reach the end of the string, we have found a valid palindrome, so
// we return 1 to count this valid palindrome; otherwise, we return 0.
// f(i)=f(i+1)+f(i+1)
// 👉 Explore both possibilities at each index and check for palindrome
// Base case:
// f(n)=1
// When we reach the end of the string, we have found a valid palindrome, so
// we return 1 to count this valid palindrome; otherwise, we return 0.


// #include<bits/stdc++.h>
// using namespace std;
// bool isPalindrome(string &s,int i){
//     int n=s.size();
//     if(i>=n/2) return true;
//     if(s[i]!=s[n-1-i]) return false;
//     return isPalindrome(s,i+1);
// }
// int main(){
//     string s;
//     cin>>s;
//     if(isPalindrome(s,0)){
//         cout<<"Palindrome"<<endl;
//     }else{
//         cout<<"Not a Palindrome"<<endl;
//     }

//}



//🔹 Find Max
// mathmatical Idea
//max(arr[0],max(arr[1],max(arr[2],…max(arr[n-2],arr[n-1])…)))
// Base case:
// When we have compared all elements, we have found the maximum element, so we return that maximum element; otherwise, we return 0.
// f(i)=max(arr[i],f(i+1))
// 👉 Explore all possibilities by comparing elements at each index
// Base case:
// f(n)=arr[n-1]
// When we have compared all elements, we have found the maximum element, so we return that maximum element; otherwise, we return 0.



// #include<bits/stdc++.h>
// using namespace std;
// int findMax(int i,vector<int>&arr) {
//     if(i==arr.size()-1){
//         return arr[i];
//     }
//     int maxRest=findMax(i+1,arr);
//     return max(arr[i],maxRest);
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }
//     cout << findMax(0, arr) << endl;
//     return 0;
// }





// 🔹 7. Binary Search (Recursion)
// 📘 Mathematical Idea
// Divide range:
// mid=   low+(high-low)/2
// Base case:
// When we have found the target element, we return its index; otherwise, if the target element is not found in the array, we return -1.
// f(low,high)=f(low,mid-1) if target<mid
// f(low,high)=f(mid+1,high) if target>mid
// 👉 Explore the half of the array that may contain the target element
// Base case:
// f(low,high)=mid if arr[mid]==target
// When we have found the target element, we return its index; otherwise, if the target element is not found in the array, we return -1.



// #include<bits/stdc++.h>
// using namespace std;
// int binarySearch(int low,int high,vector<int>&arr,int target){
//     if(low>high) return -1;
//     int mid=low+(high-low)/2;
//     if(arr[mid]==target) return mid;
//     if(target<arr[mid]){
//         return binarySearch(low,mid-1,arr,target);
//     }else{
//         return binarySearch(mid+1,high,arr,target);
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int>arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int target;
//     cin>>target;
//     int result=binarySearch(0,n-1,arr,target);
//     if(result!=-1){
//         cout<<"Element found at index: "<<result<<endl;
//     }
//     else{
//         cout<<"Element not found in the array."<<endl;
//     }
// }





