#ifndef PROGRESS_WINDOW_H
#define PROGRESS_WINDOW_H

#include <QDialog>

namespace Ui {
class progress_window;
}

class progress_window : public QDialog
{
    Q_OBJECT

public:
    explicit progress_window(QWidget *parent = nullptr);
    ~progress_window();

private:
    Ui::progress_window *ui;
};

#endif // PROGRESS_WINDOW_H
