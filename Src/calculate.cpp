
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
    QQueue<QString> NPR;
    QStack<QChar> operators;
    QString crtNumber;

    for(QChar ch : input) {
        if(ch.isDigit() || ch == '.') {
            crtNumber += ch;
        }
        else // end of a number
            {
            if(!crtNumber.isEmpty()) {
                NPR.append(crtNumber);
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
                    while(!operators.isEmpty() && priority(operators.top()) >= priority(ch)) {
                        NPR.append(operators.pop());
                    }
                    operators.push(ch);
                    break;
                case u')':
                    do {
                        NPR.append(operators.pop());
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
        NPR.append(operators.pop());
    }

    QStack<QString> result;
    while(!NPR.isEmpty()) {
        QString crt = NPR.dequeue();
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
    return result.pop();




}
