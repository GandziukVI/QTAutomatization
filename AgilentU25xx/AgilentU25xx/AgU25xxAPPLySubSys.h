#ifndef AGU25XXAPPLY_H
#define AGU25XXAPPLY_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "IAgU25xxSubsystemExtensions.h"


class AGILENTU25XXSHARED_EXPORT AgU25xxAPPLySubSys : public IAgU25xxSubsystem, public IAgU25xxSubsystemExtensions
{
public:
    AgU25xxAPPLySubSys();

    QString cmdGetAOParams(AgU25xxAOChannels channel);
    QString cmdGetAOParams(QVector<AgU25xxAOChannels> channels);
    QString cmdApplySineWave(double amplitude, double offset, AgU25xxAOChannels channel);
    QString cmdApplySineWave(double amplitude, double offset, QVector<AgU25xxAOChannels> channels);
    QString cmdApplySquareWave(double amplitude, double offset, AgU25xxAOChannels channel);
    QString cmdApplySquareWave(double amplitude, double offset, QVector<AgU25xxAOChannels> channels);
    QString cmdApplySawToothWave(double amplitude, double offset, AgU25xxAOChannels channel);
    QString cmdApplySawToothWave(double amplitude, double offset, QVector<AgU25xxAOChannels> channels);
    QString cmdApplyTriangleWave(double amplitude, double offset, AgU25xxAOChannels channel);
    QString cmdApplyTriangleWave(double amplitude, double offset, QVector<AgU25xxAOChannels> channels);
    QString cmdApplyNoise(double amplitude, double offset, AgU25xxAOChannels channel);
    QString cmdApplyNoise(double amplitude, double offset, QVector<AgU25xxAOChannels> channels);
    QString cmdApplyUser(AgU25xxAOChannels channel);
    QString cmdApplyUser(QVector<AgU25xxAOChannels> channels);
};

#endif // AGU25XXAPPLY_H
