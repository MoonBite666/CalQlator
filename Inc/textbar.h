

#ifndef TEXTBAR_H
#define TEXTBAR_H
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>

class TextBar : public QFrame {
    Q_OBJECT
public:
    explicit TextBar(QWidget *parent = nullptr);
    ~TextBar() override;
    QLineEdit *lineEdit;
    QLabel *resultLabel;

private slots:
    void changeResult(const QString &text) const;
};


#endif //TEXTBAR_H
