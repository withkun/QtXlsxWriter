/****************************************************************************
** Copyright (c) 2013-2014 Debao Zhang <hello@debao.me>
** All right reserved.
**
** Permission is hereby granted, free of charge, to any person obtaining
** a copy of this software and associated documentation files (the
** "Software"), to deal in the Software without restriction, including
** without limitation the rights to use, copy, modify, merge, publish,
** distribute, sublicense, and/or sell copies of the Software, and to
** permit persons to whom the Software is furnished to do so, subject to
** the following conditions:
**
** The above copyright notice and this permission notice shall be
** included in all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
** EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
** MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
** NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
** LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
** OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
** WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**
****************************************************************************/

#ifndef QXLSX_DRAWING_H
#define QXLSX_DRAWING_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt Xlsx API.  It exists for the convenience
// of the Qt Xlsx.  This header file may change from
// version to version without notice, or even be removed.
//
// We mean it.
//

#include "xlsxrelationships_p.h"
#include "xlsxabstractooxmlfile.h"
#include "xlsxdrawinganchor_p.h"
#include "xlsxmediafile_p.h"
#include <QList>
#include <QString>
#include <QSharedPointer>

#include <QByteArray>

class QIODevice;
class QXmlStreamWriter;

namespace QXlsx {

class DrawingAnchor;
class Workbook;
class AbstractSheet;
class MediaFile;

class Drawing : public AbstractOOXmlFile
{
public:
    Drawing(AbstractSheet *sheet, CreateFlag flag);
    ~Drawing();
    void saveToXmlFile(QIODevice *device) const override;
    bool loadFromXmlFile(QIODevice *device) override;

    QList<QByteArray> getByteArray(QList<int> &rows, QList<int> &cols){
        QList<QByteArray> qBytes;
        int count = anchors.count();
        for(int i = 0;i < count;i++){
            DrawingAnchor* my_anchor = anchors.at(i);

            MediaFile* m_mediafile = my_anchor->m_pictureFile.data();
            QByteArray contents = m_mediafile->m_contents;

            qBytes.append(contents);

            DrawingTwoCellAnchor* cellanchor=static_cast<DrawingTwoCellAnchor*>(my_anchor);
            rows.append(cellanchor->from.row());
            cols.append(cellanchor->from.col());
            // printf("col:\t%d\t",cellanchor->from.col());
            // printf("row:\t%d\t",cellanchor->from.row());

            // printf("col:\t%d\t",cellanchor->to.colOff());
            // printf("row:\t%d\n",cellanchor->to.rowOff());
        }
        return qBytes;
    }

    AbstractSheet *sheet;
    Workbook *workbook;
    QList<DrawingAnchor *> anchors;
};

} // namespace QXlsx

#endif // QXLSX_DRAWING_H
