#include <iostream>
#include <vector>
#include <string>
using namespace std;

void merge(vector<string> &a, int l1, int r1, int l2, int r2) {
    int n1 = r1 - l1 + 1;
    vector<string> L(n1);
    for (int i = 0; i < n1; i++) {
        L[i] = a[l1 + i];
    }

    int n2 = r2 - l2 + 1;
    vector<string> R(n2);
    for (int i = 0; i < n2; i++) {
        R[i] = a[l2 + i];
    }

    int i = l1;
    int i1 = 0;
    int i2 = 0;

    while (i1 < n1 && i2 < n2) {
        if (L[i1].length() <= R[i2].length() || (L[i1].length() == R[i2].length() && L[i1] <= R[i2])) {
            a[i++] = L[i1++];
        } else {
            a[i++] = R[i2++];
        }
    }

    while (i1 < n1) {
        a[i++] = L[i1++];
    }
    while (i2 < n2) {
        a[i++] = R[i2++];
    }
}

void msort(vector<string> &a, int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        msort(a, l, mid);
        msort(a, mid + 1, r);
        merge(a, l, mid, mid + 1, r);
    }
}

int main() {
    int n;
    cin >> n;

    vector<string> result;

    for (int i = 0; i < n; i++) {
        while (true) {
            string x;
            cin >> x;
            result.push_back(x);
            if (cin.peek() == '\n') {
                break;
            }
        }
        msort(result, 0, result.size() - 1);
        for (int j = 0; j < result.size(); j++) {
            cout << result[j] << " ";
        }
        cout << endl;

        result.clear();
    }
}