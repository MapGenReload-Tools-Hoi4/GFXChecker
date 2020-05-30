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




  /*----------------------------------------------------------*/
  //                        Main Section                      //
  /*----------------------------------------------------------*/

#include "startwindow.h"
#include "ui_startwindow.h"

Startwindow::Startwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Startwindow)
{
    ui->setupUi(this);
}

Startwindow::~Startwindow()
{
    delete ui;
}
  /*----------------------------------------------------------*/








  /*----------------------------------------------------------*/
  //                 Свободное движение окна                  //
  /*----------------------------------------------------------*/
void Startwindow::mousePressEvent(QMouseEvent *event) {
    m_nMouseClick_X_Coordinate = event->x();
    m_nMouseClick_Y_Coordinate = event->y();
}
void Startwindow::mouseMoveEvent(QMouseEvent *event) {
    move(event->globalX()-m_nMouseClick_X_Coordinate,event->globalY()-m_nMouseClick_Y_Coordinate);
}
  /*----------------------------------------------------------*/




  /*----------------------------------------------------------*/
  //                 Проверка на наличие файла                //
  /*----------------------------------------------------------*/
void checking_for_absence(QString file_path){

    QString paths=QGuiApplication::applicationDirPath();
    QFile file_set(paths + file_path);
    file_set.open(QIODevice::WriteOnly);
    file_set.close();
}

  /*----------------------------------------------------------*/





  /*----------------------------------------------------------*/
  //                Сохранение папки с файлами                //
  /*----------------------------------------------------------*/
void Startwindow::on_path_index_clicked()
{
    str_patch_index = QFileDialog::getExistingDirectory(0, "Выбрать путь к папке c .dds and .tga файлами...", "");
    str_patch_index_old = str_patch_index;
    //str_patch_index.replace("/","//");
    ui->lineEdit_index->setText(str_patch_index);
}
// сохранение папки с файлами end; //



  /*----------------------------------------------------------*/
  //                  Сохранение файла(.gfx)                  //
  /*----------------------------------------------------------*/
void Startwindow::on_radioButton_clicked()
{
    if (redact == 1) { redact = 0; }
    else { redact = 1; }
}


void Startwindow::on_path_save_clicked()
{
    str_patch_save = QFileDialog::getOpenFileName(0, "Выбрать путь к файлу...", "" , "*.gfx");
    str_patch_save_old = str_patch_save;
    //str_patch_save .replace("/","//");
    ui->lineEdit_save->setText(str_patch_save);
}
  // сохранение файла end; //




  /*----------------------------------------------------------*/
  //                  Кнопка вызова помощи(FAQ)               //
  /*----------------------------------------------------------*/
void Startwindow::on_faq_button_clicked()
{
  QMessageBox::information(this,"","","");
}
  // Кнопка вызова помощи(FAQ) end; //


  /*----------------------------------------------------------*/
  //                  Кнопка предложить перевод!              //
  /*----------------------------------------------------------*/
void Startwindow::on_help_local_clicked()
{
    QDesktopServices::openUrl(QUrl("https://"));
}
  // Кнопка предложения перевода end; //




  /*----------------------------------------------------------*/
  //                       Кнопка доната                      //
  /*----------------------------------------------------------*/
void Startwindow::on_donate_button_clicked()
{
    //QDesktopServices::openUrl(QUrl("https://"));
    //QDesktopServices::openUrl(QUrl("https://"));
    //QDesktopServices::openUrl(QUrl("https://"));
}
  // Кнопка доната end; //


  /*----------------------------------------------------------*/
  //                      Автор программы                     //
  /*----------------------------------------------------------*/
