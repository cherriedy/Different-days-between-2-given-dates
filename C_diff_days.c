#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#pragma pack(1)

typedef struct
{
    int day, month, year;
} date;

int diffdays(date start, date end)
{
    time_t now = time(0);
    struct tm *tm = localtime(&now);
    float total_diffYears = 0, total_diffMonths = 0;
    unsigned int currentMonth = 1 + tm->tm_mon, currentYear = 1900 + tm->tm_year;
    if (currentMonth != start.month)
    {
        int t_year = end.year - 1;
        total_diffYears = (t_year - start.year) * 365.25f;
        int MonthsOf_PreYear = 12 - start.month;
        int MonthsOf_CurrYear = end.month;
        total_diffMonths = (MonthsOf_PreYear + MonthsOf_CurrYear) * (365.25f / 12);
    }
    else
    {
        total_diffMonths = (end.month - start.month) * (365.25f / 12);
        total_diffYears = (end.year - start.year) * 365.25f;
    }
    return round(total_diffMonths + total_diffYears) - abs(end.day - start.day); 
}