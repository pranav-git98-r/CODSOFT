#include <bits/stdc++.h>
using namespace std;

void displayBoard(const vector<char> &arr)
{
    cout << "\n|-----------|\n";
    cout << "| " << arr[0] << " | " << arr[1] << " | " << arr[2] << " |";
    cout << "\n|-----------|\n";
    cout << "| " << arr[3] << " | " << arr[4] << " | " << arr[5] << " |";
    cout << "\n|-----------|\n";
    cout << "| " << arr[6] << " | " << arr[7] << " | " << arr[8] << " |";
    cout << "\n|-----------|\n";
}
void turn(vector<char> &arr, char symbol)
{

    while (true)
    {
        int turnCount;
        cout << "Enter the place to put " << symbol << ":\n";
        cin >> turnCount;
        // This is to handle invalid inputs thus to increase overall reliability
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Invalid input. Please enter a valid number.\n";
            continue;
        }
        if (turnCount > 0 && turnCount <= 9 && arr[turnCount - 1] == ' ')
        {
            arr[turnCount - 1] = symbol;
            break;
        }
        else
        {
            cout << "Invalid place! Try another place." << endl;
        }
    }
    displayBoard(arr);
    cout<<endl;
}

bool wincheck(const vector<char> &arr)
{
    if ((arr[0] == arr[1] && arr[1] == arr[2] && arr[0] != ' ') ||
        (arr[3] == arr[4] && arr[4] == arr[5] && arr[3] != ' ') ||
        (arr[6] == arr[7] && arr[7] == arr[8] && arr[7] != ' ') ||
        (arr[0] == arr[3] && arr[3] == arr[6] && arr[0] != ' ') ||
        (arr[1] == arr[4] && arr[4] == arr[7] && arr[1] != ' ') ||
        (arr[2] == arr[5] && arr[5] == arr[8] && arr[2] != ' ') ||
        (arr[0] == arr[4] && arr[4] == arr[8] && arr[0] != ' ') ||
        (arr[2] == arr[4] && arr[4] == arr[6] && arr[2] != ' '))
    {
        return true;
    }
    else
        return false;
}
void newGame(vector<char> &arr)
{
    cout << "!-----------NEW GAME------------!" << endl;
    displayBoard(arr);
    cout<<endl;
    char player;
    for (int i = 1; i <= 9; i++)
    {
        if (i % 2 != 0)
        {
            player = 'X';
            turn(arr, player);
        }
        else
        {
            player = 'O';
            turn(arr, player);
        }
        if (wincheck(arr) == true)
        {
            cout << "player " << player << " has won" << endl;
            cout << "!-----------GAME OVER------------!" << endl;
            return;
        }
    }
    cout << "Its a draw!\n";
    cout << "!-----------GAME OVER------------!\n";
}
int main()
{
    vector<char> arr(9, ' ');
    newGame(arr);
    return 0;
}