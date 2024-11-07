#include<iostream>
using namespace std;

int rfib(int n){
    if(n <= 0 || n == 1)
        return n;
    return rfib(n - 2) + rfib(n - 1);
}

void ifib(int n){
    int prev1 = 0;
    int prev2 = 1;
    int curr = 0;
    for (int i = 2; i <= n; i++){
        curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    cout << curr << endl;
}

int main(){

    int n;
    cout << "Enter n to find nth fibonacci no. " << endl;
    cin >> n;
    cout << "Recursive output: " << rfib(n) << endl;
    cout << "Iterative output: ";
    ifib(n);

}

