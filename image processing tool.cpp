#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image1[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];
unsigned char image3[SIZE][SIZE];

void loadImage ();
void saveImage ();
void EnlargeImage(int n1, int n2, int m1, int m2);
void RotateImage180();
void RotateImage270();
void RotateImage90();
void InvertImage();
void Darken();
void Lighten();
void Merge();
void Shrink_quart(unsigned char imagesave[SIZE][SIZE],unsigned char imageget[SIZE][SIZE]);
void Detect_Image();
void GS2BW();
void Flip_Horizone();
void Flip_Vertical();
void shrinkToThird();


int main()
{   int x;
    loadImage();
    while(true){
        cout << "Please select a filter to apply or 0 to exit:\n1- Black & White Filter\n2- Invert Filter\n3- Merge Filter\n4- Flip Image\n5- Darken and Lighten Image\n6- Rotate Image\n7- Detect Image Edges\n8- Enlarge Image\n9- Shrink Image\n10- Save the image to a file \n11- Load another image\n0- Exit\nYour choice is: ";
        cin >> x;
        switch(x){
        case 1:
            GS2BW();
            break;
        case 2:
            InvertImage();
            break;
        case 3:
            cout << "Please enter name of image file to merge with: ";
            char imageFileName2[100];
            cin >> imageFileName2;
            strcat (imageFileName2, ".bmp");
            readGSBMP(imageFileName2, image2);
            Merge();
            break;
        case 4:
            cout << "\n1-Horizontally  \n2-Vertically\n\n";
            cin >> x;
            switch(x){
            case 1:
                Flip_Horizone();
                break;
            case 2 :
                Flip_Vertical();
                break;
            }
            break;
        case 5:
            cout << "\n1-Darken  \n2-Lighten\n";
            cin >> x;
            switch(x){
            case 1:
                Darken();
                break;
            case 2 :
                Lighten();
                break;
            }
            break;
        case 6:
            cout << "Rotate 1-(90) 2-(180) 3-(270) degrees: ";
            cin >> x;
            switch(x){
            case 1:
                RotateImage90();
                break;
            case 2:
                RotateImage180();
                break;
            case 3:
                RotateImage270();
                break;
            }
            break;
        case 7:
            GS2BW();
            Detect_Image();
            break;
        case 8:
            cout << "Which quarter to enlarge 1, 2, 3 or 4: ";
            cin >> x;
            switch(x){
            case 1:
                EnlargeImage(0, SIZE/2, 0, SIZE/2);
                break;
            case 2:
                EnlargeImage(0, SIZE/2, SIZE/2, SIZE);
                break;
            case 3:
                EnlargeImage(SIZE/2, SIZE, 0, SIZE/2);
                break;
            case 4:
                EnlargeImage(SIZE/2, SIZE, SIZE/2, SIZE);
                break;
            }
            break;
        case 9:
            cout << "Shrink to 1-(1/2) 2-(1/3) 3-(1/4): ";
            cin >> x;
            switch(x){
            case 1:
                Shrink_quart(image3, image1);
                break;
            case 2:
                shrinkToThird();
                break;
            case 3:
                Shrink_quart(image2, image1);
                Shrink_quart(image3, image2);
                break;
            }
            break;
        case 10:
            saveImage();
            break;
        case 11:
            loadImage();
            break;
        case 0:
            return 0;
            break;
        }

    }

}

void loadImage (){
    char imageFileName[100];
    cout << "Ahlan ya user ya 7abibiii XD \nEnter the source image file name: ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image1);
}

//_________________________________________
void saveImage (){
    char imageFileName[100];
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image3);
}


void GS2BW(){
    long long sum = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            sum += (int)image1[i][j] ;

    sum = sum/(SIZE*SIZE);

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if (image1[i][j] > sum)
                image3[i][j] = (char)255;
            if(image1[i][j] <= sum)
                image3[i][j] = (char)0;
        }
    }

}

void InvertImage(){
    for (int i=0; i<SIZE; ++i)
        for (int j = 0; j <SIZE; ++j)
            image3[i][j] = 255-image1[i][j];
}
void Merge(){
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j< SIZE; j++)
            image3[i][j] = (image1[i][j]+image2[i][j])/2;
}

void Flip_Horizone(){
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            image3[SIZE - i][j] = image1[i][j];
}

void Flip_Vertical(){
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            image3[i][SIZE - j] = image1[i][j];
}

void RotateImage90(){
    for (int i=0; i<SIZE; ++i)
        for (int j = 0; j <SIZE; ++j)
            image3[j][SIZE-i] = image1[i][j];
}

void RotateImage180(){
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            image3[SIZE - i][SIZE - j] = image1[i][j];
}

void RotateImage270(){
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            image3[SIZE - j][i] = image1[i][j];

}

void Darken(){
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j< SIZE; j++)
            image3[i][j] = (image1[i][j])/2;
}

void Detect_Image(){
    for(int i = 0; i < SIZE; ++i){
        for(int j = 0; j < SIZE; ++j){
            if ((image3[i-1][j] != image3 [i+1][j])||(image3[i][j-1] != image3 [i][j+1]))
                image2[i][j] = char(255);
            else
                image2[i][j] = char(0);
        }
    }
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j< SIZE; j++)
            image3[i][j] = image2[i][j];
}

void EnlargeImage(int n1, int n2, int m1, int m2){
    int m = 0, n = 0; //zoom
    for (int i = n1; i < n2; i++){
        n = 0;
        for (int j = m1; j < m2 ; j++){
            image3[m][n]=image1[i][j];
            image3[m+1][n]=image1[i][j];
            image3[m][n+1]=image1[i][j];
            image3[m+1][n+1]=image1[i][j];
            n += 2;
        }
        m +=2;
    }
}

void Shrink_quart(unsigned char imagesave[SIZE][SIZE],unsigned char imageget[SIZE][SIZE]){
    int x = 0, y = 0;
    for (int i = 0; i < SIZE; i+=2){
        for (int j = 0; j< SIZE; j+=2){
            imagesave[x][y] = (imageget[i][j]+imageget[i][j+1]+imageget[i+1][j]+imageget[i+1][j+1])/4;
            ++y;
        }
        y = 0;
        ++x;
    }
}
void shrinkToThird()
{
    int x = 0, y = 0;
    for (int i = 0; i < SIZE - 1; i += 3)
    {
        y = 0;
        for (int j = 0; j < SIZE - 1; j += 3)
        {
            int avg = (image1[i][j] + image1[i + 1][j] + image1[i + 2][j] + image1[i][j + 1] + image1[i + 1][j + 1] +
                       image1[i + 2][j + 1]
                       + image1[i][j + 2] + image1[i + 1][j + 2] + image1[i + 2][j + 2]) / 9;
            image3[x][y] = avg;
            ++y;
        }
        ++x;
    }
}
void Lighten()
{
    /*long long sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            sum += (int)image1[i][j] ;
        }
    }
    sum = sum/(SIZE*SIZE);*/
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
        {
            //imageGS2[i][j] = char(imageGS[i][j]+SIZE/2);
           /* if (int(image1[i][j]+int (sum)) > SIZE)
                image2[i][j] = char(255);
            else
                image2[i][j] = char(image1[i][j]+(int)sum);*/
            if (image1[i][j] >= SIZE/2)
                image3[i][j] = char(255);
            else
                image3[i][j] = char(image1[i][j] + 0.5*image1[i][j]);
        }
}
