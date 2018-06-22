#include <iostream>
#include <math.h> // pour utiliser la fonction isnan
using namespace std;

int main()
{
    int i, j, k, n;
    bool Booleen; //va servir pour l'affichage
    bool continuer;
    cout << "Dimensions de la matrice : ";
    cin >> n;
    float M[n][2*n] = { 0 }, d;
    float lk[2*n], li[2*n];
    float Mp[n][2*n];

    cout << "Coefficients de la matrice : " << endl;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<"M["<<i+1<<"]"<<"["<<j+1<<"] : ";//préciser quel coefficient on entre
            cin>>M[i][j];
        }
    }
    cout<< "Matrice a inverser : " << endl;
    for (int i=0;i<n;i++)//on affiche la matrice que l'on veut inverser sur la console
    {
        for (int j=0;j<n;j++){
            cout<<" "<<M[i][j]<<" ";
        }
        cout<< endl ;
    }

//on crée la matrice identité
    for (i = 0; i < n; i++){
        for (j = 0; j < 2 * n; j++){
            if (j == (i + n)){ //qui sera à côté de la matrice à inverser (concaténation)
                M[i][j] = 1;
            }
        }
    }
/*
//on fait un pivot de gauss
    for (i = n; i > 1; i--)
    {
        if (M[i - 1][1] < M[i][1]){
            for (j = 1; j <= n * 2; j++)
            {
                d = M[i][j];
                M[i][j] = M[i - 1][j];
                M[i - 1][j] = d;
            }
        }
    }

//on diagonalise
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n * 2; j++){
            if (j != i)
            {
                d = M[j][i] / M[i][i];
                for (k = 1; k <= n * 2; k++)
                    M[j][k] -= M[i][k] * d;
            }
        }
    }

// vérifie si les valeurs propres ne sont pas nulles, si oui on divise pour avoir l'identité
    for (i = 1; i <= n; i++){
        d = M[i][i];
        if (isnan(M[i][i]) || d==0) {
            Booleen = 0;
            break;
        }
        for (j = 1; j <= n * 2; j++){
            M[i][j] = M[i][j] / d;
        }
    }
*/

for(k = 0; k<n; k++)
{
    i = k;
    continuer = true;

    for(int i1=0; i1<n;i1++)
    {
        for(j=0;j<2*n;j++)
        {
            Mp[i1][j] = M[i1][j];
        }
    }

    while(i < n)
    {
        if(M[i][k] != 0)
        {
            continuer = false;

            for(j = 0; j<2*n; j++)
            {
                M[k][j] =  Mp[i][j];
                M[i][j] =  Mp[k][j];
            }
            for(j=0; j<2*n;j++)
            {
                M[k][j] = Mp[k][j]/Mp[k][k];
            }

            for(int i1=0; i1 < n; i1++)
            {
                if(i1 != k)
                    for(j=0;j<2*n;j++)
                    {
                        M[i1][j] = Mp[i1][j] - Mp[i1][k]*M[k][j];
                    }
            }

        }
        i++;
    }
    if(continuer == true)
        break;
}
//on affiche le résultat avec une condition si la matrice est inversible
    cout << "Matrice inversee : "<< endl;
    if (Booleen==1){
        for (i = 0; i < n; i++){
            for (j = n ; j < n * 2; j++){
                cout << " " <<M[i][j] << "    ";
            }
            cout << endl;
        }
    }
    else{
        cout << "le systeme n'a pas de solution avec cette methode !" << endl ;
    }
    return 0;
}