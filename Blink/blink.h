#ifndef BLINK_H
#define BLINK_H

#include <QMainWindow>

namespace Ui {
class Blink;
}

class Blink : public QMainWindow
{
    Q_OBJECT

public:
    explicit Blink(QWidget *parent = 0);
    ~Blink();

private:
    Ui::Blink *ui;
};

#endif // BLINK_H

