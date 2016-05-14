//
// Created by maisvendoo on 15.05.16.
//
#include "DateTime.h"

time_t getUnixTime(uint32_t year,
                     uint32_t mounth,
                     uint32_t day,
                     uint32_t hour,
                     uint32_t min,
                     uint32_t sec)
{
    time_t unix_time = 0;

    struct tm date = {0};

    date.tm_year = year - 1900;
    date.tm_mon = mounth - 1;
    date.tm_mday = day;
    date.tm_hour = hour;
    date.tm_min = min;
    date.tm_sec = sec;

    unix_time = mktime(&date);

    return unix_time;
}
