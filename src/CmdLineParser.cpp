//-----------------------------------------------------------------------------
//
//      Comand line parser
//      Created by maisvendoo on 29.03.16.
//
//-----------------------------------------------------------------------------
#include <getopt.h>
#include <fstream>

#include "CmdLineParser.h"
#include "convert.h"
#include "msg.h"

static const char *optString = "t:i:o:ah?";

static const struct option longOpts[] = {
        {"help", no_argument, NULL, 'h'},
        {"type", required_argument, NULL, 't'},
        {"input-file", required_argument, NULL, 'i'},
        {"output-file", required_argument, NULL, 'o'},
        {"append-footer", no_argument, NULL, 'a'},
        {NULL, no_argument, NULL, 0}
};

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
CmdLineParser::CmdLineParser()
{
    //loadReadMe();
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
bool CmdLineParser::parse(int argc,
                          char **argv,
                          cmd_line_t &cmd_line,
                          string &msg)
{
    if (argc == 1)
        return true;

    if (argv[1][0] != '-')
        cmd_line.command = argv[1];
    else
        cmd_line.command = "";

    int longIndex = 0;
    int opt = getopt_long(argc, argv, optString, longOpts, &longIndex);

    while (opt != -1) {

        switch (opt) {

            case 't':
            {
                cmd_line.disk_type = optarg;

                break;
            }

            case 'i':
            {
                cmd_line.input_file = optarg;

                break;
            }

            case 'o':
            {
                cmd_line.output_file = optarg;

                break;
            }

            case 'a':
            {
                cmd_line.append_footer = true;

                break;
            }

            case 'h':
            case '?':
            {
                displayUsage();
                cmd_line.help = true;
                break;
            }

            default:
            {
                break;
            }
        }

        opt = getopt_long(argc, argv, optString, longOpts, &longIndex);
    }

    return true;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void CmdLineParser::displayUsage()
{
    for (unsigned long i = 0; i < help.size(); i++)
    {
        print_msg(help[i]);
    }
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void CmdLineParser::loadReadMe()
{
    ifstream fin("../README");

    if (!fin.is_open())
    {
        string msg = "WARNING: README file is not found. Help is not available";
        print_msg(msg);
        return;
    }

    while (!fin.eof())
    {
        string line;
        getline(fin, line);
        help.push_back(line);
    }

    fin.close();
}


