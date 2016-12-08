#ifndef CHATCHILD_H
#define CHATCHILD_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QPlainTextEdit>
#include <QLineEdit>

namespace Ui {
class ChatChild;
}

class ChatChild : public QMdiSubWindow
{
    Q_OBJECT

public:
    explicit ChatChild(QWidget *parent = 0);
    ~ChatChild();

private:
    Ui::ChatChild *ui;
    QPlainTextEdit *chat;
    QLineEdit *message;
};

#endif // CHATCHILD_H
