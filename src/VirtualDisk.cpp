//-----------------------------------------------------------------------------
// Created by maisvendoo on 14.05.16.
//-----------------------------------------------------------------------------
#include "VirtualDisk.h"

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
VirtualDisk::VirtualDisk()
{

}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
VirtualDisk::~VirtualDisk()
{

}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
bool VirtualDisk::process(cmd_line_t cmd_line, string &msg)
{
    if (cmd_line.command == CMD_INFO)
    {
        if (!getInfo(cmd_line.input_file, msg))
            return false;
    }
    else if (cmd_line.command == CMD_CREATE)
    {

    }
    else if (cmd_line.command == CMD_CONVERT)
    {

    }
    else
    {
        msg = "Command is't found";
        return false;
    }

    return true;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
bool VirtualDisk::getInfo(string path, string &msg)
{
    ifstream disk(path.c_str(), ifstream::binary);

    if (!disk.is_open())
    {
        msg = "ERROR: file " + path + " is't found";
        return false;
    }

    // Get file size
    disk.seekg(0, disk.end);
    uint64_t size = disk.tellg();
    uint64_t footer_size = sizeof(vhd_footer_t);

    // Read foother form file
    disk.seekg(0, disk.beg);
    disk.seekg(size - footer_size);

    vhd_footer_t *vhd_footer = new vhd_footer_t;

    disk.read((char*) vhd_footer, footer_size);

    // Convert numerical fields in litte-endian
    setLitteEndian(vhd_footer);

    disk.close();

    printVhdFooterInfo(vhd_footer);

    return true;
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void VirtualDisk::setLitteEndian(vhd_footer_t *vhd_footer)
{
    vhd_footer->features = be32toh(vhd_footer->features);
    vhd_footer->file_format_version = be32toh(vhd_footer->file_format_version);
    vhd_footer->data_offset = be64toh(vhd_footer->data_offset);
    vhd_footer->time_stamp = be32toh(vhd_footer->time_stamp);
    vhd_footer->creator_version = be32toh(vhd_footer->creator_version);
    vhd_footer->original_size = be64toh(vhd_footer->original_size);
    vhd_footer->current_size = be64toh(vhd_footer->current_size);
    vhd_footer->disk_geometry.cylinder = be16toh(vhd_footer->disk_geometry.cylinder);
    vhd_footer->disk_type = be32toh(vhd_footer->disk_type);
    vhd_footer->checksum = be32toh(vhd_footer->checksum);

    vhd_footer->unique_id.part4 = be16toh(vhd_footer->unique_id.part4);
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void VirtualDisk::printVhdFooterInfo(vhd_footer_t *vhd_footer)
{
    printf("Virtual disk (VHD) info:\n\n");
    printf("Cookies:\t\t%s\n", vhd_footer->cookie);
    printf("Features:\t\t0x%x\n", vhd_footer->features);
    printf("File format version:\t0x%x\n", vhd_footer->file_format_version);

    printf("Data offset:\t\t0x%x%x\n", (uint32_t ) (vhd_footer->data_offset >> 32),
           (uint32_t) vhd_footer->data_offset);

    printf("Creator application:\t%s\n", vhd_footer->creator_application);
    printf("Creator version:\t0x%x\n", vhd_footer->creator_version);
    printf("Creator Host OS:\t%s\n", vhd_footer->creator_host_os);
    printf("Original size:\t\t%lld\n", (long long int) vhd_footer->original_size);
    printf("Current size:\t\t%lld\n", (long long int) vhd_footer->current_size);

    printf("Disk geometry (CHS):\t%i/%i/%i\n",
           vhd_footer->disk_geometry.cylinder,
           vhd_footer->disk_geometry.heads,
           vhd_footer->disk_geometry.sectors_per_track);

    printf("Checksum:\t\t0x%x\n", vhd_footer->checksum);

    printf("UUID:\t\t\t");

    printf("%x-%x-%x-%x-",
           vhd_footer->unique_id.part1,
           vhd_footer->unique_id.part2,
           vhd_footer->unique_id.part3,
           vhd_footer->unique_id.part4);

    for (uint8_t i = 0; i < sizeof(vhd_footer->unique_id.part5); i++)
        printf("%x", vhd_footer->unique_id.part5[i]);

    printf("\n");

    printf("Saved state:\t\t%i\n", vhd_footer->saved_state);
}