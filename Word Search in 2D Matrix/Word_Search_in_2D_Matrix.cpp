#include <vector>
#include <string>
#include <iostream>
using namespace std;

bool dfs(vector<vector<char>>& board,string word,int i,int j,int index){
        if(index == word.size()) return true;

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j] != word[index]) return false;

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = dfs(board,word,i+1,j,index+1) || // DOWN
        dfs(board,word,i-1,j,index+1) || // UP
        dfs(board,word,i,j+1,index+1) || // RIGHT
        dfs(board,word,i,j-1,index+1); // LEFT

        board[i][j] = temp; 

        return found;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int columns = board[0].size();

        for(int i = 0;i < rows;i++){
            for(int j = 0;j < columns;j++){
                if(dfs(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }

    int main(){
        vector<vector<char>>board = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
};
        string word = "ABFAAAA";

        cout<<boolalpha<<exist(board,word);
        
    }