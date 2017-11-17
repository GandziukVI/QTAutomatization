#ifndef AGU25XXAPPLY_H
#define AGU25XXAPPLY_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "IAgU25xxSubsystemExtensions.h"


class AGILENTU25XXSHARED_EXPORT AgU25xxAPPLySubSys : public IAgU25xxSubsystem, public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxAPPLySubSys();

    QString cmdGetAOParams(AgU25xxEnumAOChannels channel);
    QString cmdGetAOParams(QVector<AgU25xxEnumAOChannels> channels);
    QString cmdApplySineWave(double amplitude, double offset, AgU25xxEnumAOChannels channel);
    QString cmdApplySineWave(double amplitude, double offset, QVector<AgU25xxEnumAOChannels> channels);
    QString cmdApplySquareWave(double amplitude, double offset, AgU25xxEnumAOChannels channel);
    QString cmdApplySquareWave(double amplitude, double offset, QVector<AgU25xxEnumAOChannels> channels);
    QString cmdApplySawToothWave(double amplitude, double offset, AgU25xxEnumAOChannels channel);
    QString cmdApplySawToothWave(double amplitude, double offset, QVector<AgU25xxEnumAOChannels> channels);
    QString cmdApplyTriangleWave(double amplitude, double offset, AgU25xxEnumAOChannels channel);
    QString cmdApplyTriangleWave(double amplitude, double offset, QVector<AgU25xxEnumAOChannels> channels);
    QString cmdApplyNoise(double amplitude, double offset, AgU25xxEnumAOChannels channel);
    QString cmdApplyNoise(double amplitude, double offset, QVector<AgU25xxEnumAOChannels> channels);
    QString cmdApplyUser(AgU25xxEnumAOChannels channel);
    QString cmdApplyUser(QVector<AgU25xxEnumAOChannels> channels);
};

#endif // AGU25XXAPPLY_H
