# 🚀 Complete Recursion Roadmap (DSA / CP / Interviews)

A structured guide to master **Recursion & Backtracking** from basics → advanced with logic, dry runs, and patterns.

---

# 📌 1. What is Recursion?

Recursion is a technique where a function **calls itself** to solve smaller subproblems.

### 🔑 Key Components:

* **Base Case** → stopping condition
* **Recursive Call** → function calls itself
* **Work** → processing before/after call

---

# 🟢 2. Basic Recursion (Foundation)

## 🔹 Factorial

### Logic:

```
n! = n * (n-1)!
```

### Code:

```cpp
int fact(int n){
    if(n==0) return 1;
    return n * fact(n-1);
}
```

### 🧠 Dry Run (n = 3):

```
fact(3)
= 3 * fact(2)
= 3 * 2 * fact(1)
= 3 * 2 * 1 * fact(0)
= 6
```

---

## 🔹 Fibonacci

### Logic:

```
f(n) = f(n-1) + f(n-2)
```

### Code:

```cpp
int fib(int n){
    if(n<=1) return n;
    return fib(n-1) + fib(n-2);
}
```

---

## 🔹 Sum of N Numbers

### Functional:

```cpp
int sum(int n){
    if(n==0) return 0;
    return n + sum(n-1);
}
```

### Parameterized:

```cpp
void sum(int n, int s){
    if(n==0){
        cout<<s;
        return;
    }
    sum(n-1, s+n);
}
```

---

## 🔹 Power (a^b)

```cpp
int power(int a,int b){
    if(b==0) return 1;
    return a * power(a,b-1);
}
```

---

# 🔁 3. Recursion Patterns (CORE)

---

## 🔸 Print 1 to N

```cpp
void print(int n){
    if(n==0) return;
    print(n-1);
    cout<<n<<" ";
}
```

---

## 🔸 Print N to 1

```cpp
void print(int n){
    if(n==0) return;
    cout<<n<<" ";
    print(n-1);
}
```

---

# 🔷 4. Subsequence Pattern ⭐

👉 MOST IMPORTANT for CP

## 🔹 Generate All Subsequences

```cpp
void solve(int i, vector<int>& arr, vector<int>& ds){
    if(i==arr.size()){
        for(auto x:ds) cout<<x<<" ";
        cout<<endl;
        return;
    }

    // pick
    ds.push_back(arr[i]);
    solve(i+1, arr, ds);

    // not pick
    ds.pop_back();
    solve(i+1, arr, ds);
}
```

---

### 🧠 Dry Run (arr = [1,2]):

```
[]
[1]
[2]
[1,2]
```

---

## 🔹 Subsequence Sum = K

```cpp
void solve(int i, vector<int>& arr, int sum, int k){
    if(i==arr.size()){
        if(sum==k) cout<<"YES\n";
        return;
    }

    solve(i+1, arr, sum+arr[i], k);
    solve(i+1, arr, sum, k);
}
```

---

# 🔷 5. Subset / Power Set

```cpp
vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> res;
    int n=nums.size();

    for(int mask=0;mask<(1<<n);mask++){
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(mask & (1<<i))
                temp.push_back(nums[i]);
        }
        res.push_back(temp);
    }
    return res;
}
```

---

# 🔷 6. Permutations

```cpp
void permute(vector<int>& nums, int idx){
    if(idx==nums.size()){
        for(int x:nums) cout<<x<<" ";
        cout<<endl;
        return;
    }

    for(int i=idx;i<nums.size();i++){
        swap(nums[i],nums[idx]);
        permute(nums,idx+1);
        swap(nums[i],nums[idx]);
    }
}
```

---

# 🔷 7. Combination Problems

## 🔹 Combination Sum

```cpp
void solve(int i, vector<int>& arr, int target, vector<int>& ds){
    if(target==0){
        for(int x:ds) cout<<x<<" ";
        cout<<endl;
        return;
    }
    if(i==arr.size()) return;

    if(arr[i]<=target){
        ds.push_back(arr[i]);
        solve(i, arr, target-arr[i], ds);
        ds.pop_back();
    }

    solve(i+1, arr, target, ds);
}
```

---

# 🔷 8. String Recursion

## 🔹 Reverse String

```cpp
void reverse(string &s, int i){
    if(i>=s.size()/2) return;
    swap(s[i], s[s.size()-i-1]);
    reverse(s, i+1);
}
```

---

## 🔹 Palindrome Check

```cpp
bool isPal(string s,int i){
    if(i>=s.size()/2) return true;
    if(s[i]!=s[s.size()-i-1]) return false;
    return isPal(s,i+1);
}
```

---

# 🔷 9. Recursion on Arrays

## 🔹 Check Sorted

```cpp
bool sorted(vector<int>& arr,int i){
    if(i==arr.size()-1) return true;
    if(arr[i]>arr[i+1]) return false;
    return sorted(arr,i+1);
}
```

---

# 🔷 10. Backtracking (MOST IMPORTANT ⭐⭐⭐)

---

## 🔹 N-Queens

```cpp
bool isSafe(int row,int col,vector<string>& board,int n){
    for(int i=0;i<col;i++)
        if(board[row][i]=='Q') return false;

    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
        if(board[i][j]=='Q') return false;

    for(int i=row,j=col;i<n && j>=0;i++,j--)
        if(board[i][j]=='Q') return false;

    return true;
}
```

---

## 🔹 Rat in a Maze

```cpp
void solve(int i,int j,vector<vector<int>>& m,int n,string path){
    if(i==n-1 && j==n-1){
        cout<<path<<endl;
        return;
    }
}
```

---

# 🔷 11. Divide & Conquer

## 🔹 Merge Sort

```cpp
void mergeSort(vector<int>& a,int l,int r){
    if(l>=r) return;
    int mid=(l+r)/2;
    mergeSort(a,l,mid);
    mergeSort(a,mid+1,r);
}
```

---

# 🔷 12. Recursion + Memoization

## 🔹 Fibonacci Optimized

```cpp
int dp[100];

int fib(int n){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=fib(n-1)+fib(n-2);
}
```

---

# 🔷 13. Tree Recursion

## 🔹 Height of Tree

```cpp
int height(Node* root){
    if(root==NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}
```

---

# 🔷 14. Recursion in CP

* Bitmask recursion
* DFS (graph traversal)
* Meet in the middle
* Pruning

---

# 📚 15. Learning Order (VERY IMPORTANT)

1. Basic recursion
2. Subsequence
3. Permutations
4. Backtracking
5. Divide & conquer
6. Trees
7. DP (memoization)

---

# 🧪 16. Practice Problems

## 🟢 Easy

* Factorial
* Fibonacci
* Print 1 to N

## 🟡 Medium

* Subsets
* Permutations
* Combination Sum

## 🔴 Hard

* N-Queens
* Sudoku Solver
* Rat in a Maze

---

# 🔥 Final Tips

* Always identify:

  * Base case
  * Choice (pick/not pick)
* Think in **tree structure**
* Practice **dry runs manually**

---

# 🚀 Conclusion

Recursion =
👉 Breaking problem into smaller parts
👉 Solving via function calls
👉 Combining results

Master this → you unlock:

* Backtracking
* DP
* Graphs
* Trees

---

💡 Keep practicing — recursion becomes intuitive only with repetition!
