#include "clogmodel.h"
#include "qmutex.h"

CLogModel::CLogModel(QObject *parent) : QAbstractListModel(parent)
{
    m_datas.reserve(100000);
}

CLogModel::~CLogModel()
{
    clear();
}

bool CLogModel::insert(int index, const QString item)
{      
    const int count = length();
    if (count > 500)
    {
        beginRemoveRows(QModelIndex(), 0, count - 1);
        m_datas.clear();
        endRemoveRows();
    }
    if (index >= 0  && index <= count)
    {
        beginInsertRows(QModelIndex(), index, index);
        m_datas.insert(index, item);
        endInsertRows();
        return true;
    }
    return false;
}

bool CLogModel::remove(int index)
{
    if(index < 0 || index >= m_datas.count())
        return false;
    beginRemoveRows(QModelIndex(), index, index);
    m_datas.removeAt(index);
    endRemoveRows();
    return true;
}

void CLogModel::clear()
{
    const int rows = m_datas.count();
    if(rows < 1)
        return;
    beginRemoveRows(QModelIndex(), 0, rows - 1);
    m_datas.clear();
    endRemoveRows();
}

int CLogModel::length() const
{   
    return m_datas.length();
}

bool CLogModel::isValid(int index) const
{
    if(index >= 0 && index < length() )
    {
        return true;
    }
    return false;
}

int CLogModel::rowCount(const QModelIndex &/*parent*/) const
{
    return length();
}

int CLogModel::columnCount(const QModelIndex &/*parent*/) const
{
    return 1;
}

Qt::ItemFlags CLogModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;
    return QAbstractListModel::flags(index);
}

QVariant CLogModel::data(const QModelIndex &index, int role) const
{   
    if(index.isValid())
    {
        if(role == Qt::DisplayRole)
        {
            return m_datas.value(index.row(), QString());            
        }
    }
    return QVariant();
}

bool CLogModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid())
    {
        if(role == Qt::DisplayRole)
        {
            m_datas[index.row()] = value.toString();
            emit dataChanged(index, index);
            return true;
        }
    }
    return QAbstractListModel::setData(index, value, role);
}
