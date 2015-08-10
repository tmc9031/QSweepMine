#ifndef OPTIONDIALOG_H
#define OPTIONDIALOG_H

#include <QDialog>

#include <QIntValidator>

namespace Ui {
    class OptionDialog;
}

//自定义对话框
class OptionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OptionDialog(int w,int h,int m,QWidget *parent = 0);
    ~OptionDialog();

public Q_SLOTS:

    virtual void accept();
//    virtual void reject();

public:
    int m_width;
    int m_height;
    int m_mine;
private:
    Ui::OptionDialog *ui;
    QIntValidator m_validator;
};

#endif // OPTIONDIALOG_H
