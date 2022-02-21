#include "dialog.h"
#include <QDebug>
void addEventDialog::createLayout(){
    qDebug()<<"create layout";
    layout = new QGridLayout();
    eventName = new QLabel("event Name",this);
    eventType = new QLabel("event type",this);
    inputText = new QLineEdit();
    comboBox = new QComboBox();
    comboBox->addItems({"1","2","3","4","5"});
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok|QDialogButtonBox::Cancel);
    layout->addWidget(eventName,0,0,1,2);
    layout->addWidget(inputText,0,1,1,4);
    layout->addWidget(eventType,1,0,1,2);
    layout->addWidget(comboBox,1,1,1,4);
    layout->addWidget(buttonBox,3,0);
    this->setLayout(layout);
    connect(buttonBox,&QDialogButtonBox::accepted,this,&addEventDialog::accept);
    connect(buttonBox,&QDialogButtonBox::rejected,this,&addEventDialog::reject);
    int r = exec();
    if(r == QDialog::Accepted){
        qDebug()<<"accept";
    }
    qDebug()<<"create finish";
}



