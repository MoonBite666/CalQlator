
#ifndef NUMPAD_H
#define NUMPAD_H

#include <QFrame>
#include "squarebutton.h"
#include <QGridLayout>
#include <QList>

#include "squarebutton.h"

class Numpad : public QFrame {
    Q_OBJECT
public:
    explicit Numpad(QWidget *parent = nullptr);
    ~Numpad() override;

    private slots:
    static void buttonClicked(const QString &text);
private:
    QList<SquareButton *> buttons;

};



#endif //NUMPAD_H
