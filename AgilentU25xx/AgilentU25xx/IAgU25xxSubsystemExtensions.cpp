#include "IAgU25xxSubsystemExtensions.h"
#include "AgU25xxException.h"

#include <QObject>
#include <QRegularExpression>

IAgU25xxSubsystemExtensions::IAgU25xxSubsystemExtensions()
{
    regExDouble = new QRegularExpression(QString("[+\\-]?(?:0|[1-9]\\d*)(?:\\.\\d*)?(?:[eE][+\\-]?\\d+)?"), QRegularExpression::MultilineOption);
}

IAgU25xxSubsystemExtensions::~IAgU25xxSubsystemExtensions()
{
    delete regExDouble;
}

unsigned int IAgU25xxSubsystemExtensions::extGetAOChannel(AgU25xxEnumAOChannels channel) const
{
    switch (channel) {

    case AgU25xxEnumAOChannels::AOut01:
        return 201;
    case AgU25xxEnumAOChannels::AOut02:
        return 202;
    }

    return 201;
}

QVector<unsigned int> IAgU25xxSubsystemExtensions::extGetAOChannels(QVector<AgU25xxEnumAOChannels> channels) const
{
    QVector<unsigned int> res;
    QVector<AgU25xxEnumAOChannels>::const_iterator iter = channels.cbegin();

    for (; iter != channels.cend();) {
        res.push_back(extGetAOChannel(*iter));
        ++iter;
    }

    return res;
}

const char* IAgU25xxSubsystemExtensions::extGetAOChannelPolarityStr(AgU25xxEnumAOChannelPolarities polarity) const
{
    if (polarity == AgU25xxEnumAOChannelPolarities::BIP)
        return "BIP";
    else if (polarity == AgU25xxEnumAOChannelPolarities::UNIP)
        return "UNIP";
    else
        throw AgU25xxException(QString("Unable to convert polarity."));
}

AgU25xxEnumAOChannelPolarities IAgU25xxSubsystemExtensions::extGetAOChannelPolarityEnum(QString &polarityStr)
{
    if (areStringsEqual("BIP", polarityStr))
        return AgU25xxEnumAOChannelPolarities::BIP;
    else if (areStringsEqual("UNIP", polarityStr))
        return AgU25xxEnumAOChannelPolarities::UNIP;
    else
        throw AgU25xxException(QString("Unable to convert polarity."));
}

unsigned int IAgU25xxSubsystemExtensions::extGetDigChannel(AgU25xxEnumDigitalChannels channel) const
{
    switch (channel) {

    case AgU25xxEnumDigitalChannels::DIG01:
        return 501;
    case AgU25xxEnumDigitalChannels::DIG02:
        return 502;
    case AgU25xxEnumDigitalChannels::DIG03:
        return 503;
    case AgU25xxEnumDigitalChannels::DIG04:
        return 504;
    }

    return 501;
}

QVector<unsigned int> IAgU25xxSubsystemExtensions::extGetDigChannels(QVector<AgU25xxEnumDigitalChannels> channels) const
{
    QVector<unsigned int> res;
    QVector<AgU25xxEnumDigitalChannels>::const_iterator iter = channels.cbegin();

    for (; iter != channels.cend(); ) {
        res.push_back(extGetDigChannel(*iter));
        ++iter;
    }

    return res;
}

const char* IAgU25xxSubsystemExtensions::extGetDigDirection(AgU25xxEnumDigitalDirection direction) const
{
    switch (direction) {

    case AgU25xxEnumDigitalDirection::INPut:
        return "INP";
    case AgU25xxEnumDigitalDirection::OUTPut:
        return "OUTP";
    }

    return "INP";
}

const char* IAgU25xxSubsystemExtensions::extGetTimeBaseSrcMode(AgU25xxEnumTimeSrcModes timeBaseMode) const
{
    switch (timeBaseMode) {

    case AgU25xxEnumTimeSrcModes::INTernal:
        return "INT";
    case AgU25xxEnumTimeSrcModes::EXTernal:
        return "EXT";
    case AgU25xxEnumTimeSrcModes::CCG:
        return "CCG";
    }

    return "INT";
}

const char* IAgU25xxSubsystemExtensions::extGetSSIMode(AgU25xxEnumSSIModes ssiMode) const
{
    switch (ssiMode) {

    case AgU25xxEnumSSIModes::None:
        return "NONE";
    case AgU25xxEnumSSIModes::Master:
        return "MAST";
    case AgU25xxEnumSSIModes::Slave:
        return "SLAV";
    }

    return "NONE";
}

unsigned int IAgU25xxSubsystemExtensions::extGetCounterChannel(AgU25xxEnumCounterChannels channel) const
{
    switch (channel) {

    case AgU25xxEnumCounterChannels::COUNT01:
            return 301;
    case AgU25xxEnumCounterChannels::COUNT02:
            return 302;
    }

    return 301;
}

