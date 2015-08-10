#include "optiondialog.h"
#include "ui_optiondialog.h"

#include <QMessageBox>

OptionDialog::OptionDialog(int w,int h,int m,QWidget *parent) :
    QDialog(parent),
    m_width(w),
    m_height(h),
    m_mine(m),
    ui(new Ui::OptionDialog),
    m_validator(1,100,this)
{
    ui->setupUi(this);

    QString txt;

    ui->widthEdit->setText(txt.setNum(m_width));
    ui->heightEdit->setText(txt.setNum(m_height));
    ui->mineEdit->setText(txt.setNum(m_mine));

    ui->widthEdit->setValidator(&m_validator);
    ui->heightEdit->setValidator(&m_validator);
    ui->mineEdit->setValidator(&m_validator);
}

OptionDialog::~OptionDialog()
{
    delete ui;
}

void OptionDialog::accept()
{
    m_width = ui->widthEdit->text().toInt();
    m_height = ui->heightEdit->text().toInt();
    m_mine = ui->mineEdit->text().toInt();

    if(m_mine < m_width*m_height)
        QDialog::accept();
    else
        QMessageBox::information(this,"customize","mine too much!",QMessageBox::Ok);
    //this¿ÉÌîNULL
}
