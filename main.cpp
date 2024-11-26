#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include "window.h"

int main(int argc, char **argv){
    QApplication app (argc, argv); 

    Window window(0, 4); 
    window.show();
    window.init();


    return app.exec();
}
