#ifndef LOGSFILTER_H
#define LOGSFILTER_H

#include <QObject>
#include <QUrl>
#include <QFileInfo>
#include <QQmlEngine>
#include <QtQml/qqmlregistration.h>

class LogsFilter : public QObject
{
    Q_OBJECT
    //QML_SINGLETON
    QML_ELEMENT

    Q_PROPERTY(QString filePath READ filePath WRITE setFilePath NOTIFY filePathChanged)
    Q_PROPERTY(QString filteredLogs READ filteredLogs NOTIFY filteredLogsChanged)
    Q_PROPERTY(QString fileName READ getFileName NOTIFY fileNameChanged)
public:
    explicit LogsFilter(QObject *parent = nullptr);
    explicit LogsFilter(QString path, QObject *parent = nullptr);

    Q_INVOKABLE void searchLogs(const QString& type);
    const QString getFileName() const;

    QString filteredLogs() const {return m_filteredLogs;}
    QString filePath() const {return m_filePath;}

    void setFilePath(const QString& filePath);

    //static LogsFilter* create(QQmlEngine *, QJSEngine *);
   // static LogsFilter* instance(QQmlEngine*, QJSEngine*);
signals:
    void filteredLogsChanged();
    void filePathChanged();
    void fileNameChanged();

private:
    QString m_filteredLogs; // could be QStringList
    QString m_filePath;
};

#endif // LOGSFILTER_H
