#include <iostream>
#include <vector>
using namespace std;

bool comparator(vector<int> a,vector<int> b){
    if(a[a.size()-1]==b[b.size()-1]){
            for(int i=0;i<a.size();i++){
                if(a[i]!=b[i]){
                    return a[i]<b[i];
                }
            }

    }
    else{
    return a[a.size()-1]>b[b.size()-1];
    }

}
void merge(vector<int> a[], int l1, int r1, int l2, int r2){

    int n1 = r1 - l1 + 1;
    vector<int> L[n1];
    for(int i = 0; i < n1; ++i){
        L[i] = a[l1 + i];
    }

    int n2 = r2 - l2 + 1;
    vector<int> R[n2];
    for(int i = 0; i < n2; ++i){
        R[i] = a[l2 + i];
    }
    int i = l1;
    int i1 = 0;
    int i2 = 0;
    while(i1 < n1 && i2 < n2){
        if(comparator(L[i1],R[i2])){
            a[i++] = L[i1++];
        }else {
            a[i++] = R[i2++];
        }
    }

    //copy rest of L
    while(i1 < n1){
        a[i++] = L[i1++];
    }

    //copy rest of R
    while(i2 < n2){
        a[i++] = R[i2++];
    }

}


void msort(vector<int> a[], int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        msort(a, l, m);
        msort(a, m + 1, r);
        merge(a, l, m , m + 1, r);
    }
}


int main(){
    int n, m, x;
    cin >> n >> m;
    vector<int> v[n];
    for(int i = 0; i < n; ++i){
            int sum=0;
        for(int j = 0; j < m; ++j){
            cin >> x;
            sum+=x;
            v[i].push_back(x);
        }
        v[i].push_back(sum);
    }
    msort(v, 0, n - 1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
