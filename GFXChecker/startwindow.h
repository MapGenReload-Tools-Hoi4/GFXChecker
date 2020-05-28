/*____________________________________________________________
  Copyright 2020 Sepera_okeq or Sergey Leshkevich

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
  ____________________________________________________________*/

#ifndef STARTWINDOW_H
#define STARTWINDOW_H

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
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class Startwindow; }
QT_END_NAMESPACE

class Startwindow : public QMainWindow
{
    Q_OBJECT

public:
    Startwindow(QWidget *parent = nullptr);
    ~Startwindow();

    QString str_patch_index;
    QString str_patch_save;

    QString str_patch_index_old;
    QString str_patch_save_old;

    QJsonObject chet;
    QJsonObject patch_save;
    QJsonObject patch_index;

    QString data[1000];


    QString listdirsindir(QString path)
    {
        /*
        Функция считывает список директорий в директории в QString.
        Входные параметры:
         path - путь к папке.
        Возвращаемое значение:
         Строка со списком директорий в директории, разделенные n в алфавитном порядке.
        */
        QString line="";
        QDir dir(path);
        bool ok = dir.exists();
        if (ok)
        {
            dir.setFilter(QDir::NoDotAndDotDot | QDir::Dirs );
            dir.setSorting(QDir::Name);
            QFileInfoList list = dir.entryInfoList();

            for (int i = 0; i < list.size(); ++i)
            {
                QFileInfo fileInfo = list.at(i);
                line+=fileInfo.fileName()+"\n";
            }
        }
        return line;
    }

    QString listfilesindir(QString path)
    {
        /*
        Функция считывает список файлов (включая скрытые) в директории в QString.
        Входные параметры:
         path - путь к папке.
        Возвращаемое значение:
         Строка со списком файлов в директории, разделенные n в алфавитном порядке.
        */
        QString line="";
        QDir dir(path);
        bool ok = dir.exists();
        if (ok)
        {
            dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
            dir.setSorting(QDir::Name);
            QFileInfoList list = dir.entryInfoList();

            for (int i = 0; i < list.size(); ++i)
            {
                QFileInfo fileInfo = list.at(i);
                line+=fileInfo.fileName()+"\n";
            }
        }
        return line;
    }


    void saveJson(QJsonDocument settings,QString fileName) {
        QFile jsonFile(fileName);
        jsonFile.open(QFile::WriteOnly);
        jsonFile.write(settings.toJson());
    }

private:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    int m_nMouseClick_X_Coordinate;
    int m_nMouseClick_Y_Coordinate;

private slots:
    void on_path_index_clicked();

    void on_path_save_clicked();

    void on_faq_button_clicked();

    void on_help_local_clicked();

    void on_donate_button_clicked();

    void on_author_program_button_clicked();

    void on_start_program_clicked();

private:
    Ui::Startwindow *ui;
};
#endif // STARTWINDOW_H
