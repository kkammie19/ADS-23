#include <iostream>
#include <cmath>
using namespace std;


string get_string(long long a[], long long n) {
    int mod = 1e10+7;
    string s = "";
    long long pow_p = 1;
    for(int i = 0;i<n;i++) {
            long long x;
        if(i!=0){
            x = a[i]-a[i-1];
        }else{
        x = a[i];
        }
        x = x / pow_p;

        char letter = x+97;
        s += letter;
        pow_p = pow_p * 2;
    }
    return s;
}



int main () {

    long long n;
    cin >> n;
    long long a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << get_string(a, n) << endl;
}     
