#include <iostream>
#include <vector>

using namespace std;

int findBlock(const vector<int>& blocksEnd, int mistakeLine) {
    int left = 0;
    int right = blocksEnd.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (blocksEnd[mid] >= mistakeLine) {
            if (mid == 0 || blocksEnd[mid - 1] < mistakeLine) {
                return mid + 1;
            }
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1; // This should not happen
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> blockSizes(N);
    vector<int> blocksEnd(N);

    for (int i = 0; i < N; i++) {
        cin >> blockSizes[i];
        if (i == 0) {
            blocksEnd[i] = blockSizes[i];
        } else {
            blocksEnd[i] = blocksEnd[i - 1] + blockSizes[i];
        }
    }

    for (int i = 0; i < M; i++) {
        int mistakeLine;
        cin >> mistakeLine;
        int blockNumber = findBlock(blocksEnd, mistakeLine);
        cout << blockNumber << endl;
    }

    return 0;
}
