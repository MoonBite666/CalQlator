
#include "calculate.h"

int priority(QChar op) {
    switch(op.unicode()) {
        case u'+':
        case u'-':
            return 1;
        case u'×':
        case u'÷':
            return 2;
        default:
            return 0;
    }
}

QString solve(const QString &input) {
    QStack<QString> NPR;
    QStack<QChar> operators;
    QString crtNumber;

    for(QChar ch : input) {
        if(ch.isDigit() || ch == '.') {
            crtNumber += ch;
        }
        else // end of a number
            {
            if(!crtNumber.isEmpty()) {
                NPR.push(crtNumber);
                crtNumber.clear();
            }
            // begin of an operator
            switch (ch.unicode()) {
                case u'(':
                    operators.push(ch);
                    break;
                case u'×':
                case u'÷':
                case u'+':
                case u'-':
                    if(priority(operators.top()) < priority(ch) ) {
                        NPR.push(operators.pop());
                    }
                    break;
                case u')':
                    do {
                        NPR.push(operators.pop());
                    }while(operators.top().unicode() != u'(');
                    operators.pop();
                    break;
                default:
                    break;

            }
        }
    }
    if(!crtNumber.isEmpty()) {
        NPR.append(crtNumber);
    }
    while(!operators.isEmpty()) {
        NPR.push(operators.pop());
    }

    QStack<QString> result;
    while(!NPR.isEmpty()) {
        QString crt = NPR.pop();
        if(crt[0].isDigit()) {
            result.push(crt);
        }
        else {
            double b = result.pop().toDouble();
            double a = result.pop().toDouble();
            double c;
            switch(crt[0].unicode()) {
                case u'+':
                    c = a + b;
                    break;
                case u'-':
                    c = a - b;
                    break;
                case u'×':
                    c = a * b;
                    break;
                case u'÷':
                    c = a / b;
                    break;
                default:
                    c = 0;
                    break;
            }
            result.push(QString::number(c));
        }
    }
    QDebug deb = qDebug();
    deb << result.top();




}
