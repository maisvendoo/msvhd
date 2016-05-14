//-----------------------------------------------------------------------------
//
//      Created by maisvendoo on 14.05.16.
//
//-----------------------------------------------------------------------------
#ifndef CMDLINE_H
#define CMDLINE_H

#include <string>

using namespace std;

const string CMD_CREATE = "create";
const string CMD_INFO = "info";
const string CMD_CONVERT = "convert";

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
struct cmd_line_t
{
    string      command;
    string      input_file;
    string      output_file;
    string      disk_type;
    uint64_t    disk_size;
    bool        help;
};

#endif //CMDLINE_H