QVector<unsigned int> IAgU25xxSubsystemExtensions::extGetCounterChannels(QVector<AgU25xxEnumCounterChannels> channels) const
{
    QVector<unsigned int> res;
    QVector<AgU25xxEnumCounterChannels>::const_iterator iter = channels.cbegin();

    for (; iter != channels.cend(); ) {
        res.push_back(extGetCounterChannel(*iter));
        ++iter;
    }

    return res;
}

unsigned int IAgU25xxSubsystemExtensions::extGetOutputState(AgU25xxEnumOutputState outpState) const
{
    switch (outpState) {

    case AgU25xxEnumOutputState::ON:
        return 1;
    case AgU25xxEnumOutputState::OFF:
        return 0;
    }

    return 0;
}

const char* IAgU25xxSubsystemExtensions::extGetInputTriggerSource(AgU25xxEnumTriggerSources triggerSource) const
{
    switch (triggerSource) {

    case AgU25xxEnumTriggerSources::NONE:
        return "NONE";
    case AgU25xxEnumTriggerSources::EXTD:
        return "EXTD";
    case AgU25xxEnumTriggerSources::EXTA:
        return "EXTA";
    case AgU25xxEnumTriggerSources::STRG:
        return "STRG";
    }

    return "NONE";
}

const char* IAgU25xxSubsystemExtensions::extGetOutputTriggerSource(AgU25xxEnumTriggerSources triggerSource) const
{
    switch (triggerSource) {

    case AgU25xxEnumTriggerSources::NONE:
        return "NONE";
    case AgU25xxEnumTriggerSources::EXTD:
        return "EXTD";
    case AgU25xxEnumTriggerSources::EXTA:
        return "EXTA";
    case AgU25xxEnumTriggerSources::STRG:
        return "STRG";
    }

    return "NONE";
}

const char* IAgU25xxSubsystemExtensions::extGetInputTriggerType(AgU25xxEnumTriggerTypes triggerType) const
{
    switch (triggerType) {

    case AgU25xxEnumTriggerTypes::POST:
        return "POST";
    case AgU25xxEnumTriggerTypes::PRE:
        return "PRE";
    case AgU25xxEnumTriggerTypes::MID:
        return "MID";
    case AgU25xxEnumTriggerTypes::DEL:
        return "DEL";
    }

    return "POST";
}

const char* IAgU25xxSubsystemExtensions::extGetOutputTriggerType(AgU25xxEnumTriggerTypes triggerType) const
{
    switch (triggerType) {

    case AgU25xxEnumTriggerTypes::POST:
        return "POST";
    case AgU25xxEnumTriggerTypes::DEL:
        return "DEL";
    }

    return "POST";
}

const char* IAgU25xxSubsystemExtensions::extGetInputATRiGgerSource(AgU25xxEnumATRiGgerSources triggerSource) const
{
    if (triggerSource == AgU25xxEnumATRiGgerSources::EXTAP)
        return "EXTAP";
    else
        return "EXTAP";
}

const char* IAgU25xxSubsystemExtensions::extGetOutputATRiGgerSource(AgU25xxEnumATRiGgerSources triggerSource) const
{
    switch (triggerSource) {

    case AgU25xxEnumATRiGgerSources::EXTAP:
        return "EXTAP";
    case AgU25xxEnumATRiGgerSources::CH101:
        return "CH101";
    case AgU25xxEnumATRiGgerSources::CH102:
        return "CH102";
    case AgU25xxEnumATRiGgerSources::CH103:
        return "CH103";
    case AgU25xxEnumATRiGgerSources::CH104:
        return "CH104";
    }

    return "EXTAP";
}

const char *IAgU25xxSubsystemExtensions::extGetInputATRiGgerCondition(AgU25xxEnumATRiGgerConditions triggerCondition) const
{
    switch (triggerCondition) {

    case AgU25xxEnumATRiGgerConditions::AHIG:
        return "AHIG";
    case AgU25xxEnumATRiGgerConditions::BLOW:
        return "BLOW";
    case AgU25xxEnumATRiGgerConditions::WIND:
        return "WIND";
    }

    return "BLOW";
}

const char* IAgU25xxSubsystemExtensions::extGetOutputATRiGgerCondition(AgU25xxEnumATRiGgerConditions triggerCondition) const
{
    switch (triggerCondition) {

    case AgU25xxEnumATRiGgerConditions::AHIG:
        return "AHIG";
    case AgU25xxEnumATRiGgerConditions::BLOW:
        return "BLOW";
    case AgU25xxEnumATRiGgerConditions::WIND:
        return "WIND";
    }

    return "BLOW";
}

