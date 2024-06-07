#include <iostream>
#include<fstream>
using namespace std;

bool add(int n, int x[], int res)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += x[i];
    }
    if (sum == res)
    {
        return true;
    }
    return false;
}

bool sub(int n, int x[], int res)
{
    int sub = x[0];
    for (int i = 0; i < n; i++)
    {
        sub -= x[i];
        if (sub < 0)
        {
            sub *= -1;
        }
    }
    if (sub == res)
    {
        return true;
    }
    return false;
}

bool div(int n, int x[], int res)
{
    int d;
    for (int i = 0; i < n; i++)
    {
        d /= x[i];
    }
    if (d == res)
    {
        return true;
    }
    return false;
}

bool mul(int n, int x[], int res)
{
    int m;
    for (int i = 0; i < n; i++)
    {
        m *= x[i];
    }
    if (m == res)
    {
        return true;
    }
    return false;
}

bool calculate(int n, int x[], int res)
{
    char o[4] = { '+','-','*','/' };
    int ans = 0;
    if (n == 1)
    {
        if (res == x[0])
        {
            return true;
        }
    }
    if (add(n, x, res))
    {
        return true;
    }
    else if (sub(n, x, res))
    {
        return true;
    }
    else if (mul(n, x, res))
    {
        return true;
    }
    else if (div(n, x, res))
    {
        return true;
    }
    else
    {
        for (int i = 0;i < n;i++)
        {

        }
    }
}

int main()
{
    int n, i, res;
    char space;
    ifstream fin;
    fin.open("Input.txt");
    fin >> n;
    int arr[n];
    for (i = 0;i < n - 1;i++)
    {
        fin >> arr[i];
    }
    fin >> arr[i];
    fin >> res;
    int ans = calculate(n, arr, res);
    ofstream fout;
    fout.open("Output.txt");
    if (ans)
    {
        fout << "Success : " << res << "=" << res;
    }
    else
    {
        fout << "Fail : ";
        for (int i = 0;i < n;i++)
        {
            fout << arr[i] << " ";
        }
        fout << "can't make " << res;
    }
}