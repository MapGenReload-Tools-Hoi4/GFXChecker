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

#include "progress.h"
#include "ui_progress.h"


#include <QTranslator>
#include <QLibraryInfo>
#include <QFileDialog>
#include <QMessageBox>
#include <QMouseEvent>
#include <QDesktopServices>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>

progress::progress(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::progress)
{
    ui->setupUi(this);
}

progress::~progress()
{
    delete ui;
}
QString data;


void readJson(QString fileName){
    QFile jsonFile(fileName);
    jsonFile.open(QFile::ReadOnly);

}
