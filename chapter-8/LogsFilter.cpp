#include "LogsFilter.h"

LogsFilter::LogsFilter(QObject *parent)
    : QObject{parent}, m_filePath("")
{}

LogsFilter::LogsFilter(QString path, QObject *parent)
    : QObject{parent}, m_filePath(path)
{

}

void LogsFilter::searchLogs(const QString &type)
{
    if (m_filePath.isEmpty()) return;

    QFile file(m_filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    m_filteredLogs.clear();
    m_filteredLogs.reserve(100);

    QTextStream in(&file);
    while (!in.atEnd()) {
        QStringView line = in.readLine();

        if (line.startsWith(type)) {
            QStringView clearLine = line.mid(type.size() + 2);

            m_filteredLogs.append(clearLine).append('\n');
        }
    }

    file.close();
    emit filteredLogsChanged();
}

const QString LogsFilter::getFileName() const
{
    if (m_filePath.isEmpty()) return QLatin1String("No file chosen.");

    QFileInfo fileInfo(m_filePath);
    if (!fileInfo.exists()) {
        return QLatin1String("File does not exist!");
    }

    return fileInfo.fileName();
}


void LogsFilter::setFilePath(const QString &filePath)
{
    QString localPath = QUrl(filePath).toLocalFile(); // file:///E:/c+-/QtSeries/data/logs.txt by default

    if (m_filePath != localPath) {
        m_filePath = localPath;

        emit filePathChanged();
        emit fileNameChanged();
    }
}

// LogsFilter *LogsFilter::create(QQmlEngine *, QJSEngine *)
// {
//     return new LogsFilter("");
// }


// static LogsFilter* s_instance = nullptr;
// LogsFilter *LogsFilter::instance(QQmlEngine*, QJSEngine*)
// {
//     if (!s_instance) s_instance = new LogsFilter();
//     return s_instance;
// }

