//-----------------------------------------------------------------------------
//
//      VHD data strucrures
//
//-----------------------------------------------------------------------------
#ifndef VHD_H
#define VHD_H

#include <stdint.h>
#include <string>

using namespace std;

const string VHD_COOKIE = "conectix";
const string VHD_CREATOR_APP = "win ";
const string VHD_CREATOR_HOST_OS = "Wi2k";

const uint32_t VHD_SECTOR_SIZE = 512;
const uint8_t VHD_EMPTY_SECTOR[VHD_SECTOR_SIZE] = {0};

const string VHD_EXP = ".vhd";

#pragma pack(push, 1)

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
struct vhd_disk_geometry_t
{
    uint16_t    cylinder;
    uint8_t     heads;
    uint8_t     sectors_per_track;
};

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------

struct vhd_uuid_t
{
    uint32_t    part1;
    uint16_t    part2;
    uint16_t    part3;
    uint16_t    part4;
    uint8_t     part5[6];
};

//-----------------------------------------------------------------------------
//      VHD foother's data
//-----------------------------------------------------------------------------
struct vhd_footer_t
{
    char                cookie[8];
    uint32_t            features;
    uint32_t            file_format_version;
    uint64_t            data_offset;
    uint32_t            time_stamp;
    char                creator_application[4];
    uint32_t            creator_version;
    char                creator_host_os[4];
    uint64_t            original_size;
    uint64_t            current_size;
    vhd_disk_geometry_t disk_geometry;
    uint32_t            disk_type;
    uint32_t            checksum;
    vhd_uuid_t          unique_id;
    uint8_t             saved_state;
    uint8_t             reserved[427];
};

#pragma pack(pop)

#endif // VHD_H
