
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
    signals:
    void addText(const QString &text);

    private slots:
    void buttonClicked(const QString &text);
private:
    QList<SquareButton *> buttons;
    SquareButton* createButton(const QString &text);

};



#endif //NUMPAD_H
