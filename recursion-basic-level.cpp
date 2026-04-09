// 🔹 1. Factorial
// 📘 Mathematical Definition
// n!=n×(n−1)×(n−2)×⋯×1

// Base case:
// 0!=1
// 🔁 Recursive Idea
// n!=n×(n−1)!
// 👉 Each function call waits for the next smaller factorial.


// #include<bits/stdc++.h>
// using namespace std;
// int fact(int n){
//     if(n==0) return 1;
//     return n*(fact(n-1));
// }
// int main(){
//     int n;cin>>n;
//     cout<<fact(n)<<endl;
//     return 0;
// }


// 🔹 2. Fibonacci
// 📘 Mathematical Definition
// F(n)=F(n−1)+F(n−2)
// Base cases:
// F(0)=0,F(1)=1
// 🔁 Recursive Idea
// Each call splits into two subproblems.
// 🧠 Call Stack (Example: F(4))
// fib(4)
// → fib(3) + fib(2)
// → (fib(2)+fib(1)) + (fib(1)+fib(0))

// #include<bits/stdc++.h>
// using namespace std;
// int fibonacci(int n){
//     if(n==0) return 0;
//     if(n==1) return 1;
//     return fibonacci(n-1) +fibonacci(n-2);
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<fibonacci(n)<<endl;
//     return 0;
// }

// 🔹 3. Fibonacci with Debugging

// #include <iostream>
// using namespace std;
// int fibonacci(int n) {
//     if (n == 0) {
//         cout << "fib(0) = 0" << endl;
//         return 0;
//     }
//     if (n == 1) {
//         cout << "fib(1) = 1" << endl;
//         return 1;
//     }
//     int result = fibonacci(n - 1) + fibonacci(n - 2);
//     cout << "fib(" << n << ") = " << result << endl;
//     return result;
// }

// int main() {
//    int n;
//    cin>>n;
//    fibonacci(n);
//     return 0;
// }




// 🔹 3. Sum of First N Numbers
// 📘 Mathematical Definition
// S(n)=1+2+3+⋯+n
// Closed form:
// S(n)=n(n+1)/2
// 🔁 Recursive Idea
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



// 🔹 4. Power Function

// 🔹 4. Power (a^b)
// 📘 Mathematical Definition
// //power(a,b)=a×a×a×⋯×a (b times)
// Base case:
// power(a,0)=1
// 🔁 Recursive Idea
// power(a,b)=a×power(a,b−1)
// 🧠 Flow (Example: 2³)
// power(2,3)
// → 2 * power(2,2)
// → 2 * (2 * power(2,1))
// → 2 * 2 * 2 * power(2,0)
// → 8


// #include<bits/stdc++.h>
// using namespace std;
// int power(int a,int b){
//     if(b==0) return 1;
//     return a*power(a,b-1);
// }
// int main(){
//     int a,b;
//     cin>>a>>b;
//     cout<<power(a,b)<<endl;
//     return 0;
// }




// 🔸 1. Print 1 to N
// 📘 Mathematical Idea
// We want:
// 1,2,3,…,N
// 🔁 Recursive Relation
// print(n)=print(n−1)+n

// 👉 First solve smaller problem, then print current.


// #include<bits/stdc++.h>
// using namespace std;
// void print(int n){
//     if(n==0) return;
//     print(n-1);
//     cout<<n<<" ";// After the recursive call, we print n.
// }
// int main(){
//     int n;
//     cin>>n;
//     print(n);
//     return 0;
// }



// 🔸 2. Print N to 1
// 📘 Mathematical Idea
// We want:
// N,N−1,N−2,…,1
// 🔁 Recursive Relation
// print(n)=n+print(n−1)
// 👉 Print current first, then solve smaller problem.

// #include<bits/stdc++.h>
// using namespace std;
// void print(int n){
//     if(n==0) return;
//     cout<<n<<" ";// First we print n, then we make the recursive call.
//     print(n-1);
// }
// int main(){
//     int n;
//     cin>>n;
//     print(n);
//     return 0;
// }



// 3. Print Name N Times
// 📘 Mathematical Idea
// Repeat a string N times
// f(n)=name+f(n−1)
// 🔁 Recursive Relation
// print(n)=print(n−1)+"name"

// #include<bits/stdc++.h>
// using namespace std;
// void print(string name,int n){
//     if(n==0) return;
//     print(name,n-1);
//     cout<<name<<" ";// After the recursive call, we print the name.
// }
// int main(){
//     string name;
//     int n;
//     cin>>name>>n;
//     print(name,n);
//     return 0;
// }





