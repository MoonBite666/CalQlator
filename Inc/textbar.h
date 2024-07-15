

#ifndef TEXTBAR_H
#define TEXTBAR_H
#include <QWidget>
#include <QLineEdit>

class TextBar : public QWidget {
    Q_OBJECT
public:
    explicit TextBar(QWidget *parent = nullptr);
    ~TextBar() override;
    QLineEdit *lineEdit;

private slots:
    void textChanged(const QString &text);
};


#endif //TEXTBAR_H
