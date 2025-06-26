#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scanworker.h"
#include <QDir>
#include <QMessageBox>
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("系统垃圾清理pro版本");//设置窗口标题
    // 1. 按钮美化
ui->btnScan->setStyleSheet(//设置扫描按钮样式
    "QPushButton {"//设置按钮样式
    "background-color: #2196F3;"//设置按钮背景颜色
    "color: white;"//设置按钮文字颜色
    "border-radius: 12px;"//设置按钮圆角
    "font-size: 18px;"//设置按钮文字大小
    "padding: 10px 0;"//设置按钮内边距
    "box-shadow: 0 2px 8px rgba(33,150,243,0.2);"//设置按钮阴影
    "}"
    "QPushButton:hover { background-color: #1976D2; }"//设置按钮悬停背景颜色
);
ui->btnClean->setStyleSheet(//设置清理按钮样式  
    "QPushButton {"//设置按钮样式
    "background-color: #4CAF50;"//设置按钮背景颜色
    "color: white;"//设置按钮文字颜色
    "border-radius: 12px;"//设置按钮圆角
    "font-size: 18px;"//设置按钮文字大小    
    "padding: 10px 0;"//设置按钮内边距
    "box-shadow: 0 2px 8px rgba(76,175,80,0.2);"//设置按钮阴影
    "}"//设置按钮样式结束
    "QPushButton:hover { background-color: #388E3C; }"//设置按钮悬停背景颜色
);
ui->btnAbout->setStyleSheet(//设置关于按钮样式
    "QPushButton {"//设置按钮样式
    "background-color: #9C27B0;"//设置按钮背景颜色
    "color: white;"//设置按钮文字颜色
    "border-radius: 12px;"//设置按钮圆角
    "font-size: 18px;"//设置按钮文字大小
    "padding: 10px 0;"//设置按钮内边距
    "box-shadow: 0 2px 8px rgba(156,39,176,0.2);"//设置按钮阴影
    "}"//设置按钮样式结束
    "QPushButton:hover { background-color: #7B1FA2; }"//设置按钮悬停背景颜色
);

// 2. 进度条美化
ui->progressBar->setStyleSheet(
    "QProgressBar {"//设置进度条样式
    "border: 1px solid #bbb;"//设置进度条边框
    "border-radius: 10px;"//设置进度条圆角  
    "background: #eee;"//设置进度条背景颜色
    "height: 24px;"//设置进度条高度 
    "text-align: center;"//设置进度条文字居中
    "font-size: 16px;"//设置进度条文字大小
    "}"//设置进度条样式结束
    "QProgressBar::chunk {"//设置进度条块样式
    "border-radius: 10px;"//设置进度条块圆角
    "background: QLinearGradient(x1:0, y1:0, x2:1, y2:0, stop:0 #43e97b, stop:1 #38f9d7);"//设置进度条块背景颜色
    "}"//设置进度条块样式结束
);

// 3. 日志区美化
ui->listWidget->setStyleSheet(
    "QListWidget {"//设置列表框样式
    "background: white;"//设置列表框背景颜色
    "border-radius: 12px;"//设置列表框圆角
    "font-size: 15px;"//设置列表框文字大小
    "padding: 8px;"//设置列表框内边距
    "border: 1px solid #ddd;"//设置列表框边框
    "}"//设置列表框样式结束
);

// 4. 主窗口背景渐变
this->setStyleSheet(
    "QMainWindow {"//设置主窗口样式
    "background: QLinearGradient(x1:0, y1:0, x2:1, y2:1, stop:0 #e0eafc, stop:1 #cfdef3);"//设置主窗口背景颜色
    "}"//设置主窗口样式结束
);

// 5. 底部提示和版权（如需添加）
QLabel *labelTip = new QLabel("提示：扫描完成后点击清理按钮删除垃圾文件", this);//设置提示标签
labelTip->setAlignment(Qt::AlignCenter);//设置提示标签文字居中
labelTip->setStyleSheet("color: #888; font-size: 13px;");//设置提示标签文字颜色和大小
ui->statusbar->addWidget(labelTip, 1);

QLabel *labelCopyright = new QLabel("© 2025 系统清理工具 | 版本 2.0", this);//设置版权标签
labelCopyright->setAlignment(Qt::AlignCenter);//设置版权标签文字居中
labelCopyright->setStyleSheet("color: #aaa; font-size: 12px;");//设置版权标签文字颜色和大小
ui->statusbar->addPermanentWidget(labelCopyright, 1);//设置版权标签
    ui->progressBar->setValue(0);//设置进度条初始值
    ui->listWidget->clear();//清空列表框
    connect(ui->btnScan, &QPushButton::clicked, this, &MainWindow::on_btnScan_clicked);//设置扫描按钮点击事件
    connect(ui->btnClean, &QPushButton::clicked, this, &MainWindow::on_btnClean_clicked);//设置清理按钮点击事件
    connect(ui->btnAbout, &QPushButton::clicked, this, &MainWindow::on_btnAbout_clicked);//设置关于按钮点击事件
}

