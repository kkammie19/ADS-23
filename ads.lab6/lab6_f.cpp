#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Student {
    string lastname;
    string firstname;
    double gpa;
};

double calculateGPA(const vector<string>& marks, const vector<int>& credits) {
    double gpa = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < marks.size(); i++) {
        if (marks[i] == "A+") {
            gpa += 4.00 * credits[i];
        } else if (marks[i] == "A") {
            gpa += 3.75 * credits[i];
        } else if (marks[i] == "B+") {
            gpa += 3.50 * credits[i];
        } else if (marks[i] == "B") {
            gpa += 3.00 * credits[i];
        } else if (marks[i] == "C+") {
            gpa += 2.50 * credits[i];
        } else if (marks[i] == "C") {
            gpa += 2.00 * credits[i];
        } else if (marks[i] == "D+") {
            gpa += 1.50 * credits[i];
        } else if (marks[i] == "D") {
            gpa += 1.00 * credits[i];
        } else if (marks[i] == "F") {
            gpa += 0.00 * credits[i];
        }
        totalCredits += credits[i];
    }

    if (totalCredits == 0) {
        return 0.0;
    }

    return gpa / totalCredits;
}

int partition(vector<Student>& students, int low, int high) {
    Student pivot = students[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (students[j].gpa < pivot.gpa ||
            (students[j].gpa == pivot.gpa &&
             (students[j].lastname < pivot.lastname || (students[j].lastname == pivot.lastname && students[j].firstname < pivot.firstname)))) {
            i++;
            swap(students[i], students[j]);
        }
    }

    swap(students[i + 1], students[high]);
    return i + 1;
}

void quickSort(vector<Student>& students, int low, int high) {
    if (low < high) {
        int pi = partition(students, low, high);
        quickSort(students, low, pi - 1);
        quickSort(students, pi + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    vector<Student> students(n);

    for (int i = 0; i < n; i++) {
        students[i].gpa = 0.0;
        cin >> students[i].lastname >> students[i].firstname;
        int numSubjects;
        cin >> numSubjects;
        vector<string> marks(numSubjects);
        vector<int> credits(numSubjects);
        for (int j = 0; j < numSubjects; j++) {
            cin >> marks[j] >> credits[j];
        }
        students[i].gpa = calculateGPA(marks, credits);
    }

    quickSort(students, 0, n - 1);

    cout << fixed << setprecision(3);
    for (int i = 0; i < n; i++) {
        cout << students[i].lastname << " " << students[i].firstname << " " << students[i].gpa << endl;
    }

    return 0;
}

