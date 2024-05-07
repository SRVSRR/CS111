#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>


using namespace std;

const int MAXINT = 10;
const int MININT = -10;

int readint()
{
    int x;
    cin >> x;

    while(cin.fail())
    {
        cin.clear();
        string notint;
        cin >> notint;
        cout << "Input " << notint << " is not an integer. Enter an integer.";
        cin >> x;
    }

    return x;
}

char signchar(int x)
{
    if(x >= 0)
    {
        return '+';
    }

    else
    {
        return '-';
    }
}

void random_pair(int &first, int &second)
{
    first = rand() % (MAXINT - MININT + 1) + MININT;
    second = rand() % (MAXINT - MININT + 1) + MININT;
}

bool check_linear(int guess, int answer, int &score)
{
    bool is_equal;

    if(guess == answer)
    {
        cout << "Great!\n\n";
        is_equal = true;
        score++;
        cout << "Your score is " << score << endl;
    }

    else
    {
        cout << "Oops! The solution was " << answer << ".\n\n";
        is_equal = false;
    }

    return is_equal;
}

bool check_quadratic(int &guess1, int &guess2, int answer1, int answer2, int &score)
{
    bool is_equal;

    if(guess1 == answer1 && guess2 == answer2 || guess2 == answer1 && guess1 == answer2)
    {
        cout << "Great!\n\n";
        is_equal = true;
        score++;
        cout << "Your score is " << score << endl;
    }

    else
    {
        cout << "Oops! The solutions were " << answer1 << " and " << answer2 << ".\n\n";
        is_equal = false;
    }

    return is_equal;   
}

int main()
{
    int a = 0;
    int b = 0;
    int x, y;
    int score = 0;
    int tries = 0;
    char reply;
    srand(time(0));
    cout << "***********************************\n";
    cout << "*        CS111 math tutor 2       *\n";
    cout << "***********************************\n\n";
    cout << "Enter 'L'' to try a linear  and 'Q' to try a quadratic equation.\nAny other key to quit.";
    cin >> reply;

    while(reply == 'L' || reply == 'Q')
    {
        tries++;// Update the number of tries
        random_pair(a, b); //Get random number here.

        if(reply == 'L')
        {
            int solution = -b; //Compute the solution
            int coeff_1  = a;  //Compute the coefficients in the equation
            int coeff_2  = a * b;
            cout << "\nWhat is the solution to\n";
            cout << coeff_1 << " x " << signchar(coeff_2) << " " << fabs(coeff_2) << " = 0\n";
            x = readint();

            if(check_linear(x, solution, score));
        }

        else
        {
            int solution1 = -a;//Compute the solutions
            int solution2 = -b;
            int coeff_1  = a + b; //Compute the coefficients in the equation
            int coeff_2  = a * b;
            cout << "\nWhat is a solution to\n";
            cout << "x^2 " << signchar(coeff_1) << " " << fabs(coeff_1) << " x "  << signchar(coeff_2) << " " << fabs(coeff_2) << " = 0\n"; //Use function to fix formatting.
            x = readint();
            y = readint();// Use function to validate

            if(check_quadratic(x,y, solution1, solution2, score));
            tries++;
        }

        cout << "Enter 'L'' to try a linear  and 'Q' to try a quadratic equation.\nAny other key to quit.";
        cin >> reply;
    }

    cout << "\nYour score is " << score << " correct out of " << tries << ".\n";
    system ("pause");
    return 0;
}
