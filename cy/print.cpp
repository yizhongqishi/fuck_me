﻿#include "print.h"
#include <QPainter>

Print::Print(QWidget *parent) : QWidget(parent)
{
//    fortest();
}

void Print::setPoints(QList<double> x, QList<double> y, double Cx, double Cy) {
    points.clear();
    //QPoint p(Cx, Cy);
    //points.append(p);
    for (int i = 0; i< x.length(); ++i) {
        x[i] += Cx;
        y[i] += Cy;
        if (i > 1){
            QPoint p(x[i], y[i]);
            points.append(p);
        }
    } 
}

void Print::setPoints1(QList<double> x, QList<double> y, double Xs,double Ys){
    points.clear();
    QPoint p(Xs, Ys);
    for (int i = 0; i < x.length(); i++){
        x[i] += Xs;
        y[i] += Ys;
        if (i > 0){
            QPoint p(x[i],y[i]);
            points.append(p);
        }
    }
}


void Print::paintEvent(QPaintEvent *events){
    QPainter paint(this);
    paint.translate(width() / 2, height() / 2);
    paint.scale(1.5,-1.5);
    paint.setPen(QPen(Qt::black, height() / 600));
    paint.drawLine(-2000,0,2000,0);
    paint.drawLine(0,1500,0,-1500);
    paint.drawPolyline(points);
}

/*void Print::fortest() {
    QList<double> listx, listy;
    listx.append(10); listy.append(10);
    listx.append(210); listy.append(10);
    listx.append(210); listy.append(230);
    listx.append(10); listy.append(230);
    listx.append(10); listy.append(10);
    setPoints(listx, listy, 0, 0);
    show();
}*/