const char* IAgU25xxSubsystemExtensions::extGetInputDTRiGgerPolarity(AgU25xxEnumDTRiGgerPolarities triggerPolarity) const
{
    switch (triggerPolarity) {

    case AgU25xxEnumDTRiGgerPolarities::POS:
        return "POS";
    case AgU25xxEnumDTRiGgerPolarities::NEG:
        return "NEG";
    }

    return "POS";
}

const char* IAgU25xxSubsystemExtensions::extGetOutputDTRiGgerPolarity(AgU25xxEnumDTRiGgerPolarities triggerPolarity) const
{
    switch (triggerPolarity) {

    case AgU25xxEnumDTRiGgerPolarities::POS:
        return "POS";
    case AgU25xxEnumDTRiGgerPolarities::NEG:
        return "NEG";
    }

    return "POS";
}

unsigned int IAgU25xxSubsystemExtensions::extGetAIChannel(AgU25xxEnumAIChannels channel) const
{
    switch (channel) {

    case AgU25xxEnumAIChannels::AIn01:
        return 101;
    case AgU25xxEnumAIChannels::AIn02:
        return 102;
    case AgU25xxEnumAIChannels::AIn03:
        return 103;
    case AgU25xxEnumAIChannels::AIn04:
        return 104;
    }

    return 101;
}

QVector<unsigned int> IAgU25xxSubsystemExtensions::extGetAIChannels(QVector<AgU25xxEnumAIChannels> channels) const
{
    QVector<unsigned int> res;
    QVector<AgU25xxEnumAIChannels>::const_iterator iter = channels.cbegin();

    for (; iter != channels.cend(); ) {
        res.push_back(extGetAIChannel(*iter));
        ++iter;
    }

    return res;
}

const char* IAgU25xxSubsystemExtensions::extGetAIChannelRangeStr(AgU25xxEnumAIChannelRanges range) const
{
    if (range == AgU25xxEnumAIChannelRanges::AUTO)
        return "AUTO";
    else if(range == AgU25xxEnumAIChannelRanges::Range10V)
        return "10.0";
    else if(range == AgU25xxEnumAIChannelRanges::Range5V)
        return "5.0";
    else if(range == AgU25xxEnumAIChannelRanges::Range2_5V)
        return "2.5";
    else if(range == AgU25xxEnumAIChannelRanges::Range1_25V)
        return "1.25";
    else
        throw AgU25xxException(QString("Unable to convert range."));
}

AgU25xxEnumAIChannelRanges IAgU25xxSubsystemExtensions::extGetAIChannelRangeEnum(QString &rangeStr)
{
    if (areStringsEqual("AUTO", rangeStr))
        return AgU25xxEnumAIChannelRanges::AUTO;
    else if (areStringsEqual("10.0", rangeStr))
        return AgU25xxEnumAIChannelRanges::Range10V;
    else if (areStringsEqual("5.0", rangeStr))
        return AgU25xxEnumAIChannelRanges::Range5V;
    else if (areStringsEqual("2.5", rangeStr))
        return AgU25xxEnumAIChannelRanges::Range2_5V;
    else if (areStringsEqual("1.25", rangeStr))
        return AgU25xxEnumAIChannelRanges::Range1_25V;
    else
        throw AgU25xxException(QString("Unable to convert range."));
}

const char* IAgU25xxSubsystemExtensions::extGetAIChannelPolarityStr(AgU25xxEnumAIChannelPolaities polarity) const
{
    if (polarity == AgU25xxEnumAIChannelPolaities::BIP)
        return "BIP";
    else if (polarity == AgU25xxEnumAIChannelPolaities::UNIP)
        return "UNIP";
    else
        throw AgU25xxException(QString("Unable to convert polarity."));
}

AgU25xxEnumAIChannelPolaities IAgU25xxSubsystemExtensions::extGetAIChannelPolarityEnum(QString& polarityStr)
{
    if (areStringsEqual("BIP", polarityStr))
        return AgU25xxEnumAIChannelPolaities::BIP;
    else if (areStringsEqual("UNIP", polarityStr))
        return AgU25xxEnumAIChannelPolaities::UNIP;
    else
        throw AgU25xxException(QString("Unable to convert polarity."));
}

const char* IAgU25xxSubsystemExtensions::extGetAOChannelRefereceSource(AgU25xxEnumAOChannelRSouRCes rSource) const
{
    switch (rSource) {

    case AgU25xxEnumAOChannelRSouRCes::INT:
        return "INT";
    case AgU25xxEnumAOChannelRSouRCes::EXT:
        return "EXT";
    }

    return "INT";
}

