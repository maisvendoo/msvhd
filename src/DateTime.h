//
// Created by maisvendoo on 15.05.16.
//

#ifndef DATETIME_H
#define DATETIME_H

#include <stdint.h>
#include <time.h>

// Convert date and time to Unix data
time_t getUnixTime(uint32_t year,
                     uint32_t mounth,
                     uint32_t day,
                     uint32_t hour,
                     uint32_t min,
                     uint32_t sec);

#endif // DATETIME_H
