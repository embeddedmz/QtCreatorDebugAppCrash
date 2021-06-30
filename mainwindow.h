#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Shared.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class FoobarManager;
class QThread;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void processData(DataItem);

private:
    Ui::MainWindow *ui;

    FoobarManager* m_foobarMgr = nullptr;
    QThread* m_foobarThread = nullptr;
};
#endif // MAINWINDOW_H
