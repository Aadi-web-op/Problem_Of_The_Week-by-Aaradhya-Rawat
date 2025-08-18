#include <iostream>
#include <vector>
using namespace std;

void fill(vector<vector<char>>& image,int i,int j,char color,char og){
    if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j] != og) return;

    if(image[i][j] == og){
        image[i][j] = color;
        fill(image,i+1,j,color,og); //down
        fill(image,i-1,j,color,og); //up
        fill(image,i,j+1,color,og); //right
        fill(image,i,j-1,color,og); //left
    }
}

int main(){
    vector<vector<char>> image = {
{'B', 'B', 'W'},
{'W', 'W', 'W'},
{'W', 'W', 'W'},
{'B', 'B', 'B'}
};
int sr = 2;
int sc = 2;
char color = 'G';
char og = image[sr][sc];
if (og == color){
   for(int i=0;i<image.size();i++){
    for(int j=0;j<image[0].size();j++){
        cout<<image[i][j]<<" ";
    }
    cout<<endl;
} 
} 
else{
    fill(image,sr,sc,color,og);

for(int i=0;i<image.size();i++){
    for(int j=0;j<image[0].size();j++){
        cout<<image[i][j]<<" ";
    }
    cout<<endl;
}
}


}