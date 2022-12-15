#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#pragma pack(1)

struct BMPFileHeader
{
    quint16 bfType;
    quint32 bfSize;
    quint16 bfReserved1;
    quint16 bfReserved2;
    quint32 bfOffBits;
};

#pragma pack(1)
struct BMPInfoHeader
{
    quint32 biSize;
    quint32 biWidth;
    quint32 biHeight;
    quint16 biPlanes;
    quint16 biBitCount;
    quint32 biCompression;
    quint32 biSizeImage;
    quint32 biXPelsPerMeter;
    quint32 biYPelsPerMeter;
    quint32 biClrUsed;
    quint32 biClrImportant;
};

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButtonBrowse_clicked();

    void on_pushButtonShowPic_clicked();

    void on_pushButtonReadHeader_clicked();

    void on_lineEditName_textChanged(const QString &arg1);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
