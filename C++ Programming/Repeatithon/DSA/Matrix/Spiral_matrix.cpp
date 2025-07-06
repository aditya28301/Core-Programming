#include <iostream>
#include <vector>

class matrix{
    private:
        int row;
        int col;
        std::vector<std::vector<int>> mat;
    public:
        matrix(int _row, int _col, std::vector<std::vector<int>>&  mat_vec) : 
        row(_row), 
        col(_col),
        mat(mat_vec){}

        void spriralMatrix(){
            for(int i = 0; i < col; ++i){
                std::cout << mat[0][i]<<",";
            }

            if(row - 2 == 0){
                for(int i = row - 1; i < row; ++i){
                    std::cout << mat[i][col - 1]<<",";
                }
            }
            else{
                for(int i = row - (row - 1); i < row; ++i){
                    std::cout << mat[i][col - 1]<<",";
                }
            }

            // std::cout << std::endl;

            for(int i = col - 2 ; i >= 0; --i){
                std::cout << mat[row - 1][i]<<",";
            }

            // std::cout << std::endl;
            if(row - 2 != 0){
                for(int i = row - 2; i >= row - (row - 1); --i){
                    std::cout << mat[i][0]<<",";
                }


            if(col - 2 != 0){
                for(int i = col - 2; i <= col -2; ++i){
                    std::cout << mat[row-2][i]<<",";
                }
            }
        }
        }
};

int main(void){
    std::vector<std::vector<int>> mat =
    {
        {1, 2},
        {3,4},
        {5,6},
        {7,8}
    };
    matrix m1(mat.size(),mat[0].size(), mat);
    m1.spriralMatrix();
    return EXIT_SUCCESS;
}