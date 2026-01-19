
#include <iostream>
#include <array>
#include <string>
#include <typeinfo>
using namespace std;
class watch {
private:
    bool date(string d) {
        for (string el : week) {
            if (el == d) {
                return true;
            }
        }
        return false;
    }
    array <string, 7> week = {"Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота", "Воскресенье"};
    int day;
    int month;
    int year;
    int hours;
    int min;
    int const high_year = 2024;
    string day_of_week;
    int days_of_month(int month, int year) {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            return 31;
        }
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            return 30;
        }
        if ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0)) {  
            return 29;
        }
        else {
            return 28;
        }
    }

public:
    watch() { cout << "Конструктор по умолчанию" << endl; }
    watch(int d, int m, int y, int h, int mi, string dow) {
        cout << "Конструктор полного заполнения" << endl;
        if (date(dow) == false) {
            throw invalid_argument("Нужно ввести день недели!!!");
        }
        if (y < 0) {
            throw length_error("Год не может быть отрицательным!!!");
        }
        if (m > 12 || m < 1) {
            throw out_of_range("Месяц должен быть от 1 до 12!!!");
            if (days_of_month(m, y) == 31) {
                if (d > 31 || d < 0) { throw out_of_range("Дней должно быть не меньше чем 0 и не больше 31"); }
            }
            if (days_of_month(m, y) == 30) {
                if (d > 30 || d < 0) { throw out_of_range("Дней должно быть не меньше чем 0 и не больше 30"); }
            }
            if (days_of_month(m, y) == 28) {
                if (d > 28 || d < 0) { throw out_of_range("Дней должно быть не меньше чем 0 и не больше 28"); }
            }
            if (days_of_month(m, y) == 29) {
                if (d > 29 || d < 0) { throw out_of_range("Дней должно быть не меньше чем 0 и не больше 29"); }
            }
        }
        day = d;
        month = m;
        year = y;
        hours = h;
        min = mi;
        SetDay_of_week(dow);
    }
    ~watch() { cout << "Класс: Watch удален" << endl;}

    // геттеры
    int getMonth()const { return month; }
    int getDay()const { return day; }
    int getYear()const { return year; }
    int getHours()const { return hours; }
    int getMin()const { return min; }
    string getDay_of_week()const { return day_of_week; }
    // сеттер

    void SetDay_of_week(string day_of_week1) {
        if (date(day_of_week1) == false) {
            throw invalid_argument("Нужно ввести день недели!!!");
        }
        day_of_week = day_of_week1;
    }

    void PrintAll() {
        cout << "Дата: " << day << '.' << month << '.' << year << endl;
        cout << "Время: " << hours << ':' << min << endl;
        cout << "День недели: " << day_of_week << endl;
    }

    void AddMinute(int x) {
        min += x;
        if (x < 0) {
            throw invalid_argument("Минуты не могут быть отрицательными!!!");
        }
        int orig_day = day;
        if (min >= 60) {
            hours += min / 60;
            min = min % 60;
        }

        if (hours >= 24) {
            day += hours / 24;
            hours = hours % 24;
        }

        while (day > days_of_month(month, year)) {
            day -= days_of_month(month, year);
            ++month;
            if (month > 12) {
                month = 1;
                ++year;
            }
        }
        int days_passed = day - orig_day;
        if (days_passed < 0) {
            days_passed = days_of_month(month, year) + days_passed;
        }
        int ind = -1;
        if (days_passed > 0) {
            for (int i = 0; i != week.size(); ++i) {
                if (week[i] == day_of_week) {
                    ind = i;
                    break;
                }
            }
            if (ind != -1) {
                int new_ind = (ind + days_passed) % 7;
                day_of_week = week[new_ind];
            }
        }


    }
};

int main()
{
    setlocale(LC_ALL, "RUS");
    try {
        watch myWatch(18, 1, 2026, 3, 17, "Воскресенье");
        myWatch.AddMinute(1440);
        myWatch.PrintAll();
    }
    catch (invalid_argument& res) {
        cerr << res.what() << endl;
    }
    catch (out_of_range& sss) {
        cerr << sss.what() << endl;
    }
    catch (length_error& e) {
        cerr << e.what() << endl;
    }
    catch (exception& e) {
        cerr << "Неизвестная ошибка: " << e.what() << endl;
    }


    try {
        watch myWatch(18, 1, 2026, 3, 17, "Понедельник");
        myWatch.AddMinute(-1440);
        myWatch.PrintAll();
    }
    catch (invalid_argument& res) {
        cerr << res.what() << endl;
    }   
    catch (out_of_range& sss) {
        cerr << sss.what() << endl;
    }
    catch (length_error& e) {
        cerr << e.what() << endl;
    }
    catch (exception& e) {
        cerr << "Неизвестная ошибка: " << e.what() << endl;
    }



    try {
        watch myWatch(18, 56, 2026, 3, 17, "Понедельник");
        myWatch.AddMinute(1440);
        myWatch.PrintAll();
    }
    catch (length_error& er) {
        cout << er.what() << endl;
    }
    catch (invalid_argument& res) {
        cerr << res.what() << endl;
    }
    catch (out_of_range& sss) {
        cerr << sss.what() << endl;
    }
    catch (exception& e) {
        cerr << "Неизвестная ошибка: " << e.what() << endl;
    }
    catch (length_error& e) {
        cerr << e.what() << endl;
    }

}
