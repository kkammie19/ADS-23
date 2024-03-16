#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        
        int count = 0;
        
        for (int j = 0; j < n; j++) {
            if ((l1 <= a[j] && a[j] <= r1) || (l2 <= a[j] && a[j] <= r2)) {
                count++;
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}

