#include "model.h"
#include <QString>
objModel1::objModel1(QVector<comp> *data, QObject *parent) : QAbstractTableModel(parent), _comp(data)
{}

objModel1::objModel1():_comp(new QVector<comp>()) {}

int objModel1::rowCount([[maybe_unused]] const QModelIndex &parent) const
{
    return _comp->count();
}

int objModel1::columnCount([[maybe_unused]] const QModelIndex &parent) const
{
    return 3;
}

QVariant objModel1::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if(orientation == Qt::Horizontal)
    {
        switch(section)
        {
        case 0: return tr("Название");
        case 1: return tr("Секция");
        case 2: return tr("Цена");
        default: return QVariant();
        }
    }
    else
    {
        return QString("%1").arg(section + 1);//номер секции увеличивается на 1, отображение заголовка
    }

}

QVariant objModel1::data(const QModelIndex &index, int role) const
{
    if(role != Qt::DisplayRole)
    {
        return QVariant();
    }

    switch(index.column())
    {
    case 0: return QString((*_comp)[index.row()].name);
    case 1: return QString("%1").arg((*_comp)[index.row()].section);
    case 2: return QString("%1").arg((*_comp)[index.row()].price);
    default: return QVariant();
    }

    return QVariant();
}

void objModel1::setModel(COMP<comp> *comp)
{
    beginResetModel();
    _comp->clear();
    for (int i=0; i < comp->size(); i++)
    {
        *_comp<<(comp->at(i));}
    endResetModel();
}

//------------------------------------

objModel2::objModel2(QVector<bag> *data, QObject *parent) : QAbstractTableModel(parent), _bag(data)
{}

objModel2::objModel2():_bag(new QVector<bag>()) {}

int objModel2::rowCount([[maybe_unused]] const QModelIndex &parent) const
{
    return _bag->count();
}

int objModel2::columnCount([[maybe_unused]] const QModelIndex &parent) const
{
    return 3;
}

QVariant objModel2::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if(orientation == Qt::Horizontal)
    {
        switch(section)
        {
        case 0: return tr("Название");
        case 1: return tr("Секция");
        case 2: return tr("Количество");
        default: return QVariant();
        }
    }
    else
    {
        return QString("%1").arg(section + 1);//номер секции увеличивается на 1, отображение заголовка
    }

}

QVariant objModel2::data(const QModelIndex &index, int role) const
{
    if(role != Qt::DisplayRole)
    {
        return QVariant();
    }

    switch(index.column())
    {
    case 0: return QString((*_bag)[index.row()].name);
    case 1: return QString("%1").arg((*_bag)[index.row()].section);
    case 2: return QString("%1").arg((*_bag)[index.row()].num);
    default: return QVariant();
    }

    return QVariant();
}

void objModel2::setModel(COMP<bag> *bag)
{
    beginResetModel();
    _bag->clear();
    for (int i=0; i < bag->size(); i++)
    {
        *_bag<<(bag->at(i));}
    endResetModel();
}

