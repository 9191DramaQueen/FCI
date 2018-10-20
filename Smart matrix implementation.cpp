
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>

using namespace std;

/// A structure to store a matrix
struct matrix
{
  int** data;       /// Pointer to 2-D array that will simulate matrix
  int row, col;
};

/// Already implemented
void zero(int a[], int Size){
    for(int i = 0; i < Size; ++i){
        a[i] = 0;
    }
}
void createMatrix (int row, int col, int num[], matrix& mat);

matrix operator+  (matrix mat1, matrix mat2); /// Add if same dimensions DONE
matrix operator-  (matrix mat1, matrix mat2); /// Sub if same dimensions DONE
matrix operator*  (matrix mat1, matrix mat2); /// Multi if col1 == row2  DOnE
matrix operator+  (matrix mat1, int scalar);  /// Add a scalar           DONE
matrix operator-  (matrix mat1, int scalar);  /// Subtract a scalar      DONE
matrix operator*  (matrix mat1, int scalar);  /// Multiple by scalar     DONE


matrix operator+= (matrix& mat1, matrix mat2); /// mat1 changes & return new matrix with the sum        DONE
matrix operator-= (matrix& mat1, matrix mat2); /// mat1 changes + return new matrix with difference     notDONE
matrix operator+= (matrix& mat, int scalar);   /// change mat & return new matrix                       notDONE
matrix operator-= (matrix& mat, int scalar);   /// change mat & return new matrix                       notDONE
void   operator++ (matrix& mat);               /// Add 1 to each element ++mat                          DONE
void   operator-- (matrix& mat);    	       /// Sub 1 from each element --mat                        notDONE
istream& operator>> (istream& in, matrix& mat);/// Input matrix and return istream to allow cascading input DONE


ostream& operator<< (ostream& out, matrix mat); /// Print matrix and return ostream to cascade printing DONE
bool   operator== (matrix mat1, matrix mat2);	/// True if identical                                   DONE
bool   operator!= (matrix mat1, matrix mat2); 	/// True if not same                                    notDONE
bool   isSquare   (matrix mat);                 /// True if square matrix                               DONE
bool   isSymetric (matrix mat);                 /// True if square and symmetric                        DONE
bool   isIdentity (matrix mat);                 /// True if square and identity                         DONE
matrix transpose  (matrix mat);                 /// Return new matrix with the transpose                notDONE

//__________________________________________________________________________________________________________________________________________________________________________________________________________________

