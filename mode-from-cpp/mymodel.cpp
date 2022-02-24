#include "mymodel.h"
#include <QByteArray>
#include <QTimer>
#include <cstdlib>

mymodel::mymodel(QObject *parent) :
         QAbstractListModel(parent)
{
    m_data
            << Data("Denmark", "qrc:images/denmark.jpg", 5.6)
            << Data("Sweden", "qrc:images/sweden.jpg", 9.6)
            << Data("Iceland", "qrc:images/iceland.jpg", 0.3)
            << Data("Norway", "qrc:images/norway.jpg", 5.1)
            << Data("Finland", "qrc:images/finland.jpg", 5.4);

    QTimer *growthTimer = new QTimer(this);
    connect(growthTimer, &QTimer::timeout, this, &mymodel::growPopulation);
    growthTimer->start(2000);
}

int mymodel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
           return 0;

    return m_data.count();
}

QVariant mymodel::data(const QModelIndex &index, int role) const
{
    if ( !index.isValid() )
            return QVariant();

        const Data &data = m_data.at(index.row());
        if ( role == NameRole ){
            return data.name;
        }
        else if ( role == FlagRole )
            return data.flag;
        else if ( role == PopulationRole )
            return data.population;
        else
            return QVariant();
}

QHash<int, QByteArray> mymodel::roleNames() const
{
    static QHash<int, QByteArray> mapping {
           {NameRole, "name"},
           {FlagRole, "flag"},
           {PopulationRole, "population"}
       };
    return mapping;
}

void mymodel::duplicateData(int row)
{
    if (row < 0 || row >= m_data.count())
           return;

       const Data data = m_data[row];
       const int rowOfInsert = row + 1;

       beginInsertRows(QModelIndex(), rowOfInsert, rowOfInsert);
       m_data.insert(rowOfInsert, data);
       endInsertRows();
}

void mymodel::removeData(int row)
{
    if (row < 0 || row >= m_data.count())
           return;

     beginRemoveRows(QModelIndex(), row, row);
     m_data.removeAt(row);
     endRemoveRows();
}

void mymodel::growPopulation()
{
    const double growthFactor = 0.01 / RAND_MAX;

        const int count = m_data.count();
        for (int i = 0; i < count; ++i) {
            m_data[i].population += m_data[i].population * qrand() * growthFactor;
        }

        // we've just updated all rows...
        const QModelIndex startIndex = index(0, 0);
        const QModelIndex endIndex   = index(count - 1, 0);

        // ...but only the population field
        emit dataChanged(startIndex, endIndex, QVector<int>() << PopulationRole);
}


