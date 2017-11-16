#include "AgU25xxSENSeSubSys.h"

AgU25xxSENSeSubSys::AgU25xxSENSeSubSys()
    : IAg25xxSubsystem("SENS")
{
    VOLTageSubsystem = getSubSubSystem("VOLT");
    COUNterSubsystem = getSubSubSystem("COUN");
}
