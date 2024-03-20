#include <iostream>
using namespace std;

enum ForeColour {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
};
void block(ForeColour colour)
{
    cout << "\x1b[" << colour << "m";
    int c = 5;
    for (int i = 1; i <= c; i++) 
    {
        for (int j = 1; j <= c; j++) 
        {
            if (i == 1 || i == c || j == 1 || j == c) cout << "*";
            else cout << " ";
        }
        cout << "\n";
    }
    cout << "\x1b[m";
}
int main()
{
    int a;
    cout << "화면에 그림을 그리는 프로그램입니다." << endl;
    cout << "학번 : 202127035" << endl;
    cout << "이름 : 주현호" << endl;
    cout << "\n";

    while (true)
    {
        cout << "화면에 그릴 물체코드를 입력하세요 : " << endl;
        cin >> a;
        if (a == 64) 
        {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        while (a > 0)
        {
            int b = a & -a;
            switch (b) 
            {
                case 1: 
                    block(White);
                    break;
                case 2: 
                    block(Red);
                    break;
                case 4: 
                    block(Green);
                    break;
                case 8: 
                    block(Yellow);
                    break;
                case 16: 
                    block(Cyan);
                    break;
                case 32: 
                    block(Magenta);
                    break;
                default:
                    break;
            }
            a-= b;
        }
    }
}
