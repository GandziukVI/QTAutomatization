#ifndef AGU25XXEXTBOXDEFINITIONS_H
#define AGU25XXEXTBOXDEFINITIONS_H

#include "agu25xxextensionbox_global.h"

enum class AGU25XXEXTENSIONBOXSHARED_EXPORT FilterCutOffFrequencies : unsigned int
{
    Freq_0kHz = 0x00,
    Freq_10kHz = 0x01,
    Freq_20kHz = 0x02,
    Freq_30kHz = 0x03,
    Freq_40kHz = 0x04,
    Freq_50kHz = 0x05,
    Freq_60kHz = 0x06,
    Freq_70kHz = 0x07,
    Freq_80kHz = 0x08,
    Freq_90kHz = 0x09,
    Freq_100kHz = 0x0a,
    Freq_110kHz = 0x0b,
    Freq_120kHz = 0x0c,
    Freq_130kHz = 0x0d,
    Freq_140kHz = 0x0e,
    Freq_150kHz = 0x0f
};

enum class AGU25XXEXTENSIONBOXSHARED_EXPORT FilterGains : unsigned int {
    gain1 = 0x00,
    gain2 = 0x10,
    gain3 = 0x20,
    gain4 = 0x30,
    gain5 = 0x40,
    gain6 = 0x50,
    gain7 = 0x60,
    gain8 = 0x70,
    gain9 = 0x80,
    gain10 = 0x90,
    gain11 = 0xa0,
    gain12 = 0xb0,
    gain13 = 0xc0,
    gain14 = 0xd0,
    gain15 = 0xe0,
    gain16 = 0xf0
};

enum class AGU25XXEXTENSIONBOXSHARED_EXPORT PGAGains : unsigned int {
    gain1 = 0x00,
    gain10 = 0x01,
    gain100 = 0x02
};

enum class AGU25XXEXTENSIONBOXSHARED_EXPORT AInChannelModes : unsigned int {
    AC = 0,
    DC = 1
};

#endif // AGU25XXEXTBOXDEFINITIONS_H
