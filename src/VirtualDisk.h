//-----------------------------------------------------------------------------
//
// Created by maisvendoo on 14.05.16.
//
//-----------------------------------------------------------------------------
#ifndef VIRTUALDISK_H
#define VIRTUALDISK_H

#include "vhd.h"
#include "CmdLine.h"
#include "DateTime.h"

#include <fstream>

using namespace std;

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
class VirtualDisk
{
public:

    VirtualDisk();
    ~VirtualDisk();

    bool process(cmd_line_t cmd_line, string &msg);

private:

    bool getInfo(string path, string &msg);
    bool convert(string path,
                 string dest_path,
                 bool append_footer,
                 string &msg);

    void setLitteEndian(vhd_footer_t* vhd_footer);

    void printVhdFooterInfo(vhd_footer_t *vhd_footer);

    void getDiskGeometry(uint64_t size, vhd_disk_geometry_t &disk_geometry);
};

#endif //VIRTUALDISK_H
