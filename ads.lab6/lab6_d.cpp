#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Date {
    int day, month, year;

    bool operator<(const Date& other) const {
        if (year != other.year) {
            return year < other.year;
        }
        if (month != other.month) {
            return month < other.month;
        }
        return day < other.day;
    }
};

int main() {
    int n;
    cin >> n;

    vector<Date> dates(n);

    for (int i = 0; i < n; i++) {
        string dateStr;
        cin >> dateStr;
        sscanf(dateStr.c_str(), "%d-%d-%d", &dates[i].day, &dates[i].month, &dates[i].year);
    }

    sort(dates.begin(), dates.end());

    for (const Date& date : dates) {
        printf("%02d-%02d-%04d\n", date.day, date.month, date.year);
    }

    return 0;
}
