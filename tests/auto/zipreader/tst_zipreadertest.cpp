#include "xlsxzipreader_p.h"
#include <QString>
#include <QtTest>
#include <QBuffer>

const char fileContent[] = "\x50\x4B\x03\x04\x0A\x00\x00\x00\x00\x00\x8F\x51\x25\x43\x82\x89\xD1\xF7\x05\x00\x00\x00\x05\x00\x00\x00\x09\x00\x00\x00\x68\x65\x6C\x6C\x6F\x2E\x74\x78\x74\x48\x65\x6C\x6C\x6F\x50\x4B\x03\x04\x0A\x00\x00\x00\x00\x00\xB8\x53\x25\x43\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x03\x00\x00\x00\x71\x74\x2F\x50\x4B\x03\x04\x0A\x00\x00\x00\x00\x00\x92\x51\x25\x43\x2E\x19\xFC\x34\x04\x00\x00\x00\x04\x00\x00\x00\x0B\x00\x00\x00\x71\x74\x2F\x78\x6C\x73\x78\x2E\x74\x78\x74\x58\x6C\x73\x78\x50\x4B\x01\x02\x14\x00\x0A\x00\x00\x00\x00\x00\x8F\x51\x25\x43\x82\x89\xD1\xF7\x05\x00\x00\x00\x05\x00\x00\x00\x09\x00\x00\x00\x00\x00\x00\x00\x01\x00\x20\x00\x00\x00\x00\x00\x00\x00\x68\x65\x6C\x6C\x6F\x2E\x74\x78\x74\x50\x4B\x01\x02\x14\x00\x0A\x00\x00\x00\x00\x00\xB8\x53\x25\x43\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x00\x03\x00\x00\x00\x00\x00\x00\x00\x00\x00\x10\x00\x00\x00\x2C\x00\x00\x00\x71\x74\x2F\x50\x4B\x01\x02\x14\x00\x0A\x00\x00\x00\x00\x00\x92\x51\x25\x43\x2E\x19\xFC\x34\x04\x00\x00\x00\x04\x00\x00\x00\x0B\x00\x00\x00\x00\x00\x00\x00\x01\x00\x20\x00\x00\x00\x4D\x00\x00\x00\x71\x74\x2F\x78\x6C\x73\x78\x2E\x74\x78\x74\x50\x4B\x05\x06\x00\x00\x00\x00\x03\x00\x03\x00\xA1\x00\x00\x00\x7A\x00\x00\x00\x00\x00";

class ZipReaderTest : public QObject
{
    Q_OBJECT
    
public:
    ZipReaderTest();
    
private Q_SLOTS:
    void testFileList();
};

ZipReaderTest::ZipReaderTest()
{
}

void ZipReaderTest::testFileList()
{
    QByteArray data(fileContent, sizeof(fileContent) - 1);
    QBuffer buffer(&data);
    buffer.open(QIODevice::ReadOnly);

    QXlsx::ZipReader reader(&buffer);

    QStringList files = reader.filePaths();
    QVERIFY(files.contains("hello.txt"));
    QVERIFY(files.contains("qt/xlsx.txt"));
    QCOMPARE(reader.fileData("hello.txt"), QByteArray("Hello"));
    QCOMPARE(reader.fileData("qt/xlsx.txt"), QByteArray("Xlsx"));
}

QTEST_APPLESS_MAIN(ZipReaderTest)

#include "tst_zipreadertest.moc"
