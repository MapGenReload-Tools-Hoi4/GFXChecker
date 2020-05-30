#include "progress_window.h"
#include "ui_progress_window.h"
#include "startwindow.h"

progress_window::progress_window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::progress_window)
{
    ui->setupUi(this);
}

progress_window::~progress_window()
{
    delete ui;
}
/*



*/
QJsonDocument ReadJson(QString path){
    QFile jsonfile(path);
    jsonfile.open(QFile::ReadOnly);
    return QJsonDocument().fromJson(jsonfile.readAll());
}





