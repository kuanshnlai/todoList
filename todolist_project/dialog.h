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
    addEventDialog(){
        createLayout();
    }
    void createLayout();
    virtual ~addEventDialog(){
        delete layout;
        delete eventName;
        delete eventType;
        delete inputText;
        delete comboBox;
        delete buttonBox;
    }
private:
    QGridLayout *layout;
    QLabel *eventName;
    QLabel *eventType;
    QLineEdit *inputText;
    QComboBox *comboBox;
    QDialogButtonBox *buttonBox;
};

#endif // DIALOG_H
