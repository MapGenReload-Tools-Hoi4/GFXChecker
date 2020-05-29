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
    str_patch_index.replace("/","//");
    ui->lineEdit_index->setText(str_patch_index);
}
// сохранение папки с файлами end; //



/*----------------------------------------------------------*/
//                  Сохранение файла(.gfx)                  //
/*----------------------------------------------------------*/
void Startwindow::on_path_save_clicked()
{
    str_patch_save = QFileDialog::getOpenFileName(0, "Выбрать путь к файлу...", "" , "gfx");
    str_patch_save_old = str_patch_save;
    str_patch_save .replace("/","//");
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

    /*----------------------------------------------------------*/
     QString paths=QGuiApplication::applicationDirPath();
    //получаем путь,где лежит .exe файл программы.
    /*----------------------------------------------------------*/





     /*----------------------------------------------------------*/
     //            Получаем весь список папок в папке.           //
     /*----------------------------------------------------------*/
    QString line="";
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
            line+=fileInfo.fileName()+"\n";
            data[i]=fileInfo.fileName();
        }
    }
    /*----------------------------------------------------------*/



    /*----------------------------------------------------------*/
    //            Получаем весь список файлов в папке.          //
    /*----------------------------------------------------------*/
    for (int up = 0;up < chets_tech; ++up){
        QString line1="";
        QDir dir1(str_patch_index_old +"/" + data[0]);
        bool ok1 = dir1.exists();
        if (ok1)
        {
            dir1.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
            dir1.setSorting(QDir::Name);
            QFileInfoList list = dir1.entryInfoList();

            for (int i = 0; i < list.size(); ++i)
            {
                QFileInfo fileInfo = list.at(i);
                line+=fileInfo.fileName()+"\n";

                ui->lineEdit_save->setText(line);
            }
        }
    }
    /*----------------------------------------------------------*/



    /*----------------------------------------------------------*/
    //                                                          //
    //                          JSON                            //
    //                                                          //
    /*----------------------------------------------------------*/

    // Json - индексирование папок
    patch_index.insert("patch_index",str_patch_index);
    patch_index.insert("patch_index_tech",str_patch_index_old);
    patch_index.insert("type",0);
    patch_index.insert("error",false);

    // Json - индексирование файла для сохранения
    patch_save.insert("patch_save",str_patch_save);
    patch_save.insert("patch_save_tech",str_patch_save_old);
    patch_save.insert("type",0);
    patch_save.insert("error",false);

    // Json - тех.конфигуация
    chet.insert("data_score_real",chets_real);
    chet.insert("data_score_tech",chets_tech);
    chet.insert("type",0);
    chet.insert("error",false);

    // cache json
    for (int i = 0; i < chets_tech; ++i){

       QJsonDocument data_json;

       QJsonObject save_data_int;
       QJsonObject save_data;

       save_data.insert("data",data[i]);
       save_data.insert("int",i+1);

       QString chetchik = "0";
       chetchik = QString::number(i);
       save_data_int.insert("data" + chetchik,save_data);

       data_json.setObject(save_data_int);

       checking_for_absence("/cache/data.json");
       saveJson(data_json,paths + "/cache/" + "data" + ".json");


      // save_data.insert("error",0);
    }


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
