
#ifndef SQUAREBUTTON_H
#define SQUAREBUTTON_H

#include <QPushButton>
#include <QResizeEvent>

class SquareButton : public QPushButton {
    Q_OBJECT

public:
    explicit SquareButton(const QString &text, QWidget *parent = nullptr);

signals:
    void buttonClicked(const QString &text);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    // void resizeEvent(QResizeEvent *event) override;
};

#endif //SQUAREBUTTON_H
