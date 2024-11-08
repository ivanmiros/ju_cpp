// ...
#include <iostream> 
#include <cstring>
using namespace std;


// print square 2D array
void print_arr(int ** A, int size) {
    for (int i=0 ; i<size ; i++){
        for (int j=0 ; j<size ; j++ ) cout << A[i][j] << " ";
        cout << endl;
    }

}

// put numbers to 2D square array
void fill_arr(int ** A, int size) {

    if (size < 12) {
        cout << "Size < 12. Skip fill_arr()" << endl;
        return;
    }
    int *p = &A[1][0];
    *p++ = 2;*p++ = 1;*p++ = 1;*p++ = 1;*p++ = 0;*p++ = 4;*p++ = 0;*p++ = 4;*p++ = 2;*p++ = 0;*p++ = 2;*p++ = 0; 
}

// do command N
void command_n(int ** A, int size) {

    cout << " =N" << endl;
    int x,y,w; 
    cin >> x >> y >> w;
    A[x-1][y-1] = w;
}

 int main(){
    int M=12; //cin >> M;

    // Array of pointers - columns
    int **A = new int* [M];
    // Add arrays of rows + init to 0
    for(int i = 0; i < M; i++) {
        A[i] = new int[M];
        memset(A[i], 0, sizeof(int)*M);
    }

    
    fill_arr(A,M);
    print_arr(A,M);

    char command;
    while(cin >> command && command != 'K' ){ 


        if( command == 'N'){ 
            command_n(A,M);
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
         


        print_arr(A,M);
    }

}