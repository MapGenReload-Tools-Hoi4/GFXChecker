#ifndef PROGRESS_WINDOW_H
#define PROGRESS_WINDOW_H

#include <QDialog>
#include <QMainWindow>
#include <QTranslator>
#include <QLibraryInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QMouseEvent>
#include <QDesktopServices>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonValue>
#include <QDir>
#include <QFile>
#include <QDebug>

namespace Ui {
class progress_window;
}

class progress_window : public QDialog
{
    Q_OBJECT

public:
    explicit progress_window(QWidget *parent = nullptr);
    ~progress_window();

private slots:
    void on_pushButton_run_clicked();

private:
    Ui::progress_window *ui;
};

#endif // PROGRESS_WINDOW_H
