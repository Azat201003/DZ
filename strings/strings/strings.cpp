#include <iostream>
#include <string>

using namespace std;
void taskNumberOne(string);
void taskNumberTwo(string);
void taskNumberThree(string);
void taskNumberFour(string);
void taskNumberFive(string);
void taskNumberSix(string);

int getNumberOfOccurrences(string, char);

string enterText();
int main()
{
    setlocale(LC_ALL, "Russian");
    string line = enterText();
    taskNumberOne(line);
    cout << endl;
    taskNumberTwo(line);
    cout << endl;
    taskNumberThree(line);
    cout << endl;
    taskNumberFour(line);
    cout << endl;
    taskNumberFive(line);
    cout << endl;
    taskNumberSix(line);
}


void taskNumberOne(string line) {
    char endLine = line[line.size() - 1];

    cout << "кол-во вхождений символа \"" << endLine << "\" (включая конец) - " << getNumberOfOccurrences(line, endLine) << endl;
}


void taskNumberTwo(string line) {
    for (int index = 2; index < line.size(); index += 3) {
        cout << "Line[" << index << "] - \"" << line[index] << "\"" << endl;
    }
}


void taskNumberThree(string line) {
    char PLUS = '+', MINUS = '-', ZERO = '0';

    cout << "кол-во плюсов в строке - " << getNumberOfOccurrences(line, PLUS) << endl 
        << "кол-во минусов в строке - " << getNumberOfOccurrences(line, MINUS) << endl;

    int numberOfOccurrences = 0;
    for (int index = 0; index < line.size() - 1; index++) {
        if ((line[index] == PLUS || line[index] == MINUS) && line[index + 1] == ZERO) numberOfOccurrences++;
    }
    cout << "кол-во плюсов/минусов после которых идёт ноль в строке - " << numberOfOccurrences << endl;
}


void taskNumberFour(string line) {
    char X = 'x', W = 'w';
    int numberOfOccurrencesW = getNumberOfOccurrences(line, W);
    int numberOfOccurrencesX = getNumberOfOccurrences(line, X);

    if (numberOfOccurrencesW == 0) cout << "символа \"w\" в строке нет" << endl;
    if (numberOfOccurrencesX == 0) cout << "символа \"x\" в строке нет" << endl;

    for (int index = 0; index < line.size(); index++) {
        if (line[index] == W) {
            cout << "символа \"w\" в строке встречается раньше чем символ \"x\"" << endl;
            break;
        }
        if (line[index] == X) {
            cout << "символа \"x\" в строке встречается раньше чем символ \"w\"" << endl;
            break;
        }
    }
}


void taskNumberFive(string line1) {
    string line2 = enterText();
    int sizeOfLine1 = line1.size(), sizeOfLine2 = line2.size();

    if (sizeOfLine1 == sizeOfLine2) {
        cout << "строки равны";
    } else {
        if (sizeOfLine1 > sizeOfLine2) {
            cout << "первая строка больше на " << sizeOfLine1 - sizeOfLine2 << " символа" << endl;
            for (int i = 1; i <= sizeOfLine1 - sizeOfLine2; i++) {
                cout << line1 << endl;
            }
        } else {
            cout << "вторая строка больше на " << sizeOfLine2 - sizeOfLine1 << " символа" << endl;
            for (int i = 1; i <= sizeOfLine2 - sizeOfLine1; i++) {
                cout << line2 << endl;
            }
        }
    }
}


void taskNumberSix(string line) {
    string tmpLine, ABC = "abc";
    if (line.size() >= 3) {
        for (int i = 0; i < 3; i++) {
            if (!(line[i] == ABC[i])) {
                tmpLine = line + "zzz";
                break;
            } 
            if (i == 2) {
                tmpLine = line;
                for (int i = 0; i < 3; i++) {
                    tmpLine[i] = 'w';
                }
            }
        }
    }
    else {
        tmpLine = line;
        for (int i = 0; i < 3; i++) {
            tmpLine[i] = 'w';
        }
    }
    cout << "не знаю как это описать - \"" << tmpLine << "\"" << endl;
}
int getNumberOfOccurrences(string line, char symbol) {
    int numberOfOccurrences = 0;

    for (int index = 0; index < line.size(); index++) {
        if (line[index] == symbol) numberOfOccurrences++;
    }

    return numberOfOccurrences;
}

string enterText() {
    string line;
    cout << "строка - \"";
    getline(cin, line);
    system("cls");
    cout << "строка - \"" << line << "\"" << endl;
    return line;
}