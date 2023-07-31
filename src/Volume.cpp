#include <Volume.h>

Volume::Volume(const char *path)
{
    openvdb::initialize();
    openvdb::io::File file(path);
}