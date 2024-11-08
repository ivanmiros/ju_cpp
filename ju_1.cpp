// ...
#include <iostream> 
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <sstream>
using namespace std;


 int main(){
   int M; cin >> M;

   int A[M][M]; memset(A, 0, sizeof(A));

A[1][0] = 2;A[1][1] = 1;A[1][2] = 1;A[1][3] = 1;A[1][4] = 0;A[1][5] =4 ;A[1][6] = 0;A[1][7] = 4;A[1][8] =2 ;A[1][9] = 0;A[1][10] = 2;A[1][11] =0 ;
   for (int i=0 ; i<M ; i++){
            for (int j=0 ; j<M ; j++ ) cout << A[i][j] << " ";
        cout << endl;
        }

    char command;
    while(cin >> command && command != 'K' ){ 


        if( command == 'N'){ 
            cout << " =N" << endl;
            int x,y,w; cin >> x >> y >> w;
            A[x-1][y-1] = w;

        }
         
        if ( command == 'L'){
            cout << " =L" << endl;
            int flag = 0;
           while (1){
                for (int i = 0 ; i<M ; i++ ){               
                    flag = 0;
                    for (int j = 0 ; j<M ; j++ ){
                            if (A[i][j] != 0){
                                A[i][flag] = A[i][j];
                                flag++;
                            }
                    }
                    for (int j=flag ; j<M ; j++) A[i][j] = 0;
                }
                
                flag = 0; 
                for (int n = 0 ; n<M ; n++){
                    for (int i = 1; i<M ; i++ ){
                        if (A[n][i-1] != 0 && A[n][i] != 0)
                            if (A[n][i]%A[n][i-1] == 0 ){
                                A[n][i] = A[n][i]-A[n][i-1];  
                                A[n][i-1] = A[n][i-1]*2;
                                flag++;
                            }
                     }
                }
                if (flag == 0){ break;} 
             }
            


        }
         


        for (int i=0 ; i<M ; i++){
            for (int j=0 ; j<M ; j++ ) cout << A[i][j] << " ";
        cout << endl;
        }
    }

}