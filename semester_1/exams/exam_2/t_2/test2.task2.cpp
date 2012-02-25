#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

struct Date
{
    int day;
    int month;
    int year;

    Date(int d = 0, int m = 0, int y = 0) :
        day(d),
        month(m),
        year(y)
    {}
};

inline bool isLess(Date first, Date second)
{
    return (first.year < second.year || (first.year == second.year && 
            (first.month < second.month || (first.month == second.month && 
            first.day < second.day))));
}

Date getMinDate(ifstream &in)
{
    const int maxDay = 32;
    const int maxMonth = 13;
    const int maxYear = 10000;
    bool less = false;
    Date minDate(maxDay, maxMonth, maxYear);
    Date currDate;

    while (!in.eof())
    {
        while (!in.eof() && !isdigit(in.peek()))
            in.get();
        if (!in.eof())
        {
            less = false;
            if (in.peek() == '0')
                less = true;
            in >> currDate.day;
            if (less && currDate.day >= 10)
                continue;
            if (currDate.day < 1 || currDate.day >= maxDay)
                continue;
            if (in.get() != '.' || !isdigit(in.peek()))
                continue;
            else
            {
                less = false;
                if (in.peek() == '0')
                    less = true;
                in >> currDate.month;
                if (less && currDate.month >= 10)
                    continue;
                if (currDate.month < 1 || currDate.month >= maxMonth)
                    continue;
                if (in.get() != '.' || !isdigit(in.peek()))
                    continue;
                else
                {
                    less = false;
                    if (in.peek() == '0')
                        less = true;
                    in >> currDate.year;
                    if (less && currDate.year >= 1000)
                        continue;
                    if (isLess(currDate, minDate))
                        minDate = currDate;
                }
            }
        }
    }
    return minDate;
}

int main()
{
    ifstream in("input");
    if (!in)
    {
        cerr << "Error reading from file. There must be file \"input\"" << endl;
        return 1;
    }
    
    Date minDate = getMinDate(in);

    if (minDate.day == 32)
        clog << "There is no dates in the file" << endl;
    else
    {
        clog << "The lesser date is ";
        cout << minDate.day << '.' << minDate.month << '.' << minDate.year << endl;
    }
    in.close();
    return 0;
} 
