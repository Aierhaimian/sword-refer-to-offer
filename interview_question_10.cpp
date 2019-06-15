#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

// Recursive
// Time  Complexity: O(2^n)
// Space Complexity: O(1)
class Solution1 {
public:
    long long fibonacci(unsigned int n) {
        return n == 0 ? 0 : (n == 1 ? 1 : fibonacci(n-1) + fibonacci(n-2));
    }
};

// Memory search by Recursive
// Time  Complexity: O(n)
// Space Complexity: O(n)
class Solution2 {
public:
    long long fibonacci(unsigned int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        vector<long long> mem(n+1, -1);
        mem[0] = 0;
        mem[1] = 1;
        return generateFib(n, mem);
    }
private:
    long long generateFib(unsigned int n, vector<long long>& mem) {
        if (n == 0) {
            return mem[0];
        }
        if (n == 1) {
            return mem[1];
        }

        if (mem[n] != -1)
            return mem[n];

        mem[n] = generateFib(n-1, mem) + generateFib(n-2, mem);
        return mem[n];
    }
};

// Memory Search by Non-recursive
// Time  Complexity: O(n)
// Space Complexity: O(n)
class Solution3 {
public:
    long long fibonacci(unsigned int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        vector<long long> mem(n+1, -1);
        mem[0] = 0; mem[1] = 1;
        for (unsigned int i=2; i<=n; i++)
            mem[i] = mem[i-1] + mem[i-2];
        return mem[n];
    }
};

// Memory Search by Non-recursive
// Time  Complexity: O(n)
// Space Complexity: O(1)
class Solution4 {
public:
    long long fibonacci(unsigned int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        long long mem0 = 0, mem1 = 1, fibN = 0;
        for (unsigned int i=2; i<=n; i++) {
            fibN = mem0 + mem1;
            mem0 = mem1;
            mem1 = fibN;
        }
        return fibN;
    }
};

// Math
// Time  Complexity: O(logn)
// Space Complexity: O(1)

class Matrix2By2 {
public:
    Matrix2By2( long long m00 = 0, long long m01 = 0,
                long long m10 = 0, long long m11 = 0)
        :m_00(m00), m_01(m01), m_10(m10), m_11(m11) {  }

    Matrix2By2 MatrixMul(Matrix2By2& matrix1, Matrix2By2& matrix2) {
        return Matrix2By2(
                          matrix1.m_00 * matrix2.m_00 + matrix1.m_01 * matrix2.m_10,
                          matrix1.m_00 * matrix2.m_01 + matrix1.m_01 * matrix2.m_11,
                          matrix1.m_10 * matrix2.m_00 + matrix1.m_11 * matrix2.m_10,
                          matrix1.m_10 * matrix2.m_01 + matrix1.m_11 * matrix2.m_11
                         );
    }

    Matrix2By2 MatrixPow(unsigned int n) {
        assert(n > 0);

        Matrix2By2 matrix;
        if (n == 1)
            matrix = Matrix2By2(1, 1, 1, 0);
        else if (n%2 == 0) {
            matrix = MatrixPow(n / 2);
            matrix = MatrixMul(matrix, matrix);
        }
        else if (n %2 == 1) {
            matrix = MatrixPow((n-1)/2);
            matrix = MatrixMul(matrix, matrix);
            Matrix2By2 tmp(1,1,1,0);
            matrix = MatrixMul(matrix, tmp);
        }

        return matrix;
    }

    long long m_00;
    long long m_01;
    long long m_10;
    long long m_11;
};

class Solution : public Matrix2By2 {
public:
    long long fibonacci(unsigned int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        Matrix2By2 PowerNMinus2 = MatrixPow(n-1);

        return PowerNMinus2.m_00;
    }
};

int main()
{
    cout << Solution().fibonacci(0) << endl;
    cout << Solution().fibonacci(1) << endl;
    cout << Solution().fibonacci(2) << endl;
    cout << Solution().fibonacci(5) << endl;
    cout << Solution().fibonacci(6) << endl;
    cout << Solution().fibonacci(100) << endl;
    return 0;
}

