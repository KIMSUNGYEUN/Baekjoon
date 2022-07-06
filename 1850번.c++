#include <iostream> 
using namespace std; 
  
long long GCD(long long a, long long b) { 
    if (a % b == 0) 
        return b; 
  
    return GCD(b, a%b); 
} 
  
int main(void) { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    long long a, b; 
    cin >> a >> b; 
  
    long long result = GCD(a, b); 
    for (int i = 0; i < result; i++) 
        cout << 1; 
    cout << "\n"; 
} 
