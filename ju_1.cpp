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
    // fill the 2nd row
    int i = 1;
    int j = 0;
    A[i][j++] = 2;
    A[i][j++] = 1;
    A[i][j++] = 1;
    A[i][j++] = 1;
    A[i][j++] = 0;
    A[i][j++] = 4;
    A[i][j++] = 0;
    A[i][j++] = 4;
    A[i][j++] = 2;
    A[i][j++] = 0;
    A[i][j++] = 2;
    A[i][j++] = 0;

    // fill the 3rd column
    i = 0;
    j = 2;
    A[i++][j] = 2;
    A[i++][j] = 3;
    A[i++][j] = 1;
    A[i++][j] = 0;
    A[i++][j] = 0;
    A[i++][j] = 4;
    A[i++][j] = 3;
    A[i++][j] = 2;
    A[i++][j] = 0;
    A[i++][j] = 1;
    A[i++][j] = 1;
    A[i++][j] = 0;
}

// do command N
void command_n(int ** A, int size) {

    cout << " =N" << endl;
    int x,y,w; 
    cin >> x >> y >> w;
    A[x-1][y-1] = w;
}


// move numbers to the left
void move_l(int ** A, int size) {

    for (int i = 0 ; i < size; i++ ) {    
        int shift = 0;
        for (int j = 0 ; j < size; j++ ) {
            if (A[i][j] != 0){
                A[i][shift] = A[i][j];       // move to the left
                if (shift != j) A[i][j] = 0; // clear if it's not the same 
                shift++;
            }
        }
    }
}

// move numbers to the right
void move_r(int ** A, int size) {

    for (int i = 0 ; i < size; i++ ) {    
        int shift = size-1;
        for (int j = size-1 ; j >= 0; j-- ) {
            if (A[i][j] != 0){
                A[i][shift] = A[i][j];       // move to the right
                if (shift != j) A[i][j] = 0; // clear if it's not the same 
                shift--;
            }
        }
    }
}

// move numbers to the top
void move_t(int ** A, int size) {

    for (int j = 0 ; j < size; j++ ) {    
        int shift = 0;
        for (int i = 0 ; i < size; i++ ) {
            if (A[i][j] != 0){
                A[shift][j] = A[i][j];       // move to the top
                if (shift != i) A[i][j] = 0; // clear if it's not the same 
                shift++;
            }
        }
    }
}

// move numbers to the bottom
void move_b(int ** A, int size) {

    for (int j = 0 ; j < size; j++ ) {    
        int shift = size-1;
        for (int i = size-1 ; i >= 0; i-- ) {
            if (A[i][j] != 0){
                A[shift][j] = A[i][j];       // move to the bottom
                if (shift != i) A[i][j] = 0; // clear if it's not the same 
                shift--;
            }
        }
    }
}


int main() {
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
    while(cin >> command && command != 'K' ) { 


        if( command == 'N'){ 
            command_n(A,M);
        }
         
        if ( command == 'L'){
            move_l(A,M);
        }

        if ( command == 'R'){
            move_r(A,M);
        } 

        if ( command == 'T'){
            move_t(A,M);
        } 

        if ( command == 'B'){
            move_b(A,M);
        } 


        print_arr(A,M);
    }

}