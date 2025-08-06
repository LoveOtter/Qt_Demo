#ifndef LOVEMU_H
#define LOVEMU_H

#include <QWidget>

namespace Ui {
class Lovemu;
}

class Lovemu : public QWidget
{
    Q_OBJECT

public:
    explicit Lovemu(QWidget *parent = nullptr);
    ~Lovemu();

private:
    Ui::Lovemu *ui;
};

#endif // LOVEMU_H
