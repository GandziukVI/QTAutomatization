#include "IKeithley4200Page.h"

#include <memory>
#include <string>
#include <sstream>

const char* IKeithley4200Page::buildCommand(const char* command) const
{
    std::stringstream commandBuilder;

    commandBuilder << pageIdentifier << "\n" << commandIdentifier << ", " << command << '\n';

    return commandBuilder.str().c_str();
}

void IKeithley4200Page::extCopyString(char* dest, const char* src) const
{
    std::string srcStr(src);
    std::size_t len = srcStr.copy(dest, srcStr.length());
    dest[len] = '\0';
}

int IKeithley4200Page::getSMUSourceMode(SMUSourceMode sourceMode) const
{
    switch(sourceMode) {

    case SMUSourceMode::Voltage:
        return 1;
    case SMUSourceMode::Current:
        return 2;
    case SMUSourceMode::Common:
        return 3;
    case SMUSourceMode::ModeNotSet:
        return -1;
    }

    return 1;
}

int IKeithley4200Page::getSMUSourceFunction(SMUSourceFunction sourceFunction) const
{
    switch (sourceFunction) {

    case SMUSourceFunction::VAR1:
        return 1;
    case SMUSourceFunction::VAR2:
        return 2;
    case SMUSourceFunction::Constant:
        return 3;
    case SMUSourceFunction::VAR1Alternative:
        return 4;
    }

    return 3;
}