const char* IAgU25xxSubsystemExtensions::extGetCOUNterFunc(AgU25xxEnumCounterFunctions function) const
{
    switch (function) {

    case AgU25xxEnumCounterFunctions::FREQ:
        return "FREQ";
    case AgU25xxEnumCounterFunctions::PER:
        return "PER";
    case AgU25xxEnumCounterFunctions::PWID:
        return "PWID";
    case AgU25xxEnumCounterFunctions::TOT:
        return "TOT";
    }

    return "FREQ";
}

const char* IAgU25xxSubsystemExtensions::extGetCOUNterGateSource(AgU25xxEnumCounterGateSources counterGateSrc) const
{
    switch (counterGateSrc) {

    case AgU25xxEnumCounterGateSources::INT:
        return "INT";
    case AgU25xxEnumCounterGateSources::EXT:
        return "EXT";
    }

    return "INT";
}

const char* IAgU25xxSubsystemExtensions::extGetCOUNterGatePolarity(AgU25xxEnumCounterGatePolarities counterPolarity) const
{
    switch (counterPolarity) {

    case AgU25xxEnumCounterGatePolarities::AHI:
        return "AHI";
    case AgU25xxEnumCounterGatePolarities::ALO:
        return "ALO";
    }

    return "AHI";
}

const char* IAgU25xxSubsystemExtensions::extGetCOUNterGateState(AgU25xxEnumCounterGateStates counterControl) const
{
    switch (counterControl) {

    case AgU25xxEnumCounterGateStates::DIS:
        return "DIS";
    case AgU25xxEnumCounterGateStates::ENAB:
        return "ENAB";
    }

    return "DIS";
}

const char* IAgU25xxSubsystemExtensions::extGetCOUNterClockSource(AgU25xxEnumCounterClockSources counterClockSrc) const
{
    switch (counterClockSrc) {

    case AgU25xxEnumCounterClockSources::INT:
        return "INT";
    case AgU25xxEnumCounterClockSources::EXT:
        return "EXT";
    }

    return "INT";
}

const char* IAgU25xxSubsystemExtensions::extGetCOUNterClockPolarity(AgU25xxCounterEnumClockPolarities counterClkPolarity) const
{
    switch (counterClkPolarity) {

    case AgU25xxCounterEnumClockPolarities::AHI:
        return "AHI";
    case AgU25xxCounterEnumClockPolarities::ALO:
        return "ALO";
    }

    return "AHI";
}

const char* IAgU25xxSubsystemExtensions::extGetCOUNterTotalizeCountingSrc(AgU25xxEnumCounterTotalizeCountingSrc counterTotalizeSrc) const
{
    switch (counterTotalizeSrc) {

    case AgU25xxEnumCounterTotalizeCountingSrc::INT:
        return "INT";
    case AgU25xxEnumCounterTotalizeCountingSrc::EXT:
        return "EXT";
    }

    return "INT";
}

const char* IAgU25xxSubsystemExtensions::extGetCOUNterTotalizeCountingDir(AgU25xxEnumCounterTotalizeCountingDir counterTotalizeDir) const
{
    switch (counterTotalizeDir) {

    case AgU25xxEnumCounterTotalizeCountingDir::UP:
        return "UP";
    case AgU25xxEnumCounterTotalizeCountingDir::DOWN:
        return "DOWN";
    }

    return "UP";
}

int IAgU25xxSubsystemExtensions::extConvertResponseToIntValue(QString strResponse)
{
//    int  intResponse = 0;
//    bool conversionIsOk;

//    QRegularExpressionMatchIterator responseMatch = regExDouble->globalMatch(strResponse);
//    if(responseMatch.hasNext())
//        intResponse = responseMatch.next().captured(0).toInt(&conversionIsOk);
//    else
//        throw AgU25xxException(QString("Unable to read instrument response."));

//    if(conversionIsOk)
//        return intResponse;
//    else
//        throw AgU25xxException(QString("Unable to convert read value."));
    return strResponse.toInt();
}

double IAgU25xxSubsystemExtensions::extConvertResponseToRealValue(QString strResponse)
{
//    double doubleResponse;
//    bool   conversionIsOk;

//    QRegularExpressionMatch responseMatch = regExDouble->match(strResponse);
//    if(responseMatch.hasMatch())
//        doubleResponse = responseMatch.captured(0).toDouble(&conversionIsOk);
//    else
//        throw AgU25xxException(QString("Unable to read instrument response."));

//    if(conversionIsOk)
//        return doubleResponse;
//    else
//        throw AgU25xxException(QString("Unable to convert read value."));
    return strResponse.toDouble();
}

bool IAgU25xxSubsystemExtensions::areStringsEqual(const char *str1, QString& str2)
{
    QRegularExpression termCharsExp("[\r\n\f]");

    QString toComp1 = QString(str1).remove(termCharsExp);
    QString toComp2 = QString(str2).remove(termCharsExp);

    return toComp1 == toComp2;
}
