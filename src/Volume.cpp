#include <Volume.h>
#include <CirrusValidation.h>
#include <openvdb/openvdb.h>

Volume::Volume(const char *path)
{
    CirrusValidation::logi("Volume: Ctor called.");
    openvdb::initialize();
}