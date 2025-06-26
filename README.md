
# 系统垃圾清理工具

## 项目简介
本项目是一款基于 Qt 开发的 Windows 系统垃圾清理工具，能够自动扫描并清理常见的系统及浏览器缓存垃圾文件，提升系统运行效率。界面美观，操作简便，支持进度显示和日志输出。

## 应用技术
- C++
- Qt Widgets
- 多线程编程
- QSS 界面美化

## 功能特性
- 一键扫描系统及常见浏览器的垃圾文件
- 实时显示扫描进度
- 日志窗口展示详细扫描与清理信息
- 支持多线程，界面流畅不卡顿
- 按钮、进度条、日志区等控件美化，用户体验良好

## 运行截图
![image](https://github.com/user-attachments/assets/f0aacdcf-961e-4fe9-be44-fd0a7f7c1fd9)


## 编译与运行

### 环境要求
- Qt 5.x 或 Qt 6.x（建议使用 Qt Creator 集成开发环境）
- C++11 及以上

### 编译步骤
1. 使用 Qt Creator 打开 `Cleaning.pro` 工程文件。
2. 配置合适的 Qt 版本和编译器。
3. 点击“构建”并运行即可。

或使用命令行编译：
```bash
qmake Cleaning.pro
make
./Cleaning.exe
```

## 主要文件说明
- `main.cpp`：程序入口
- `mainwindow.h/cpp/ui`：主窗口及核心逻辑
- `scanworker.h/cpp`：垃圾扫描与清理的工作线程

## 致谢
感谢 Qt 官方文档及开源社区的技术支持。
