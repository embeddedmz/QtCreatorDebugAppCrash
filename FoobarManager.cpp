#include "FoobarManager.h"

#include <QDebug>
#include <QTimer>

struct FoobarManager::Internals
{
    QTimer* Timer = nullptr;
};

FoobarManager::FoobarManager(QObject* parent) :
    QObject(parent),
    m_Internals(new FoobarManager::Internals)
{

}

FoobarManager::~FoobarManager()
{
    delete m_Internals;
}

void FoobarManager::initialize()
{
    if (m_Internals->Timer != nullptr)
    {
        delete m_Internals->Timer;
    }

    m_Internals->Timer = new QTimer(this);
    m_Internals->Timer->setInterval(2000);
    m_Internals->Timer->setSingleShot(false);
    m_Internals->Timer->callOnTimeout([this]()
    {
        DataItem di;
        emit dataItemReceived(di);
    });
    m_Internals->Timer->start();
}

void FoobarManager::stop()
{
    m_Internals->Timer->stop();
}
