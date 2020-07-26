#################################################
#                                               #
#         Created by Cao Le Cong Minh           #
#                                               #
#################################################
#   Gmail:  caolecongminh1997@gmail.com         #
#	Github: https://github.com/Minh-CaoLeCong   #
#################################################

# Import the necessary packages
import numpy as np

# Recursively, multiplying two matrices product by divide and conquer 
# (Strassen’s Matrix Multiplication) approach.
"""
The idea of Strassen’s method is to reduce the number of recursive 
calls to 7. Strassen’s method is similar to above simple divide 
and conquer method in the sense that this method also divide matrices 
to sub-matrices of size N/2 x N/2 as shown in the above diagram, 
but in Strassen’s method, the four sub-matrices of result are calculated 
using following formulae:
    p1 = a(f -h)            p2 = (a + b)h
    p3 = (c + d)e           p4 = d(g - e)
    p5 = (a + d)(e + h)     p6 = (b - d)(g + h)
    p7 = (a - c)(e + f)
"""

"""
Time Complexity of Strassen’s Method:
Addition and Subtraction of two matrices takes O(N2) time. 
So time complexity can be written as

T(N) = 7T(N/2) +  O(N2)

From Master's Theorem, time complexity of above method is 
O(NLog7) which is approximately O(N2.8074)
"""

def multiply_strassen_split(matrix):
    """ 
    Splits matrix into one of four equal parts (quarters). 
    Input: square matrix (nxn)
    Output: containing 4 n/2 x n/2 matrices corresponding to a, b, c, d 
    """
    row1, collumn1 = matrix.shape
    row2, collumn2 = row1 // 2, collumn1 // 2
    return  matrix[:row2, :column2], matrix[:row2, column2:], 
            matrix[row2:, :collumn2], matrix[row2:, collumn2]

def multiply_strassen(matrix1, matrix2):
    """ 
    Recursively, multiplying two matrices product by divide and conquer 
    (Strassen’s Matrix Multiplication) approach. 
    Input: square matrices (nxn) matrix1 and matrix2 
    Output: nxn matrix, product of matrix1 and matrix2 
    """

    # Base case of recursion when size of matrices is 1x1
    if len(matrix1) == 1:
        return matrix1 * matrix2

    # Split the matrices into one of four equal parts (quarters). 
    # This will be done recursively until the base case is reached.
    a, b, c, d = multiply_strassen_split(matrix1)
    e, f, g, h = multiply_strassen_split(matrix2)

    # Computing the 7 products, recursively (p1, p2...p7)
    p1 = multiply_strassen(a, f - h)   
    p2 = multiply_strassen(a + b, h)         
    p3 = multiply_strassen(c + d, e)         
    p4 = multiply_strassen(d, g - e)         
    p5 = multiply_strassen(a + d, e + h)         
    p6 = multiply_strassen(b - d, g + h)   
    p7 = multiply_strassen(a - c, e + f)

    # Computing the values of the 4 quarters of the final matrix c 
    c00 = p5 + p4 - p2 + p6   
    c01 = p1 + p2            
    c10 = p3 + p4             
    c11 = p1 + p5 - p3 - p7

    # Combining the 4 quarters into a single matrix by stacking horizontally and vertically. 
    c = np.vstack((np.hstack((c00, c01)), np.hstack((c10, c11))))  

    return c
    
"""
Generally Strassen’s Method is not preferred for practical applications for following reasons:
1) The constants used in Strassen’s method are high and 
for a typical application Naive method works better.
2) For Sparse matrices, there are better methods especially designed for them.
3) The submatrices in recursion take extra space.
4) Because of the limited precision of computer arithmetic on noninteger values, 
larger errors accumulate in Strassen’s algorithm than in Naive Method 
"""
# Recursively, multiplying two matrices product by divide and conquer 
# (Strassen’s Matrix Multiplication) approach.

#################################################
#                                               #
#         Created by Cao Le Cong Minh           #
#                                               #
#################################################
#   Gmail:  caolecongminh1997@gmail.com         #
#	Github: https://github.com/Minh-CaoLeCong   #
#################################################