void Startwindow::on_author_program_button_clicked()
{
    QMessageBox::information(this,"О авторе...."," Разработал Sepera_okeq\n Главный Разработчик мода Discord Server's Mod\n\n Группа мода разработчика: https://vk.com/serversdiscordmodhoi4\n\n\n(MIT)\n Для пожертвований :\n Qiwi :\n \n Cвязаться со мной: \n Discord: Sepera_okeq#5009\n Группа ВК - Написать сообщение - пометка#GFXChecker \n\n Официальный git(свежие версии): https://github.com/HOI4-tools/Country-HOI4-Generator\n\n\n                  Версия программы : beta 1.1 \n\t      Год выпуска :   2020 год");
}
  // Автор программы end;//



  //############################################################//
  //#                                                          #//
  //#                                                          #//
  //#                     Запуск программмы                    #//
  //#                                                          #//
  //#                                                          #//
  //############################################################//

void Startwindow::on_start_program_clicked()
{

    /**///---------------------------------------------------///**/
    /**/  QString paths=QGuiApplication::applicationDirPath(); /**/
    /**/    //получаем путь,где лежит .exe файл программы//    /**/
    /**///---------------------------------------------------///**/





    /*----------------------------------------------------------*/
    //            Получаем весь список папок в папке.           //
    /*----------------------------------------------------------*/

    qDebug() << " ";
    qDebug() << "####################";
    qDebug() << "    Folder List    ";
    qDebug() << "####################";
    qDebug() << " ";

    QDir dir(str_patch_index_old);
    bool ok = dir.exists();
    int chets_real = 1;
    int chets_tech = 0;
    if (ok)
    {
        dir.setFilter(QDir::NoDotAndDotDot | QDir::Dirs );
        dir.setSorting(QDir::Name);
        QFileInfoList list = dir.entryInfoList();

        for (int i = 0; i < list.size(); ++i)
        {
            ++chets_real;
            ++chets_tech;
            QFileInfo fileInfo = list.at(i);
            data_folder[i]=fileInfo.fileName();

            QString debug_num = "0";
            debug_num = QString::number(i);

          qDebug() << " - #" + debug_num  + " Folder:" + data_folder[i];
        }
    }
    /*----------------------------------------------------------*/



    /*----------------------------------------------------------*/
    //            Получаем весь список файлов в папке.          //
    /*----------------------------------------------------------*/
    int chets_real_2 = 1;
    int chets_tech_2 = 0;

    qDebug() << " ";
    qDebug() << "################";
    qDebug() << "   Files List   ";
    qDebug() << "################";
    qDebug() << " ";

   // Debug start folder (h/h)
   /* QDir dir_start(str_patch_index_old);
    bool ok_start = dir_start.exists();
    if (ok_start)
    {
       dir_start.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
       dir_start.setSorting(QDir::Name);
        QFileInfoList list_start = dir_start.entryInfoList();

        for (int i = 0; i < list_start.size(); ++i)
        {
            QFileInfo fileInfo = list_start.at(i);
            data_files[i]=fileInfo.fileName();

            QString debug_num = "0";
            debug_num = QString::number(i);

          qDebug() << "№" + debug_num  + " File:" + data_files[i];
        }
    } */
    // Debug start folder (h/h) end;

    int lvl = 0; // обр.массива

    for (int up = 0;up < chets_real; ++up){
        QDir dir1(str_patch_index_old + "/" + data_folder[up]);
        bool ok1 = dir1.exists();
        if (ok1)
        {
            QString qDebug_int = QString::number(up);

            qDebug() << " ";
            qDebug() << "#################################################";
            qDebug() << " #" + qDebug_int + " Folder: " + data_folder[up];
            qDebug() << "#################################################";
            qDebug() << " Filelist:";
            qDebug() << " ";
            dir1.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
            dir1.setSorting(QDir::Name);
            QFileInfoList list1 = dir1.entryInfoList();

            lvl = up;

            for (int i = 0; i < list1.size(); ++i)
            {
                ++index_files[up];
                ++chets_real_2;
                ++chets_tech_2;
                QFileInfo fileInfo = list1.at(i);
                data_files[i][lvl]=fileInfo.fileName();

                QString debug_num = "0",lvl_summ = "0";
                debug_num = QString::number(i+1);
                lvl_summ = QString::number(up);

              qDebug() << " - #" + debug_num  + " File:" + data_files[i][lvl];
            }
              qDebug() << " #" + data_folder[up] + " End Floder";
              qDebug() << "\n\n";

        }
    }
    /*----------------------------------------------------------*/



    /*----------------------------------------------------------*/
    //                                                          //
    //                          JSON                            //
    //                                                          //
    /*----------------------------------------------------------*/

    // Json - путь к папке для чека
    patch_index.insert("patch_index",str_patch_index);
    patch_index.insert("patch_index_tech",str_patch_index_old);
    patch_index.insert("type",0);
    patch_index.insert("error",false);

    // Json - файл для сохранения
    patch_save.insert("patch_save",str_patch_save);
    patch_save.insert("patch_save_tech",str_patch_save_old);
    patch_save.insert("type",0);
    patch_save.insert("error",false);

    // Json - тех.конфигуация
    chet.insert("data_score_real_folder",chets_real);
    chet.insert("data_score_tech_folder",chets_tech);
    chet.insert("data_score_real_files",chets_real_2);
    chet.insert("data_score_tech_files",chets_tech_2);
    chet.insert("type",0);
    chet.insert("error",false);

    /*----------------------------------------------------------*/
    //                       cache json                         //
    /*----------------------------------------------------------*/

    //folders
    QJsonDocument data_json_folder;
    //QJsonArray db_folder;
    QJsonObject save_data_folder;
    QJsonObject name_editor_folder;


    //files
    QJsonDocument data_json;
    QJsonArray db;
    QJsonObject save_data;
    QJsonObject name_editor;



    // цикл для папок
    for (int o = 0; o < chets_tech_2; ++o){
        // цикл для файлов в папке

         QString folder_summ = QString::number(o);

            if(data_folder[o]!=""){

                save_data_folder.insert("folder",data_folder[o]);

                name_editor_folder[folder_summ] = save_data_folder;

                data_json_folder.setObject(name_editor_folder);
                checking_for_absence("/cache/folders.json");
                saveJson(data_json_folder,paths + "/cache/folders.json");

            }






        for (int o1 = 0; o1 < index_files[o]; ++o1){

            //сохраняем файлы и папку и номер
            save_data.insert("files",data_files[o1][o]);
            save_data.insert("folder",data_folder[o]);
            save_data.insert("int",o1+1);

            QString files_summ = QString::number(o1);

            //сохраняем в .json файл
            name_editor [folder_summ + " : " + files_summ] = save_data;
            db.append(name_editor);
            data_json.setObject(name_editor);
            checking_for_absence("/cache/cache.json");
            saveJson(data_json,paths + "/cache/cache.json");
            qDebug() << name_editor;
        }
    };

    // QJsonObject save_data_int;
    // checking_for_absence("/cache/cache.json");
    // saveJson(data_json,paths + "/cache/cache.json");
/*
      for (int i = 0; i < chets_tech_2; ++i){

       QJsonDocument data_json;

       QJsonObject save_data_int;
       QJsonObject save_data;


       save_data.insert("data",data_files[i][lvl]);
       save_data.insert("int",i+1);

       QString chetchik = "0";
       chetchik = QString::number(i);
       save_data_int.insert("data" + chetchik,save_data);

       data_json.setObject(save_data_int);

       chetchik = chetchik + 1;

       checking_for_absence("/cache/data" + chetchik + ".json");
       saveJson(data_json,paths + "/cache/" + "data" + chetchik + ".json");

       эта хуйня не работает,пофиксить кэширование в 1 файл все данные.

       ###P.S = ( теперь работает) (удалить этот код)###

       save_data.insert("error",0);
*/


    // ввод данных в массив для дальшей записи в файл с .json
    QJsonArray global_data;
    global_data.append(patch_index);
    global_data.append(patch_save);
    global_data.append(chet);


    // запись в файл.
    QJsonDocument json;
    json.setArray(global_data);
    checking_for_absence("/settings/settings.json");
    saveJson(json,paths + "/settings/settings.json");
    // Json end;

}

//end program;

// редактор
void Startwindow::on_checkBox_clicked()
{

}
