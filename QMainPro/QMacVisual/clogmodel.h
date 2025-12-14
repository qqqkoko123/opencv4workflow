#pragma once
#pragma execution_character_set("utf-8")

#include <QAbstractListModel>

class CLogModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit CLogModel(QObject *parent = nullptr);
    ~CLogModel();

public:
    //删除
    bool remove(int index);   
    //清空数据
    void clear();
    //数据长度
    int length() const;
    //index是否有效
    bool isValid(int index) const;

public slots:
    //插入
    bool insert(int index, const QString item);

public:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

protected:
    QStringList m_datas;
};
