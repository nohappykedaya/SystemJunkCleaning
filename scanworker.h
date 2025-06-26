#ifndef SCANWORKER_H
#define SCANWORKER_H

#include <QObject>
#include <QFileInfo>
#include <QStringList>

class ScanWorker : public QObject
{
    Q_OBJECT
public:
    explicit ScanWorker(const QStringList &dirs, QObject *parent = nullptr);

signals:
    void fileFound(const QFileInfo &info);
    void progress(int current, int total);
    void finished();

public slots:
    void start();

private:
    QStringList scanDirs;
    void scanDir(const QString &dirPath, int &current, int total);
};

#endif // SCANWORKER_H
