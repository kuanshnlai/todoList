#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QDialogButtonBox>
#ifndef DIALOG_H
#define DIALOG_H
class addEventDialog : QDialog{
    Q_OBJECT
public:
    using QDialog::QObject;
    addEventDialog(){
        initDialog();
    }
    void initDialog();
    void createLayout();
    void handleEvent();
    virtual ~addEventDialog(){
        delete layout;
        delete eventName;
        delete eventType;
        delete inputText;
        delete comboBox;
        delete buttonBox;
        qDebug()<<"destructor";
    }
    QString getType()const{return eventTypeValue;};
    QString getName()const{return eventNameValue;};
    int getState()const{return state;};
private:
    QGridLayout *layout;
    QLabel *eventName;
    QLabel *eventType;
    QLineEdit *inputText;
    QComboBox *comboBox;
    QDialogButtonBox *buttonBox;
    int state = 0;
    //store the input
    QString eventNameValue = "";
    QString eventTypeValue = "";
};

#endif // DIALOG_H
