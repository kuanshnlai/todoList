#include<QCalendarWidget>
#ifndef CALENDAR_H
#define CALENDAR_H

class Calendar:public QCalendarWidget{
public:
protected:
void mousePressEvent(QMouseEvent* event);


};

#endif // CALENDAR_H
