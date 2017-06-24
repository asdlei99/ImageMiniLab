﻿#include "ImageCook.h"

#include <QFileDialog>
#include <QDebug>
#include <QPainter>
#include <QAction>
#include <QFile>

ImageCook::ImageCook(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    QFile qss(":/res/normal.qss");
    if (qss.open(QIODevice::ReadOnly))
    {
        qDebug() << qss.readAll();
        qss.close();
    }

    //旋转菜单
//    QAction* RotateRight90 = new QAction(this);
//    RotateRight90->setText("向右旋转90度");
//    QAction* RotateLeft90 = new QAction(this);
//    RotateLeft90->setText("向左旋转90度");
//    QMenu *pRotateMenu = new QMenu();
//    pRotateMenu->addAction(RotateRight90);
//    pRotateMenu->addAction(RotateLeft90);
//    connect(pRotateMenu, SIGNAL(triggered(QAction*)), this, SLOT(on_ActRotate(QAction*)));
//    ui.BtnRotate->setMenu(pRotateMenu);
    
    connect(this, SIGNAL(Sig_BasePix(QPixmap)), ui.ShowWidget, SLOT(On_SetBasePix(QPixmap)));
//    connect(this, SIGNAL(Sig_Rotate(int)), ui.ShowWidget, SLOT(On_SetRotate(int)));

}

void ImageCook::on_ActOpen_triggered()
{
	qDebug() << "on_actionopen_triggered";
    m_ImagePath = QFileDialog::getOpenFileName(this, tr("Open File"),
        "/",
		tr("Images (*.png *.xpm *.jpg)"));
    if (!m_ImagePath.isEmpty())
	{
        m_Pix.load(m_ImagePath);
        emit Sig_BasePix(m_Pix);
        //ui.LabShow->setPixmap(m_Pix);
	}
}

void ImageCook::on_ActClose_triggered()
{
	qDebug() << "on_actionclose_triggered";
    m_ImagePath.clear();
}

void ImageCook::on_ActSave_triggered()
{
    if (m_ImagePath.isEmpty())
    {
        ui.StatusBar->showMessage("未打开文件", 3000);

        return;
    }


}

void ImageCook::on_ActSaveAs_triggered()
{
    if (m_ImagePath.isEmpty())
    {
        ui.StatusBar->showMessage("未打开文件", 3000);

        return;
    }
}

//void ImageCook::on_ActRotate(QAction *act)
//{
//    if (act->text() == "向左旋转90度")
//    {
//        emit Sig_Rotate(90);
//    }
//    else if (act->text() == "向右旋转90度")
//    {
//        emit Sig_Rotate(-90);
//    }
//}

