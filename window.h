#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QProgressBar>
#include <QSlider>
#include <QChronoTimer>
#include <QLabel>
#include <QString>

class QPushButton; 
class Window : public QWidget {
    Q_OBJECT
    public: 
        explicit Window(QWidget *parent = 0, int timeSlot = 100); 
        void init();
    private: 
        QPushButton *m_button;
        QProgressBar *progressBar;
        QSlider *slider;
        QChronoTimer *timer;
        QLabel *label;
        bool breakTime; 
        int progress; 
        int max = 100; // in seconds
        void finish();
        signals: 
            void progression(int value);  
        public slots:
            void start(); 
};
#endif