int main()
{
  int data1 [] = {1,2,3,4,5,6,7,8};
  int data2 [] = {13,233,3,4,5,6};
  int data3 [] = {10,100,10,100,10,100,10,100};

  matrix mat1, mat2, mat3,mat4;
  createMatrix (4, 2, data1, mat1);
  createMatrix (2, 3, data2, mat2);
  createMatrix (4, 2, data3, mat3);
  cin >> mat4;
  cout << "mat 1: \n" << mat1 << endl;
  cout << "mat 2: \n" << mat2 << endl;
  cout << "mat 3: \n" << mat3 << endl;

  cout << "mat1 + mat3 = \n" << (mat1 + mat3) << endl << endl;
  cout << "mat 3: \n" << mat3 << endl;
  cout << "mat3 + mat3 = \n" << (mat3 + mat3) << endl << endl;
  cout << "mat 3: \n" << mat3 << endl;

  cout << "++mat1 = \n";
  ++mat1;
  cout << mat1 << endl;

  mat1+= mat3 += mat3;
  cout << "mat 1: \n" << mat1 << endl;
  cout << "mat 2: \n" << mat2 << endl;
  cout << "mat 3: \n" << mat3 << endl;
  cout << "mat 4: \n" << mat4 << endl;
  // Add more examples of using matrix
  // .......

  return 0;
}_____________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat) {
  mat.row = row;
  mat.col = col;
  mat.data = new int* [row];

  for (int i = 0; i < row; i++)
    mat.data[i] = new int [col];

  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      mat.data[i][j] = num[i * col + j];
}
istream& operator>> (istream& in, matrix& mat){///Input The Matrix
    cout<<"row & cols :"<<endl;
    cin>>mat.row>>mat.col;
    mat.data = new int* [mat.row];

    for (int i = 0; i < mat.row; i++)
        mat.data[i] = new int [mat.col];

    cout<<"please enter the elements "<<endl;
    for(int i=0 ; i<mat.row ; i++)
    {
        for(int j=0 ; j<mat.col ; j++)
            in>>mat.data[i][j];
    }
    cout << "Matrix Created : \n" << mat << "-------\n";
    return in;
}
ostream& operator<< (ostream& out, matrix mat){///Print The Matrix
    for (int i=0; i<mat.row; i++){
        for(int j =0; j <mat.col; j++){
            out << mat.data[i][j] << ' ';
        }
        out << endl;
    }
    return out;
}
matrix operator+= (matrix& mat1, matrix mat2){///Add Mat2 To Mat1 and Put the Sum In Mat1 and return it
    if(mat1.row == mat2.row && mat1.col==mat2.col)
    {
        for(int i=0 ; i<mat1.row ; i++)
        {
            for(int j=0 ; j<mat1.col ; j++)
            {
                mat1.data[i][j]=mat1.data[i][j]+mat2.data[i][j];
            }
        }
    }
    else
        cout<<"Error , the 2 dims aren't equal"<<endl;
return mat1;
}
void operator++ (matrix& mat){ ///Add 1 To Each element in the matrix mat
    for(int i=0 ; i<mat.row ; i++)
    {
        for(int j=0 ; j<mat.col ; j++)
        {
            mat.data[i][j]=mat.data[i][j]+1;
        }
    }

}
bool   operator== (matrix mat1, matrix mat2){ ///Return True if The 2 Matrices identical
    if (mat1.row == mat2.row && mat1.col == mat2.col)
    {
        for(int i=0; i < mat1.row; i++)
        {
            for(int j=0; j < mat1.col; j++)
            {
                if(mat1.data[i][j] != mat2.data[i][j])
                {
                    return false;
                }
            }
        }

        return true;
    }
    else
        cout << "Error" <<endl;
}
bool   operator!= (matrix mat1, matrix mat2){ ///Return True if The 2 Matrices not same
    if (mat1.row == mat2.row && mat1.col == mat2.col)
    {
        for(int i=0; i < mat1.row; i++)
        {
            for(int j=0; j < mat1.col; j++)
            {
                if(mat1.data[i][j] != mat2.data[i][j])
                {
                    return true;
                }
            }
        }

        return false;
    }
    else
        cout << "Error" <<endl;
}
bool isSquare (matrix mat){ ///Checking if the number of rows equal the number of columns to the matrix be square or no
    if (mat.row == mat.col)
    {
        return true;
    }
    else
        return false;
}
bool isSymetric (matrix mat){///Checking is the matrix square and symmetric or no
    if (mat.row == mat.col) ///If the matrix is square, checking for the symmetric, if isn't square don't check
    {
        for(int i=0; i < mat.row; i++)
        {
            for(int j=0; j < mat.col; j++)
            {
                if(mat.data[i][j] != mat.data[j][i])
                {
                    return false;
                }
            }
        }

        return true;
    }
    else
        cout <<"Error,Please enter equal rows and columns" << endl;

}
bool isIdentity (matrix mat){ ///Checking is the matrix square and identity or no
    if (mat.row == mat.col) ///If the matrix is square, checking for the identity, if isn't square don't check
    {
        for(int i=0; i < mat.row; i++)
        {
            for(int j=0; j < mat.col; j++)
            {
                if(i==j && mat.data[i][j] != 1)
                {
                    return false;
                }
                else if(i!=j && mat.data[i][j]!=0)
                {
                    return false;
                }
            }
        }
        return true;
    }
    else
        cout <<"Error,Please enter equal rows and columns" << endl;
}
matrix transpose (matrix mat, matrix trn){ ///Finding transpose of matrix mat and storing it in matrix trn to return it
    for (int i =0; i < mat.row ; i++)
    {
        for(int j =0; j < mat.col; j++)
        {
            trn.data[j][i]= mat.data[i][j];
        }
    }
    return trn;
}
matrix operator+  (matrix mat1, matrix mat2){
    if(mat1.row == mat2.row && mat1.col == mat2.col){
        matrix mat;
        int a[mat1.row*mat1.col];
        zero(a, mat1.row*mat1.col);
        createMatrix(mat1.row, mat1.col, a, mat);
        for(int i = 0; i < mat1.row; ++i)
            for(int j = 0; j < mat1.col; ++j)
                mat.data[i][j] = mat2.data[i][j] +  mat1.data[i][j];
        return mat;
    }else
        cout <<"Error,Please enter equal rows and columns" << endl;
} // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2){
    if(mat1.row == mat2.row && mat1.col == mat2.col){
        matrix mat;
        int a[mat1.row*mat1.col];
        zero(a, mat1.row*mat1.col);
        createMatrix(mat1.row, mat1.col, a, mat);
        for(int i = 0; i < mat1.row; ++i)
            for(int j = 0; j < mat1.col; ++j)
                mat.data[i][j] = mat2.data[i][j] -  mat1.data[i][j];
        return mat;
    }else
        cout <<"Error,Please enter equal rows and columns" << endl;
} // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2){
    if(mat1.col == mat2.row){
        int sum = 0, col = 0, row = 0, c = 0;
        vector <int> v;
        matrix mat3;
        mat3.row = mat1.row;
        mat3.col = mat2.col;
        mat3.data = new int* [row];
        for (int i = 0; i < mat3.row; i++)
            mat3.data[i] = new int [mat3.col];
        for(int i = 0; i < mat1.row; ++i){
            for(int j = 0; j < mat1.col; ++j){
                sum += mat1.data[i][j]*mat2.data[row][col];
                ++row;
            }
            v.push_back(sum);
            row = 0;
            ++col;
            sum = 0;
        }
        for(int i = 0; i < mat3.row; ++i)
            for(int j = 0; j < mat3.col; ++j)
                mat3.data[i][j] = v[c++];
        return mat3;
    }else
        cout << "Can't preform multiplication\n " << endl;

} // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar){
        for(int i = 0; i < mat1.row; ++i)
            for(int j = 0; j < mat1.col; ++j)
                mat1.data[i][j] += scalar;
        return mat1;
}  // Add a scalar
matrix operator-  (matrix mat1, int scalar){
        for(int i = 0; i < mat1.row; ++i)
            for(int j = 0; j < mat1.col; ++j)
                mat1.data[i][j] -= scalar;
        return mat1;
}  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar){
        for(int i = 0; i < mat1.row; ++i)
            for(int j = 0; j < mat1.col; ++j)
                mat1.data[i][j] *= scalar;
        return mat1;
}  // Multiple by scalar
