#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to check if a character is a vowel
bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Separate vowels and consonants
    string vowels, consonants;
    for (int i = 0; i < n; i++) {
        if (isVowel(s[i])) {
            vowels += s[i];
        } else {
            consonants += s[i];
        }
    }

    // Sort both vowel and consonant strings
    sort(vowels.begin(), vowels.end());
    sort(consonants.begin(), consonants.end());

    // Merge the sorted vowel and consonant strings
    string result = vowels + consonants;

    cout << result << endl;

    return 0;
}

