#include "window.h"
#include <chrono>
#include <QPushButton>
#include <QProgressBar>
#include <QChronoTimer>
#include <QLabel>
#include <QString>
#include <iostream>

Window::Window(QWidget *parent, int timeSlot) :
    QWidget(parent){
        setFixedSize(1200, 80); 

        progressBar = new QProgressBar(this); 
        this->max = timeSlot;
        progressBar->setRange(0, this->max);
        progressBar->setValue(0);
        progressBar->setGeometry(10, 10, 1200, 30);
        progressBar->setFormat("%vs");

        m_button = new QPushButton("Start", this);
        m_button->setGeometry(10, 10, 80, 30);


        label = new QLabel(this);
        label->setGeometry(400, 30, 800, 80);


        this->progress = 0;
        this->breakTime = false;

        timer = new QChronoTimer(std::chrono::seconds{1}, this); 

        std::cout << "the foregroundrole is : " <<  progressBar->foregroundRole() << std::endl;

    }


void Window::start() {
    if(this->progress == 0 ){
        progressBar->setStyleSheet("QProgressBar::chunk {background-color: blue; }");
    }
    if(this->progress<= this->max){
        this->progress += 1;  
        emit progression(this->progress);
        //progression();
        std::cout << "still in progress with " << this->progress << std::endl;
    } else {
        std::cout << "are we actually in this case" << std::endl;
        finish();
        breakTime = !breakTime; 
        this->progress = 0;
        if(breakTime){
            label->setText(QString("Take a break!"));
        }
        else {
            label->setText(QString("Time to Work"));
        }
        timer->stop();  
    } 
}

void Window::init(){
    //QObject::connect(slider, SIGNAL (valueChanged(int)), progressBar, SLOT (setValue(int))); 
    QObject::connect(m_button, &QPushButton::clicked, timer , &QChronoTimer::start); 
    QObject::connect(this, SIGNAL (progression(int)), progressBar, SLOT (setValue(int))); 
    QObject::connect(timer, &QChronoTimer::timeout, this, &Window::start); 
}

void Window::finish(){
    std::cout << "We are in the finish function boys"  << std::endl;
    progressBar->setStyleSheet("QProgressBar::chunk {background-color: red; }");
}
