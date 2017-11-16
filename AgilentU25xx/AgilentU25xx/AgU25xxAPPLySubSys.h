#ifndef AGU25XXAPPLY_H
#define AGU25XXAPPLY_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "AgU25xxDefinitions.h"


class AGILENTU25XXSHARED_EXPORT AgU25xxAPPLySubSys : public IAg25xxSubsystem
{
public:
    AgU25xxAPPLySubSys();

    QString cmdGetAOParams(AgU25xxOUTPut::AOChannels channel);
    QString cmdGetAOParams(QVector<AgU25xxOUTPut::AOChannels> channels);
    QString cmdApplySineWave(double amplitude, double offset, AgU25xxOUTPut::AOChannels channel);
    QString cmdApplySineWave(double amplitude, double offset, QVector<AgU25xxOUTPut::AOChannels> channels);
    QString cmdApplySquareWave(double amplitude, double offset, AgU25xxOUTPut::AOChannels channel);
    QString cmdApplySquareWave(double amplitude, double offset, QVector<AgU25xxOUTPut::AOChannels> channels);
    QString cmdApplySawToothWave(double amplitude, double offset, AgU25xxOUTPut::AOChannels channel);
    QString cmdApplySawToothWave(double amplitude, double offset, QVector<AgU25xxOUTPut::AOChannels> channels);
    QString cmdApplyTriangleWave(double amplitude, double offset, AgU25xxOUTPut::AOChannels channel);
    QString cmdApplyTriangleWave(double amplitude, double offset, QVector<AgU25xxOUTPut::AOChannels> channels);
    QString cmdApplyNoise(double amplitude, double offset, AgU25xxOUTPut::AOChannels channel);
    QString cmdApplyNoise(double amplitude, double offset, QVector<AgU25xxOUTPut::AOChannels> channels);
    QString cmdApplyUser(AgU25xxOUTPut::AOChannels channel);
    QString cmdApplyUser(QVector<AgU25xxOUTPut::AOChannels> channels);
};

#endif // AGU25XXAPPLY_H
