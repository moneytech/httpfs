#include "../phpfs.h"

int phpfs_create( const char *path ,
                  mode_t mode ,
                  struct fuse_file_info *fi )
{
    struct raw_data raw_data = { 0 };
    struct
    {
        uint32_t mode;
    }
    header = { htonl( mode ) };

    PHPFS_DO_REQUEST( PHPFS_OPCODE_create )
    {
        PHPFS_CHECK_RESPONSE_STATUS;
        PHPFS_CLEANUP;
        return 0;
    }
}