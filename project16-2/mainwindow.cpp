#include <QtGui>
#include "mainwindow.h"
#include <cmath>

int bitsCount = 8;

MainWindow::MainWindow() {
	setWindowTitle(tr("Bits v0.2"));
	setFixedSize(900, 500);
	setStyleSheet("background-color: black;");
	
	rectW = 50;
	rectH = 50;
	rectStartW = 10;
	rectStartH = 50;

    for(int i = 0; i < bitsCount; i++) {
    	bitLabel[i] = new QLabel(this);
		bitLabel[i]->setGeometry(rectStartW + rectW * bitsCount + 10, rectStartH + i * rectH, 400, rectH);
		bitLabel[i]->setFont(QFont("Courier", 20, QFont::Bold));
		bitLabel[i]->setText( "0" );
		bitLabel[i]->setStyleSheet("color: white;");
    }

    for(int i = 0; i < bitsCount; i++)
    	for(int j = 0; j < bitsCount; j++)
    		bit[i][j] = 0;

}

void MainWindow::paintEvent( QPaintEvent * ) {
	QPainter p(this);
	p.setPen(QPen(Qt::white));

	for(int i = 0; i < bitsCount; i++) {
		for(int j = 0; j < bitsCount; j++) {
	    	(bit[i][j] == 0) ? p.setBrush(QBrush(Qt::black)) : p.setBrush(QBrush(Qt::white));
	    	(bit[i][j] == 0) ? p.setPen(QPen(Qt::white)) : p.setPen(QPen(Qt::black));
	    	p.drawRect(rectStartW + rectW * i, rectStartH + rectH * j, rectW, rectH);
	    	bitLabel[i]->setText(QString::number(bitsToDec(i), 2) + " = 0x" + QString::number(bitsToDec(i), 16) + " = " + QString::number(bitsToDec(i)));
    	}
	}
}

int MainWindow::bitsToDec(int row) {
	int res = 0;
	for(int i = bitsCount - 1; i >= 0; i--) {
		res += pow(2, (bitsCount - (i + 1))) * bit[i][row];
	}
	return res;
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
	int x = event->x();
	int y = event->y();

	for(int i = 0; i < bitsCount; i++) {
		for(int j = 0; j < bitsCount; j++) {
			if( x > rectStartW + rectW * i && x < rectStartW + rectW * i + rectW && y > rectStartH + rectH * j && y < rectStartH + rectH * j + rectH ) {
				bit[i][j] = !bit[i][j];
			}
		}
	}

	update();
}