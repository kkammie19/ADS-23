#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> stones(N);
    for (int i = 0; i < N; i++) {
        cin >> stones[i];
    }

    while (stones.size() > 1) {
        
        sort(stones.rbegin(), stones.rend());

        int x = stones[0];
        int y = stones[1];

        
        stones.erase(stones.begin(), stones.begin() + 2);

        if (x != y) {
      
            stones.push_back(abs(x - y));
        }
    }

   
    cout << (stones.empty() ? 0 : stones[0]) << endl;

    return 0;
}
