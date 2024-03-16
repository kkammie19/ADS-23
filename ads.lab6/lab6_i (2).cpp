#include <iostream>
#include <string>

using namespace std;

void quickSort(string& str, int left, int right) {
    if (left < right) {
        int pivot = left;
        int i = left;
        int j = right;

        while (i < j) {
            while (str[i] <= str[pivot] && i < right) {
                i++;
            }
            while (str[j] > str[pivot]) {
                j--;
            }
            if (i < j) {
                swap(str[i], str[j]);
            }
        }
        swap(str[pivot], str[j);

        quickSort(str, left, j - 1);
        quickSort(str, j + 1, right);
    }
}

int main() {
    string input;
    cin >> input;

    quickSort(input, 0, input.size() - 1);

    cout << input << endl;

    return 0;
}
