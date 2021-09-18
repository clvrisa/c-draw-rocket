// Project 1
// Write a program that draws a rocket shape on the screen based on 
// user input of three values, height, width and stages

#include <iostream>
#include <iomanip>
using namespace std;

// list of function prototypes
void drawCone(); //prototype with no parameters
void drawEven(/*in*/int,/*in*/ int);
void drawOdd (/*in*/int,/*in*/ int);
void dimmensions (/*in*/int&, /*in*/int&);
void drawRocket (/*in*/int,/*in*/ int);

int main()
{
    //declare variables
    int height= 0 , width = 0, col, row;

    cout << "Draw a Rocket!" << endl;

    // function call with two arguments
    dimmensions(width, height);

    cout << endl;

    // function call with two arguments
    drawRocket(width, height);

    return 0;
}

//function prompt for user input of rocket dimmensions with validation
void dimmensions(/*in*/int& width, /*in*/int& height)
{
    //prompt for user input of width with validation of number between 4 and 15
    cout << "Please enter a number between 4 and 15 for width: " << endl;
    cin >> width;
    if (width < 4 || width > 15)
        {
            cout << "Invalid Input, Please Retry" << endl;
            cout << "Please enter a number between 4 and 15 for width: " << endl;
            cin >> width;
        }
    //prompt for user input of height with validation of number between 4 and 15
    cout << "Please enter a number between 4 and 15 for height: " << endl;
    cin >> height;
        if (height < 4 || height > 15)
        {
            cout << "Invalid Input, Please Retry" << endl;
            cout << "Please enter a number between 4 and 15 for height: " << endl;
            cin >> height;
        }
}

//function showing cone
void drawCone()
{
    cout << "  *  " << endl;
    cout << " * * " << endl;
    cout << "*   *" << endl;
}

//function used to generate a hollow box when dimensions are even
void drawEven(/*in*/int width,/*in*/ int height)
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            cout << '*';
        }
        cout << endl;
    }

    for (int row = 0; row < height -1; row++)
    {
        if (row == 0 || row == height - 1)
        {
            for (int col = 0; col < width; col++)
            {
                cout << '*';
            }
        }
        else
        {
            cout << '*';
            for (int col = 0; col < width - 2 ; col++)
            {
                cout << ' ';
            }
            cout << '*';
        }
    }

}

//function to generate filled box when dimensions are odd
void drawOdd(/*in*/int width,/*in*/ int height)
{
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            cout << '*';
        }
        cout << endl;
    }
}
//function to generate entire rocket with an algorithm to determine if dimensions are odd or even,
//therefor generating the proper filled or hollow shaped box for the rocket
void drawRocket(/*in*/int width,/*in*/ int height)
{
    if (height % 2 == 0)
        {
            drawCone();
            drawEven(width, height);
            drawEven (width, height);
            drawCone();
        }

    else
        {
            drawCone();
            drawOdd(width, height);
            drawOdd(width, height);
            drawCone();
        }
}
