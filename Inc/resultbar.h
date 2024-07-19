

#ifndef RESULTBAR_H
#define RESULTBAR_H

#include <QLabel>

class ResultBar : public QWidget {
    Q_OBJECT
public:
    explicit ResultBar(QWidget *parent = nullptr);
    ~ResultBar() override;
    QLabel *resultLabel;

private slots:
    static void textChanged(const QString &text);
};



#endif //RESULTBAR_H
