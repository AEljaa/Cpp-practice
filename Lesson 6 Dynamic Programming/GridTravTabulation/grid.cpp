#include <iostream>

 int grid(int x,int y){

    int arr[x+1][y+1];
    for (int i = 0; i < x+1; i++) {
        for (int j = 0; j < y+1; j++) {
            arr[i][j] = 0;
        }
    }
    arr[1][1]=1;
    for (int i = 0; i <= x; i++) {
        for (int j = 0; j <= y; j++) {
            int current = arr[i][j];
            if (j + 1 <= y) {
                arr[i][j + 1] += current;
            }
            if (i + 1 <= x) {
                arr[i + 1][j] += current;
            }
        }
    }
    return arr[x][y];
}

int main(){
    int x,y;
    std::cin>>x>>y;
    std::cout<<grid(x,y)<<std::endl;
}

