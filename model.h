#ifndef MODEL_H
#define MODEL_H

#include <QAbstractTableModel>
#include "comp.h"


class objModel1 : public QAbstractTableModel
{
    Q_OBJECT
public:
    objModel1(QVector<comp> *comp, QObject *parent = nullptr);
    objModel1();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void setModel(COMP<comp>* comp);
protected:
    QVector<comp> *_comp;
};

class objModel2 : public QAbstractTableModel
{
    Q_OBJECT
public:
    objModel2(QVector<bag> *bag, QObject *parent = nullptr);
    objModel2();

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void setModel(COMP<bag>* bag);
protected:
    QVector<bag> *_bag;
};

#endif // MODEL_H

