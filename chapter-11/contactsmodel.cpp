#include "contactsmodel.h"
#include <QDebug>

ContactsModel::ContactsModel(QObject *parent)
    : QAbstractListModel{parent}
{
    m_items = std::vector<Contact>(
        {{QStringLiteral("Bill"), QStringLiteral("bill5@mail.com")},
        {QStringLiteral("John"), QStringLiteral("john1@mail.com")},
        {QStringLiteral("Sam"), QStringLiteral("sam@mail.com")}
    });
}

int ContactsModel::rowCount(const QModelIndex &parent = QModelIndex()) const
{
    qDebug() << "rowCount() is called";
    return m_items.size();
}

QVariant ContactsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant(false);

    qDebug() << "data() is called";

    switch (role) {
    case NameRole:
        return m_items[index.row()].name;

    case EmailRole:
        return m_items[index.row()].email;
    }

    return QVariant(false);
}

QHash<int, QByteArray> ContactsModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[EmailRole] = "email";

    qDebug() << "roleNames() is called";
    return roles;
}

bool ContactsModel::insertRows(int row, int count, const QModelIndex &parent)
{
    if (row < 0 || row > rowCount() || count < 0) return false;

    beginInsertRows(parent, row, row + count - 1);

    for (int i = row; i < row + count; i++) {
        m_items.insert(m_items.begin() + i, Contact{});
    }

    endInsertRows();
    return true;

}

void ContactsModel::appendEmptyRow()
{
    insertRows(rowCount(), 1, QModelIndex());
}

bool ContactsModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid()) return false;

    Contact& item = m_items[index.row()];
    switch (role) {
    case (NameRole):
        item.name = value.toString();
        break;
    case (EmailRole):
        item.email = value.toString();
        break;
    default:
        return false;
    }

    emit dataChanged(index, index, {role});
    return true;
}

bool ContactsModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if (row < 0 || row > rowCount() ||
        row + count < 0 || row + count > rowCount()) return false;

    beginRemoveRows(parent, row, row + count - 1);

    m_items.erase(m_items.begin() + row, m_items.begin() + row + count);

    endRemoveRows();
    return true;
}

void ContactsModel::removeAt(int row)
{
    removeRows(row, 1, QModelIndex());
}
