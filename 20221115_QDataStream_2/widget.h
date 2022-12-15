#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QByteArray>

#pragma pack(1)
struct UDPPacker
{
    quint16 m_srcPort;
    quint16 m_dstPort;
    quint16 m_length;
    quint16 m_checksum;
    QByteArray m_data;

    friend QDataStream & operator<<(QDataStream & stream, const UDPPacker &udp);
    friend QDataStream & operator>>(QDataStream & stream, UDPPacker &udp);
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
    void on_pushButtonAddUDP_clicked();

    void on_pushButtonDelUDP_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonLoad_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
