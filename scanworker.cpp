#include "scanworker.h"
#include <QDir>
#include <QDirIterator>

ScanWorker::ScanWorker(const QStringList &dirs, QObject *parent)
    : QObject(parent), scanDirs(dirs) {}

void ScanWorker::start()
{
    int total = scanDirs.size();
    int current = 0;
    for (const QString &dirPath : scanDirs) {
        scanDir(dirPath, current, total);
        emit progress(++current, total);
    }
    emit finished();
}

void ScanWorker::scanDir(const QString &dirPath, int &current, int total)
{
    QDir dir(dirPath);
    if (!dir.exists()) return;
    QDirIterator it(dirPath, QDir::Files | QDir::NoSymLinks, QDirIterator::Subdirectories);
    while (it.hasNext()) {
        it.next();
        emit fileFound(it.fileInfo());
    }
}
