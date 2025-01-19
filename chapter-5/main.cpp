#include <QCoreApplication>
#include <QString>
#include <QDebug>
#include <string>
#include <vector>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

void printAll(QString& str1, QString& str2, QString& str3) {
    qDebug() << "str1: " << str1;
    qDebug() << "str2: " << str2;
    qDebug() << "str3: " << str3;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

// constructor
    QString str1 = QString();
    QString str2 = QString("some text");
    QString str3 = QString(10, 'a');
    printAll(str1, str2, str3);

// .append
    str1.append("abc");
    str2.append('*');
    const QChar* c = new QChar[3]{'b','c','d'};
    str3.append(c, 2);

    printAll(str1, str2, str3);

    delete[] c;
// .arg
    QString str = QString("Name: %1, Age: %2, Height(m): %3");
    qDebug() << str.arg("Bob", "30", "1.80");
    qDebug() << str.arg("Bob").arg(30).arg(1.80);
    qDebug() << str.arg("Bob", 5, '-')
                    .arg(120, 2, 16, QChar(' '))
        .arg(1.801, 3, 'f', 2, '-');
/*
•	‘f’ – Fixed point notation (The number is displayed in standard fixed-point notation.)
•	‘e’ – Scientific notation (The number is displayed in scientific notation (e.g., 1.23456e+02).
•	‘g’ – General format (The number is displayed in the shorter of fixed-point or scientific notation, depending on the magnitude of the number.)
•	‘G’ (Same as 'g', but uses uppercase letters for the exponent in scientific notation (e.g., 1.23E+02 instead of 1.23e+02).
*/
// .assign
    QLatin1StringView l_str("Hello");
    std::string s("World");
    std::vector<char> vec_str = {'W', 'o', 'r', 'd'};

    str.assign(l_str);
    qDebug() << str;
    str.assign(s);
    qDebug() << str;

    str.assign(vec_str.begin(), vec_str.end() - 1);
    qDebug() << str;

    str.assign(l_str.begin() + 2, l_str.end());
    qDebug() << str;
// .at
    qDebug() << "str #2" << str.at(2);
    qDebug() << "str #2" << str[2];

// back
    qDebug() << str.back();
    str = "";
    //Debug() << str.back();

// begin
    str = "ABC";
    qDebug() << str.begin();
    qDebug() << *(str.begin());
// capacity
    qDebug() << str << str.capacity();
// cbegin
    qDebug() << *(str.cend());
    qDebug() << *(str.cend() - 1);
    qDebug() << *(str.cbegin());
// chop
    str = "abcde";
    str.chop(3);
    qDebug() << str;

    str.chop(5);
    qDebug() << str;
// chopped
    str = "abcde";
    qDebug() << str.chopped(2);
    qDebug() << str;
// clear
    str.clear();
    qDebug() << str;
// compare
    int x = QString::compare("aUtO", "AuTo", Qt::CaseInsensitive);
    qDebug() << x;

    int y = QString::compare("auto", "Car", Qt::CaseSensitive);
    qDebug() << y;

    int z = QString::compare("auto", "Car", Qt::CaseInsensitive);
    qDebug() << z;

// .constBegin, constEnd == cbegin, cend

// constData
    str = "Hello";
    const QChar* chars = str.constData();

    for (int i = 0; i < str.size(); i++) {
        qDebug() << chars[i];
    }
// contains
    str.append(" World");
    qDebug() << str;
    if (str.contains("rld")) {
        qDebug() << "str contain \"rld\"";
    }
    if (str.contains("HE", Qt::CaseInsensitive)) {
        qDebug() << "str contain \"HE\"";
    }

    static const QRegularExpression re("\\bWorld\\b");
    QRegularExpressionMatch match;

    if (str.contains(re, &match)) {
        qDebug() << match.captured(0);
    }
// count
    str = "xoxoxoxox";
    int count = str.count("Xox", Qt::CaseInsensitive);
    qDebug() << count;

// endsWith
    if (str.endsWith("Xox", Qt::CaseInsensitive)) {
        qDebug() << "endsWith";
    }
// erase
    str = "abcdefgh";
    str.erase(str.cbegin() + 3, str.cend() - 2);
    qDebug() << str;

    str.erase(str.cbegin());
    qDebug() << str;

// fill
    str.fill('a');
    qDebug() << str;

// first
    qDebug() << str.first(2);
    qDebug() << str.left(20);

// indexOf
    str = "mytxtfile.txt";
    qDebug() << str.indexOf("txt");
    qDebug() << str.indexOf("txt", 5);
// insert
    qDebug() << str.insert(2, " ** ");
    qDebug() << str;
// isEmpty, isNull
    qDebug () << str.isEmpty();
    str = "";
    qDebug () << str.isEmpty();
    qDebug () << str.isNull();
    QString nullStr;
    qDebug () << nullStr.isNull();
// left
    str = "ABC";
    qDebug() << str.left(10);

// leftJustField
    str = str.leftJustified(5, '*');
    qDebug() << str;
    str = str.leftJustified(2, '*', true);
    qDebug() << str;
// length
    str = "ABCDE";
    for (int i = 0; i < str.length(); i++) {
        qDebug() << str[i];
    }

// mid
    qDebug() << str.mid(2, 2);

// prepend
    str.prepend("....");
    qDebug() << str;

// remove
    str.remove("..");
    qDebug() << str;

    str.remove(1, 3);
    qDebug() << str;

// removeFirst, removeLast
    str.removeFirst();
    str.removeLast();
    str.removeFirst();

    qDebug() << str;

// repeted
    str = "TEXT ";
    str = str.repeated(3);
    qDebug() << str;

// replace
    str.replace("TEXT", "a");
    qDebug() << str;

// section
    str = "root/bin/users/myfile.txt";
    qDebug() << str.section('/', 1, 1, QString::SectionSkipEmpty);
    qDebug() << str.section('/', 1, 3, QString::SectionSkipEmpty);

// setNum
    int num = 1234;
    str.setNum(num);
    qDebug() << str;

// simplified
//  '\t', '\n', '\v', '\f', '\r'
    str = "  text\t qwe\r\n";
    str = str.simplified();
    qDebug() << str;

// split
    str = "1,,2,3,4";
    QStringList l = str.split(',', Qt::SkipEmptyParts);

    qDebug() << l;

// toFloat, toStdString ...
    str = "1.123";
    float fStr = str.toFloat();
    qDebug() << fStr;

    str = "abc";
    qDebug() << str.toUpper();

// trimmed
    str = "  asd  ";
    qDebug() << str.trimmed();

    return a.exec();
}








