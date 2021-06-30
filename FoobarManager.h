#ifndef FOOBARMANAGER_H
#define FOOBARMANAGER_H

#include <QObject>

#include "Shared.h"

class FoobarManager final : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(FoobarManager)
public:
    explicit FoobarManager(QObject* parent = nullptr);
    ~FoobarManager() override;

public slots:
    void initialize();
    void stop();

signals:
    void dataItemReceived(DataItem);

protected:
    struct Internals;
    Internals* m_Internals;

};

#endif // FOOBARMANAGER_H
