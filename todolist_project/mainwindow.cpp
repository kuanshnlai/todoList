#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QCalendarWidget>
#include <QToolButton>
#include <QPushButton>
#include <iostream>
#include <QDir>
#include <QDebug>
#include <QListWidget>
#include <QFile>
#include "calendar.h"
#include <QLabel>
#include <QStandardItem>
#include <QWidget>
#include <QDialog>
#include <QComboBox>
#include <QLayout>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <windows.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    createCalendar();
    createDateInfo();
    this->loadStyleSheet(":/stylesheet/stylesheet.qss");
    connect(calendar,&Calendar::selectionChanged,this,&MainWindow::calendarDateChange);
    connect(addButton,&QPushButton::pressed,this,&MainWindow::dateEditEvent);
}
void MainWindow::createCalendar(){
    calendar = new Calendar();
    this->setGeometry(0,0,1000,700);
    window_width = this->width();
    window_height = this->height();
    calendar->setParent(this);
    calendar->setGeometry(0,0,800,700);
    calendar->setObjectName("qt_calendar");
}
void MainWindow::createDateInfo(){
    //----------------date info--------------------------

    date = new QLabel();
    date->setGeometry(800,0,200,30);
    QString str = calendar->selectedDate().toString("MMM dd");
    date->setText(str);
    date->setParent(this);
    model = new QStandardItemModel(0,2,this);
    view = new QTableView();
    model->setHorizontalHeaderItem(0,new QStandardItem(QString("Name")));
    model->setHorizontalHeaderItem(1,new QStandardItem(QString("Type")));
    for(int i=0;i<3;i++){
        QStandardItem *name = new QStandardItem(QString("%1").arg(i));
        QStandardItem *type = new QStandardItem(QString("%1").arg(i+5));
        int rowCount = model->rowCount();
        model->setItem(rowCount,0,name);
        model->setItem(rowCount,1,type);
    }
    view->setModel(model);
    view->setParent(this);
    view->setGeometry(800,30,200,640);

    //---------------add/delete event item----------------------
    addButton = new QPushButton("+");
    delButton = new QPushButton("-");
    addButton->setGeometry(950,670,25,30);
    addButton->setParent(this);
    delButton->setGeometry(975,670,25,30);
    delButton->setParent(this);

}
void MainWindow::loadStyleSheet(const QString &filename){
    QFile file = QFile(filename);
    file.open(QFile::ReadOnly);
    if(file.isOpen()){
        QString str = this->styleSheet();
        str += file.readAll();
        this->setStyleSheet(str);
    }
    else{
        qDebug()<<"Open file fail";

    }
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::resizeEvent(QResizeEvent* event){
    // bug 縮放比例怪改用fix size?
    float new_window_width = this->width();
    float new_window_height = this->height();
    float width_ratio = new_window_width/window_width;
    float height_ratio = new_window_height/window_height;
    window_width = this->width();
    window_height = this->height();
    auto children = this->findChildren<QWidget*>();
    for(auto &child:children){
        child->resize(child->width()*width_ratio,child->height()*height_ratio);
    }
//    calendar->resize(calendar->width()*width_ratio,calendar->height()*height_ratio);

    qDebug()<<width_ratio;
    qDebug()<<height_ratio;
    qDebug()<<"Size of calendar"<<calendar->size();
}
void MainWindow::calendarDateChange(){
    date->setText(calendar->selectedDate().toString("MMM dd"));
}
void MainWindow::dateEditEvent(){
    //create a popup window
    qDebug()<<"add button click";
    dialog = new addEventDialog();
    qDebug()<<"print something to see what happen";
    if(dialog->getState() == QDialog::Accepted){
        qDebug()<<"Event name is "<<dialog->getName();
        qDebug()<<"Event type is "<<dialog->getType();
        QString name = dialog->getName();
        QString type = dialog->getType();
        QDate date = calendar->selectedDate();
        addEvent(date,name,type);
    }
    delete dialog;
}
void MainWindow::testSlot(){
    qDebug()<<"trigger";
}
void MainWindow::addEvent(const QDate& date,const QString& name,const QString& type){
    qDebug()<<"date";
    QStandardItem *item1 = new QStandardItem(name);
    QStandardItem *item2 = new QStandardItem(type);
    int rowCount = model->rowCount();
    model->setItem(rowCount,0,item1);
    model->setItem(rowCount,1,item2);
    view->setModel(model);
}
