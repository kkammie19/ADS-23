#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    map<int, int> number_count;
    int max_count = 0;

    for (int i = 0; i < n; ++i) {
        number_count[numbers[i]]++;
        max_count = max(max_count, number_count[numbers[i]]);
    }

    vector<int> modes;
    for (const auto& pair : number_count) {
        if (pair.second == max_count) {
            modes.push_back(pair.first);
        }
    }

    // Сортируем режимы в порядке убывания
    sort(modes.rbegin(), modes.rend());

    // Выводим режимы
    for (int mode : modes) {
        cout << mode<<" ";
    }

    return 0;
}
