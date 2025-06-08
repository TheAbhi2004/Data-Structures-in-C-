#include <stdio.h>

void transpose( int nzero, int triplet[50][3]) 
{
    int i, j, k,row,col;
    int temp[50][3];

    row=triplet[0][0]; 
    col=triplet[0][1];
    temp[0][0]= col; 
    temp[0][1]=row; 
    temp[0][2]=nzero;
    // Transpose the matrix
    k = 1;
    for(j=0;j<col;j++)
    { 
         for(i=1;i<nzero+1;i++)
         { 
           if(triplet[i][1]==j)
           {
             temp[k][0] = triplet[i][1];
             temp[k][1] = triplet[i][0];
             temp[k][2] = triplet[i][2];
             k++;
           }
        }
    }    

    // Print the transposed matrix
    printf("Transposed Matrix:\n");
    printf("Row\tCol\tValue:\n");
    for (i = 0;i<nzero+1; i++)
    { 
        for(j=0;j<3;j++)
        {
          printf("%d\t",temp[i][j]);
        }
        printf("\n"); 
    }    
}

int main() 
{
    int nz;
    
    printf("Enter the number of non zero values of sparse matrix: ");
    scanf("%d", &nz);

    
    int triplet[50][3];
    printf("Enter the 3-tuple representation of the sparse matrix:\n");
    for (int i = 0; i<nz+1; i++) 
    { 
        for(int j=0;j<3;j++) 
        {
          scanf("%d",&triplet[i][j]);
        }
    }
    printf("Displaying triplet matrix:\n");
    printf("Row\tCol\tValue:\n"); 
    for(int i=0;i<nz+1;i++) 
    {
       for(int j=0;j<3;j++) 
       { 
          printf("%d\t",triplet[i][j]);
       }
       printf("\n");
    }      
    transpose(nz, triplet);

    return 0;
}

