#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileInfo>
#include <QList>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class ScanWorker;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnScan_clicked();
    void on_btnClean_clicked();
    void on_btnAbout_clicked();

    // 扫描线程相关槽
    void onFileFound(const QFileInfo &info);
    void onScanProgress(int current, int total);
    void onScanFinished();

private:
    Ui::MainWindow *ui;
    QList<QFileInfo> garbageFiles;
    QThread *scanThread = nullptr;
    ScanWorker *worker = nullptr;

    void startScan();
    void cleanGarbage();
    void log(const QString &msg);
    QString humanReadableSize(qint64 size);
};

#endif // MAINWINDOW_H
