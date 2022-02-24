#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QCalendar>
#include <QStandardItemModel>
#include <QTableView>
#include "calendar.h"
#include "dialog.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void loadStyleSheet(const QString& file);
    void resizeEvent(QResizeEvent* event);
    void calendarDateChange();
    void createCalendar();
    void createDateInfo();
public slots:
        void testSlot();
private:
    int window_width,window_height;
    Ui::MainWindow *ui;
    QLabel* date;
    QPushButton* addButton;
    QPushButton* delButton;
    Calendar* calendar;
    QStandardItemModel* model;
    QTableView* view;
    void dateEditEvent();
    void addEvent(const QDate&,const QString&,const QString&);
    addEventDialog* dialog;
    //


};
#endif // MAINWINDOW_H
