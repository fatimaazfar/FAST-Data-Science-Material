/*#include <iostream>
#include <fstream>
using namespace std;

int main() 
{
  int row, column;
  ifstream fin;
  fin.open("text.txt");
  fin >> row >> column;
  //allocating
  int **arr = new int*[row];
  for(int i = 0;i < row;i++)
  {
    arr[i] = new int[column];
  }
  //inputting from file
  for(int i = 0;i < row;i++)
  {
    for(int j = 0;j < column;j++)
    {
      fin >> arr[i][j];
    }
  }
  fin.close();
  //outputting on console
  int largest = arr[0][0],smallest = arr[0][0];
  for(int i = 0;i < row;i++)
  {
    for(int j = 0;j < column;j++)
    {
      if(arr[i][j] > largest)
      {
        largest = arr[i][j];
      }
      if(arr[i][j] < smallest)
      {
        smallest = arr[i][j];
      }
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  
  cout << "Largest value is : " << largest << endl;
  cout << "Smallest value is : " << smallest << endl;

  //deallocating
  for(int i = 0;i < row;i++)
  {
    delete[] arr[i];
  }
  delete[] arr;
}*/

#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
    HANDLE hIn;
    HANDLE hOut;
    COORD KeyWhere;
    COORD MouseWhere;
    COORD EndWhere;
    bool Continue = TRUE;
    int KeyEvents = 0;
    int MouseEvents = 0;
    INPUT_RECORD InRec;
    DWORD NumRead;

    hIn = GetStdHandle(STD_INPUT_HANDLE);
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << "Key Events   : " << endl;
    cout << "Mouse Events : " << flush;

    KeyWhere.X = 15;
    KeyWhere.Y = 0;
    MouseWhere.X = 15;
    MouseWhere.Y = 1;
    EndWhere.X = 0;
    EndWhere.Y = 3;

    while (Continue)
    {
        ReadConsoleInput(hIn,
                         &InRec,
                         1,
                         &NumRead);

        switch (InRec.EventType)
        {
        case KEY_EVENT:
            ++KeyEvents;
            SetConsoleCursorPosition(hOut,
                                     KeyWhere);
            cout << KeyEvents << flush;
            if (InRec.Event.KeyEvent.uChar.AsciiChar == 'x')
            {
                SetConsoleCursorPosition(hOut,
                                         EndWhere);
                cout << "Exiting..." << endl;
                Continue = FALSE;
            }
            break;

        case MOUSE_EVENT:
            ++MouseEvents;
            SetConsoleCursorPosition(hOut,
                                     MouseWhere);
            cout << MouseEvents << flush;
            break;
        }
    }

    return 0;
}
