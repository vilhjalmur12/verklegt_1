#ifndef ERRORWINDOW_H
#define ERRORWINDOW_H

#include <QWidget>

namespace Ui {
class errorwindow;
}

class errorwindow : public QWidget
{
    Q_OBJECT

public:
    explicit errorwindow(QWidget *parent = 0);
    ~errorwindow();
    void dataErrorFound ();
    void nonMatchPassword ();
    void userExists();
    void nonUserInput();
    bool confirmDeleteAll(bool OK);

private slots:
    void on_pushButton_cancel_clicked();

    void on_pushButton_ok_clicked();

private:
    Ui::errorwindow *ui;
    bool okDelete = false;
};

#endif // ERRORWINDOW_H
