#ifndef AGU25XXAPPLY_H
#define AGU25XXAPPLY_H

#include "agilentu25xx_global.h"
#include "IAgU25xxSubsystem.h"
#include "AgU25xxDefinitions.h"


class AGILENTU25XXSHARED_EXPORT AgU25xxAPPLy : public IAg25xxSubsystem
{
public:
    AgU25xxAPPLy();

    QString cmdGetAOParams(AgU25xxAnalogOutput::AOChannels channel);
    QString cmdGetAOParams(QVector<AgU25xxAnalogOutput::AOChannels> channels);
    QString cmdApplySineWave(double amplitude, double offset, AgU25xxAnalogOutput::AOChannels channel);
    QString cmdApplySineWave(double amplitude, double offset, QVector<AgU25xxAnalogOutput::AOChannels> channels);
    QString cmdApplySquareWave(double amplitude, double offset, AgU25xxAnalogOutput::AOChannels channel);
    QString cmdApplySquareWave(double amplitude, double offset, QVector<AgU25xxAnalogOutput::AOChannels> channels);
    QString cmdApplySawToothWave(double amplitude, double offset, AgU25xxAnalogOutput::AOChannels channel);
    QString cmdApplySawToothWave(double amplitude, double offset, QVector<AgU25xxAnalogOutput::AOChannels> channels);
    QString cmdApplyTriangleWave(double amplitude, double offset, AgU25xxAnalogOutput::AOChannels channel);
    QString cmdApplyTriangleWave(double amplitude, double offset, QVector<AgU25xxAnalogOutput::AOChannels> channels);
    QString cmdApplyNoise(double amplitude, double offset, AgU25xxAnalogOutput::AOChannels channel);
    QString cmdApplyNoise(double amplitude, double offset, QVector<AgU25xxAnalogOutput::AOChannels> channels);
    QString cmdApplyUser(double amplitude, double offset, AgU25xxAnalogOutput::AOChannels channel);
    QString cmdApplyUser(double amplitude, double offset, QVector<AgU25xxAnalogOutput::AOChannels> channels);
};

#endif // AGU25XXAPPLY_H
