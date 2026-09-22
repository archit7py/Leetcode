class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        
        vector<string> week = {
            "Friday", "Saturday", "Sunday",
            "Monday", "Tuesday", "Wednesday", "Thursday"
        };
        
        int days = 0;

        // Days from previous years
        for(int y = 1971; y < year; y++) {
            if((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0))
                days += 366;
            else
                days += 365;
        }

        // Days from previous months
        vector<int> monthDays = {
            31,28,31,30,31,30,
            31,31,30,31,30,31
        };

        // Leap year
        if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
            monthDays[1] = 29;

        for(int m = 0; m < month - 1; m++) {
            days += monthDays[m];
        }

        // Days before current day
        days += day - 1;

        return week[days % 7];
    }
};