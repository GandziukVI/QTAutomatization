#ifndef IEXPERIMENT_H
#define IEXPERIMENT_H

#include <QFuture>
#include <QMutex>
#include <QObject>

class IExperiment : public QObject
{
    Q_OBJECT
public:
    IExperiment();
    IExperiment(QObject *expSettings);
    ~IExperiment();

    virtual void start();
    virtual void stop();
    virtual void toDo(QObject *expSettings) = 0;

    bool mExperimentIsRunning;
private:
    QObject        *mExpSettings;
    mutable QMutex mIExperimentMutex;
    QFuture<void>  mExpThreadRes;
};

#endif // IEXPERIMENT_H
