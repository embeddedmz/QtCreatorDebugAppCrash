#ifndef SHARED_H
#define SHARED_H

struct DataItem
{
    DataItem() = default;
    DataItem(QString name) : name(name) {}

    QString name;
    bool isWarning = false;
    bool isError = false;
};

#endif // SHARED_H
