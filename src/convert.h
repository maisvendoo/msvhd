//-----------------------------------------------------------------------------
//
//      Data conversion module
//      Created by maisvendoo on 26.03.16.
//
//-----------------------------------------------------------------------------
#ifndef CONVERT_H
#define CONVERT_H

#include <string>

using namespace std;

// Convert string to double with data correction check
bool TextToDouble(string text, double &value, string &msg);

// Convert string to int with data correction check
bool TextToInt(string text, int &value, string &msg);

#endif //CONVERT_H
