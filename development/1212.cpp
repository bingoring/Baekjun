int main(int argc, char *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string input;
    cin >> input;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '0')
        {
            if (i == 0)
                cout << '0';
            else
                cout << "000";
        }
        else if (input[i] == '1')
        {
            if (i == 0)
                cout << "1";
            else
                cout << "001";
        }
        else if (input[i] == '2')
        {
            if (i == 0)
                cout << "10";
            else
                cout << "010";
        }
        else if (input[i] == '3')
        {
            if (i == 0)
                cout << "11";
            else
                cout << "011";
        }
        else if (input[i] == '4')
            cout << "100";
        else if (input[i] == '5')
            cout << "101";
        else if (input[i] == '6')
            cout << "110";
        else if (input[i] == '7')
            cout << "111";
    }

    return 0;
}