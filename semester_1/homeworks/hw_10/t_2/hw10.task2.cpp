#include <iostream>
#include <cstring>
#include <cctype>

/* Состояния:
 * 0 - начало
 * 1 - знак числа
 * 2 - целая часть числа
 * 3 - точка
 * 4 - дробная часть
 * 5 - е или Е
 * 6 - знак экспоненты
 * 7 - экспонента
 * 8 - точка, если стоит в самом начале
 */

using namespace std;

bool isNumber(char num[])
{
    const int len = strlen(num);
    int state = 0;
    for (int i = 0; i < len; ++i)
        switch (state)
        {
            case 0: if (num[i] == '+' || num[i] == '-')
                        state = 1;
                    else if (isdigit(num[i]))
                        state = 2;
                    else if (num[i] == '.')
                        state = 8;
                    else
                        return false;
                    break;
            case 1: if (isdigit(num[i]))
                        state = 2;
                    else if (num[i] == '.')
                        state = 3;
                    else
                        return false;
                    break;
            case 2: if (isdigit(num[i]))
                        continue;
                    else if (num[i] == '.')
                        state = 3;
                    else if (num[i] == 'e' || num[i] == 'E')
                        state = 5;
                    else
                        return false;
                    break;
            case 3: if (isdigit(num[i]))
                        state = 4;
                    else if (num[i] == 'e' || num[i] == 'E')
                        state = 5;
                    else
                        return false;
                    break;
            case 4: if (isdigit(num[i]))
                        continue;
                    else if (num[i] == 'e' || num[i] == 'E')
                        state = 5;
                    else
                        return false;
                    break;
            case 5: if (isdigit(num[i]))
                        state = 7;
                    else if (num[i] == '-' || num[i] == '+')
                        state = 6;
                    else
                        return false;
                    break;
            case 6: if (isdigit(num[i]))
                        state = 7;
                    else
                        return false;
                    break;
            case 7: if (!isdigit(num[i]))
                        return false;
            case 8: if (isdigit(num[i]))
                        state = 4;
                    else
                        return false;
        }
    if (!(state == 5 || state == 8 || state == 1 || state == 6 || state == 0))
            return true;
    return false;
}

int main()
{
    clog << "The program checks if a typed string is a number\n"
         << "Type a string: " << endl;
    char number[50];
    cin >> number;
    if (isNumber(number))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}

