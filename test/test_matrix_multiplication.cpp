#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult


TEST(MatrixMultiplicationTest, TestMultiplyMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);
    /*TEST_COUT << "Matrix C:" << std::endl;
    for (const auto& row : C) {
        for (const auto& element : row) {
            TEST_COUT << element << " ";
        }
        TEST_COUT << std::endl;
    }*/
    std::vector<std::vector<int>> expected = {
        {58, 64},
        {139, 154}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

TEST(MatrixMultiplicationTest, TestMultiplyScalars) {
    
    std::vector<std::vector<int>> A = {
        {6}
    };
    std::vector<std::vector<int>> B = {
        {5}
    };
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));
    multiplyMatrices(A, B, C, 1, 1, 1);

    std::vector<std::vector<int>> expected = {
        {30}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

TEST(MatrixMultiplicationTest, TestSumColRow) {
    
    std::vector<std::vector<int>> A = {
        {6},
        {7}
        
    };
    std::vector<std::vector<int>> B = {
        {5,4}
    };
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));
    multiplyMatrices(B, A, C, 1, 2, 1);

    std::vector<std::vector<int>> expected = {
        {58}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}

TEST(MatrixMultiplicationTest, TestMultiplyIdentity) {
    
    std::vector<std::vector<int>> A = {
        {1,0,0},
        {0,1,0},
        {0,0,1}
        
    };
    std::vector<std::vector<int>> B = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));
    multiplyMatrices(A, B, C, 3, 3, 3);


    ASSERT_EQ(C, B) << "Matrix multiplication test failed! :(((()";

    multiplyMatrices(B, A, C, 3, 3, 3);
    ASSERT_EQ(C, B) << "Matrix multiplication test failed! :(((()";
}
TEST(MatrixMultiplicationTest, TestMultiplyBig) {
    
    std::vector<std::vector<int>> A(10, std::vector<int>(10, 0));
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            A[i][j]=(i*10)+j;
        }
    }
    std::vector<std::vector<int>> B(10, std::vector<int>(10, 0));
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            B[i][i]=1;
        }
    }

    std::vector<std::vector<int>> C(10, std::vector<int>(10, 0));
    multiplyMatrices(A, B, C, 10, 10, 10);

   

    ASSERT_EQ(C, A) << "Matrix multiplication test failed! :(((()";

    multiplyMatrices(B, A, C, 10, 10, 10);
    ASSERT_EQ(C, A) << "Matrix multiplication test failed! :(((()";


}





int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
