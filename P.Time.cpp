#include <iostream>
#include <iomanip>

using namespace std;

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    // تابع برای تنظیم زمان و بررسی اعتبار آن
    void setTime(int h, int m, int s) {
        if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
            hours = h;
            minutes = m;
            seconds = s;
        } else {
            throw invalid_argument("زمان نامعتبر است.");
        }
    }

public:
    // سازنده پیش فرض
    Time() : hours(0), minutes(0), seconds(0) {}

    // سازنده با پارامتر
    Time(int h, int m, int s) {
        setTime(h, m, s);
    }

    // سازنده با زمان به صورت ثانیه
    Time(int totalSeconds) {
        hours = (totalSeconds / 3600) % 24;
        minutes = (totalSeconds / 60) % 60;
        seconds = totalSeconds % 60;
    }

    // تابع برای چاپ زمان به صورت HH:MM:SS
    void printTime() const {
        cout << setfill('0') << setw(2) << hours << ":"
             << setfill('0') << setw(2) << minutes << ":"
             << setfill('0') << setw(2) << seconds << endl;
    }

    // تابع برای محاسبه اختلاف بین دو زمان
    static Time difference(const Time& t1, const Time& t2) {
        int totalSec1 = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
        int totalSec2 = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
        int diffSeconds = abs(totalSec1 - totalSec2);

        return Time(diffSeconds);
    }
};

int main() {
    try {
        Time t1(14, 30, 45); // ایجاد زمان با سازنده پارامتر دار
        Time t2(8, 20, 15);  // ایجاد زمان دیگر

        cout << "زمان اول: ";
        t1.printTime();

        cout << "زمان دوم: ";
        t2.printTime();

        Time diff = Time::difference(t1, t2);
        cout << "اختلاف بین دو زمان: ";
        diff.printTime();

        int totalSeconds = 55555;
        Time t3(totalSeconds); // ایجاد زمان با تعداد ثانیه‌ها
        cout << "زمان از تعداد ثانیه‌ها: ";
        t3.printTime();

    } catch (const invalid_argument& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
