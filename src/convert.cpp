//-----------------------------------------------------------------------------
//
//      Data conversion module
//      Created by maisvendoo on 26.03.16.
//
//-----------------------------------------------------------------------------
#include "convert.h"

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
bool TextToDouble(string text, double &value, string &msg)
{
    try
    {
        value = stod(text);
    }
    catch (exception &e)
    {
        msg = "EXEPTION: input data " + text + " is not numerical ";
        msg += e.what();
        return false;
    }

    return true;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
bool TextToInt(string text, int &value, string &msg)
{
    try
    {
        value = stoi(text);
    }
    catch (exception &e)
    {
        msg = "EXEPTION: input data " + text + " is not numerical ";
        msg += e.what();
        return false;
    }

    return true;
}