MainWindow::~MainWindow()
{
    if (scanThread) {//如果扫描线程存在
        scanThread->quit();//退出扫描线程
        scanThread->wait();//等待扫描线程结束
        delete scanThread;//删除扫描线程
    }
    delete ui;
}

void MainWindow::on_btnScan_clicked()
{
    ui->progressBar->setValue(0);
    ui->listWidget->clear();
    garbageFiles.clear();
    startScan();
}

void MainWindow::startScan()
{
    QStringList scanDirs = {
        qgetenv("TEMP"),
        QDir::tempPath(),
        "C:/Windows/Temp",
        "C:/Users/" + qgetenv("USERNAME") + "/AppData/Local/Google/Chrome/User Data/Default/Cache",
        "C:/Users/" + qgetenv("USERNAME") + "/AppData/Local/Microsoft/Windows/INetCache",
        "C:/Users/" + qgetenv("USERNAME") + "/AppData/Local/Microsoft/Edge/User Data/Default/Cache",
        "C:/Users/" + qgetenv("USERNAME") + "/AppData/Local/Mozilla/Firefox/Profiles"
    };

    scanThread = new QThread(this);
    worker = new ScanWorker(scanDirs);
    worker->moveToThread(scanThread);

    connect(scanThread, &QThread::started, worker, &ScanWorker::start);
    connect(worker, &ScanWorker::fileFound, this, &MainWindow::onFileFound);
    connect(worker, &ScanWorker::progress, this, &MainWindow::onScanProgress);
    connect(worker, &ScanWorker::finished, this, &MainWindow::onScanFinished);
    connect(worker, &ScanWorker::finished, scanThread, &QThread::quit);
    connect(scanThread, &QThread::finished, worker, &QObject::deleteLater);
    connect(scanThread, &QThread::finished, scanThread, &QObject::deleteLater);

    scanThread->start();
}

void MainWindow::onFileFound(const QFileInfo &info)
{
    garbageFiles.append(info);
    QString display = QString("%1 (%2)").arg(info.absoluteFilePath()).arg(humanReadableSize(info.size()));
    ui->listWidget->addItem(display);
}

void MainWindow::onScanProgress(int current, int total)
{
    ui->progressBar->setValue(current * 100 / total);
}

void MainWindow::onScanFinished()
{
    qint64 totalSize = 0;
    for (const QFileInfo &fi : garbageFiles) totalSize += fi.size();
    QMessageBox::information(this, "扫描完成",
                             QString("共找到 %1 个垃圾文件，总大小：%2").arg(garbageFiles.size()).arg(humanReadableSize(totalSize)));
    ui->progressBar->setValue(100);
}

void MainWindow::on_btnClean_clicked()
{
    cleanGarbage();
}

void MainWindow::cleanGarbage()
{
    if (garbageFiles.isEmpty()) {
        QMessageBox::information(this, "提示", "没有可清理的垃圾文件，请先扫描。");
        return;
    }
    int deleted = 0, failed = 0;
    qint64 cleanedSize = 0;
    int fileCount = garbageFiles.size();
    for (int i = 0; i < fileCount; ++i) {
        const QFileInfo &fi = garbageFiles[i];
        QFile file(fi.absoluteFilePath());
        if (file.remove()) {
            deleted++;
            cleanedSize += fi.size();
            ui->listWidget->item(i)->setForeground(Qt::gray);
        } else {
            failed++;
            ui->listWidget->item(i)->setForeground(Qt::red);
        }
        ui->progressBar->setValue(i * 100 / fileCount);
        qApp->processEvents();
    }
    QMessageBox::information(this, "清理完成",
                             QString("成功删除 %1 个文件，失败 %2 个，释放空间：%3")
                                 .arg(deleted).arg(failed).arg(humanReadableSize(cleanedSize)));
    ui->progressBar->setValue(0);
    garbageFiles.clear();
}

void MainWindow::on_btnAbout_clicked()
{
    QMessageBox::about(this, "关于", "3秒垃圾归0版\n系统垃圾清理工具\n© 2025");
}

QString MainWindow::humanReadableSize(qint64 size)
{
    if (size < 1024) return QString("%1 B").arg(size);
    if (size < 1024 * 1024) return QString::asprintf("%.2f KB", size / 1024.0);
    if (size < 1024 * 1024 * 1024) return QString::asprintf("%.2f MB", size / 1024.0 / 1024.0);
    return QString::asprintf("%.2f GB", size / 1024.0 / 1024.0 / 1024.0);
}
