#include "FoobarManager.h"
#include "Shared.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qRegisterMetaType<DataItem>("DataItem");

    m_foobarThread = new QThread;
    m_foobarMgr = new FoobarManager;

    QObject::connect(m_foobarMgr, &FoobarManager::dataItemReceived,
            this, [this](DataItem data) {
                processData(data);
            }/*, Qt::QueuedConnection*/); /* Qt::QueuedConnection has to be added to fix
                                      VS2019 debugger freezing if a breakpoint is defined
                                      in this lambda */

    QObject::connect(m_foobarThread, &QThread::started,
                     m_foobarMgr, &FoobarManager::initialize);
    QObject::connect(m_foobarThread, &QThread::finished,
                     m_foobarMgr, &FoobarManager::stop);

    m_foobarMgr->moveToThread(m_foobarThread);
    m_foobarThread->start();
}

MainWindow::~MainWindow()
{
    m_foobarThread->quit();
    m_foobarThread->wait();

    delete m_foobarThread;
    delete m_foobarMgr;
    delete ui;
}

void MainWindow::processData(DataItem item)
{
    (void) item;
    qDebug() << "Received a new data item !";
}
