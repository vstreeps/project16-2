#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

QT_BEGIN_NAMESPACE
 class QLabel;
 class QPainter;
QT_END_NAMESPACE

class MainWindow :public QMainWindow
{
	Q_OBJECT
	 public:
      MainWindow();
      int bitsToDec(int row);
     protected:
      void paintEvent (QPaintEvent *event);
      void mousePressEvent(QMouseEvent *event);
     private:
      QLabel *bitLabel[8];
      int bit[8][8];
      int rectW, rectH, rectStartW, rectStartH;  
};
#endif