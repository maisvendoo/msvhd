//-----------------------------------------------------------------------------
//
//      Comand line parser
//      Created by maisvendoo on 29.03.16.
//
//-----------------------------------------------------------------------------
#ifndef CMDLINEPARSER_H
#define CMDLINEPARSER_H

#include <vector>

#include "CmdLine.h"

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
class CmdLineParser
{
public:

    CmdLineParser();
    ~CmdLineParser(){ }

    bool parse(int argc, char* argv[], cmd_line_t &cmd_line, string &msg);

private:

    vector<string> help;

    // Display usage help by -h or --help command line key
    void displayUsage();
    // Load help
    void loadReadMe();
};

#endif //CMDLINEPARSER_H
