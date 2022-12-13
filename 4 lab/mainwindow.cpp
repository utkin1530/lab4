#include <QTimer>
#include <QPushButton>

#include "mainwindow.h"

int GetRandomValue(int, int);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(300, 600);
    const int speed = 5;
    auto timer = new QTimer(this);
    timer->setInterval(400);
    connect(timer, &QTimer::timeout, this,
        [this, timer, speed] {
            auto btn = new QPushButton(this);
            btn->setStyleSheet("background-color:white;");
            static int x = 10;
            static int y = 10;
            auto txt = new QLabel("YOU LOSE!", this);
            txt->setGeometry(130, 100, 200, 200);

            btn->setGeometry(x = GetRandomValue(0, width() - 30), y = 0, 30, 30);
            auto tmr = new QTimer(btn);

            auto move = [btn, speed, txt, this, timer] {
                (btn)->setGeometry(btn->x(), btn->y() + speed, 30, 30);
                if (btn->y() >= this->height())
                {
                    this->setStyleSheet("background-color:red;");
                    txt->show();
                    timer->stop();
                }
                connect(btn, &QPushButton::clicked, this,
                    [btn, this] {
                        delete btn;
                    });
            };

            connect(tmr, &QTimer::timeout, btn, move);

            //tmr->setInterval(GetRandomValue(50, 150));
            tmr->setInterval(100);
            btn->show();
            tmr->start();

        });
    timer->setInterval(500);
    timer->start();
}

int GetRandomValue(int min, int max)
{
    return min + rand() % (max - min + 1);
}

MainWindow::~MainWindow()
{
}
