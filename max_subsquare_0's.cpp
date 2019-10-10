#include<bits/stdc++.h>
using namespace std;
void getMatrixData(int rows,int columns,vector<vector<int>>&matrix)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cin>>matrix[i][j];
        }
    }
}

void calSubSquare(int rows,int columns,vector<vector<int>>&matrix,vector<vector<int>>&tempMatrix)
{
    for(int j=0;j<columns;j++)
    tempMatrix[0][j]=(matrix[0][j]==0)?1:0;

    for(int i=0;i<rows;i++)
    tempMatrix[i][0]=(matrix[i][0]==0)?1:0;

    for(int i=1;i<rows;i++)
    {
        for(int j=1;j<columns;j++)
        {
            tempMatrix[i][j]=(matrix[i][j]==0)?(min(tempMatrix[i-1][j-1],min(tempMatrix[i-1][j],tempMatrix[i][j-1]))+1):0;
        }
    }

}

int getSubSquare(int rows,int columns,vector<vector<int>>&matrix)
{
    vector<vector<int>>tempMatrix(rows,vector<int>(columns));

    calSubSquare(rows,columns,matrix,tempMatrix);

    int maxSize=0;

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            maxSize=max(maxSize,tempMatrix[i][j]);
        }
    }

    return maxSize;
}

int main()
{
    int rows,columns;
    cin>>rows;
    cout<<"Enter the number of rows"<<endl;

    cin>>columns;
    cout<<"Enter the number of columns"<<endl;

    

    vector<vector<int>>matrix(rows,vector<int>(columns));

    getMatrixData(rows,columns,matrix);

    cout<<getSubSquare(rows,columns,matrix);

    

}
