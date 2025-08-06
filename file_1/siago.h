#ifndef SIAGO_H
#define SIAGO_H

#include <QWidget>

namespace Ui {
class siago;
}

class siago : public QWidget
{
    Q_OBJECT

public:
    explicit siago(QWidget *parent = nullptr);
    ~siago();

private:
    Ui::siago *ui;
};

#endif // SIAGO_H
