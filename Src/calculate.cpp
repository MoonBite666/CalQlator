
#include "calculate.h"

int priority(QChar op) {
    switch(op.unicode()) {
        case u'+':
        case u'-':
            return 1;
        case u'×':
        case u'÷':
        case u'*':
        case u'/':
            return 2;
        default:
            return 0;
    }
}

bool containOperator(const QString& text) {
    const auto op = text.unicode()->unicode();
    return (op == u'+' || op == u'-' || op == u'×' || op == u'÷' || op == u'*' || op == u'/');
}

QString solve(const QString &input) {
    QQueue<QString> NPR;
    QStack<QChar> operators;
    QString crtNumber;
    bool leftBracket = false;

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
                case u'（':
                    leftBracket = true;
                    operators.push(ch);
                    break;
                case u'×':
                case u'*':
                case u'÷':
                case u'/':
                case u'+':
                case u'-':
                    while(!operators.isEmpty() && priority(operators.top()) >= priority(ch)) {
                        NPR.append(operators.pop());
                    }
                    operators.push(ch);
                    break;
                case u')':
                case u'）':
                    if (leftBracket) {
                        do {
                            NPR.append(operators.pop());
                        } while (!operators.isEmpty() && operators.top().unicode() != u'(');
                        if(!operators.isEmpty()) operators.pop();
                        leftBracket = false;
                    }
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
        if(QString crt = NPR.dequeue(); crt[0].isDigit()) {
            result.push(crt);
        }
        else if(!containOperator(crt)) {
            return "NaN";
        }
        else if(result.size() >= 2){
            const double b = result.pop().toDouble();
            const double a = result.pop().toDouble();
            double c;
            switch(crt[0].unicode()) {
                case u'+':
                    c = a + b;
                    break;
                case u'-':
                    c = a - b;
                    break;
                case u'×':
                case u'*':
                    c = a * b;
                    break;
                case u'÷':
                case u'/':
                    c = a / b;
                    break;
                default:
                    continue;
            }
            result.push(QString::number(c));
        }
        else {
            break;
        }
    }

    return result.isEmpty() ? "0" : result.top();

}
