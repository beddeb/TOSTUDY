#include <stdio.h>
#include <stdlib.h>

int ERROR_CODE = 0;

void fill_rand_matrix(int m, int n, int matrix[], int diapozon[2]);
void print_matrix(int m, int n, int matrix[]);
void transposition(int m, int n, int matrix[], int *res);
void sum(int m_A, int n_A, int mtr_A[], int m_B, int n_B, int mtr_B[], int res[]);
void multi(int m_A, int n_A, int mtr_A[], int m_B, int n_B, int mtr_B[], int res[]);
void pow_mtr(int m_A, int n_A, int mtr_A[], int res[]);



int main()
{
    int m_A, n_A, m_B, n_B;
     

    // int diap[2]={13,24};
    // fill_rand_matrix(m_A,n_A, &A[0][0], diap);
    // fill_rand_matrix(m_B,n_B, &B[0][0], diap);
    scanf("%d %d", &m_A, &n_A);
    int A[m_A][n_A];
    for(int ii=0; ii<m_A; ii++)
    for(int jj=0; jj<n_A; jj++)
        scanf("%d", &A[ii][jj]);

    
    scanf("%d %d", &m_B, &n_B);
    int B[m_B][n_B];
    for(int ii=0; ii<m_B; ii++)
    for(int jj=0; jj<n_B; jj++)
        scanf("%d", &B[ii][jj]);

    

    int transB[n_B][m_B];
    transposition(m_B, n_B, &B[0][0], &transB[0][0]);

    int multiBtB[n_B][n_B];
    multi(n_B, m_B, &transB[0][0], m_B, n_B, &B[0][0], &multiBtB[0][0]);
    
    int powB[n_B][n_B];
    pow_mtr(n_B, n_B, &multiBtB[0][0], &powB[0][0]);

    int multiAB[m_A][n_B];
    multi(m_A, n_A, &A[0][0], m_B, n_B, &B[0][0], &multiAB[0][0]);

    int res[m_A][n_B];
    sum(m_A, n_B, &multiAB[0][0], n_B, n_B, &powB[0][0], &res[0][0]);

    print_matrix(m_A, m_A, &res[0][0]);
}

void fill_rand_matrix(int m, int n, int matrix[], int diapozon[2])
{
    int a=diapozon[0], b=diapozon[1];
    for(int ii=0; ii<m; ii++)
    for(int jj=0; jj<n; jj++)
        matrix[ii*n+jj] = rand()%(b-a+1) + a;
}
void print_matrix(int m, int n, int matrix[])
{
    for(int ii=0; ii<m; ii++)
    {
        for(int jj=0; jj<n; jj++)
            printf("%6d", matrix[ii*n+jj]);
        printf("\n");
    }
}


void transposition(int m, int n, int matrix[], int *res)
{
    
    for(int ii=0; ii<n; ii++)
    for(int jj=0; jj<m; jj++)
        res[ii*m+jj] = matrix[jj*n+ii];
}

void sum(int m_A, int n_A, int mtr_A[], int m_B, int n_B, int mtr_B[], int res[])
{
    if(!(m_A==m_B && n_A==n_B))
    {
        ERROR_CODE=1;
        printf("!1\n");
        exit(0);
    }

    for(int ii=0; ii<m_A; ii++)
    for(int jj=0; jj<n_A; jj++)
    res[ii*n_A+jj] = mtr_A[ii*n_A+jj]+mtr_B[ii*n_A+jj];
}


void multi(int m_A, int n_A, int mtr_A[], int m_B, int n_B, int mtr_B[], int res[])
{
    if(!(n_A==m_B))
    {
        ERROR_CODE=2;
        printf("!2\n");
        exit(0);
    }
    int sum=0;
    for(int ii=0; ii<m_A; ii++)
    for(int jj=0; jj<n_B; jj++)
    {
        sum=0;
        for(int kk=0; kk<n_A; kk++)
        {
            sum+=mtr_A[ii*n_A+kk]*mtr_B[kk*n_B+jj];
        }
        res[ii*n_B+jj] = sum;
    }
}

void pow_mtr(int m_A, int n_A, int mtr_A[], int res[])
{
    if(!(n_A==m_A))
    {
        ERROR_CODE=3;
        printf("!3\n");
        exit(0);
    }

    multi(m_A, n_A, &mtr_A[0], m_A, n_A, &mtr_A[0], &res[0]);
}
