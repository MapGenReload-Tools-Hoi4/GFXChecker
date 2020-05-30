#include "progress_window.h"
#include "ui_progress_window.h"
//#include "startwindow.h"

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

QString path_files=QGuiApplication::applicationDirPath();



/*
"spriteType = {"
"    name = "
"    texturefile = "
"}"
*/



int check = 0;

void progress_window::on_pushButton_run_clicked()
{

       QJsonDocument settings_progress = ReadJson("./settings/settings.json");
       QJsonDocument folders_progress = ReadJson("./cache/folders.json");
       QJsonDocument files_progress = ReadJson("./cache/files.json");

       QJsonArray settings = settings_progress.array();
       QJsonObject folders = folders_progress.object();
       QJsonObject files = files_progress.object();



        ui->label_main->setText("Процесс начат.....");
        ui->pushButton_run->hide();

        qDebug() << "\n\n\n\n\n\n\n\n";
        qDebug() << settings ;
        qDebug() << "\n\n\n\n\n\n\n\n";
        qDebug() << folders  ;
        qDebug() << "\n\n\n\n\n\n\n\n";
        qDebug() << files ;

}
