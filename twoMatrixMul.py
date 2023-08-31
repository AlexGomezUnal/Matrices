import random
import time

def generate_random_matrix(rows, cols):
    matrix = []
    for _ in range(rows):
        row = [random.randint(-100, 100) for _ in range(cols)]
        matrix.append(row)
    return matrix

def matrix_multiplication(matrix1, matrix2):
    if len(matrix1[0]) != len(matrix2):
        raise ValueError("Number of columns in the first matrix must match number of rows in the second matrix.")

    result = [[0] * len(matrix2[0]) for _ in range(len(matrix1))]

    for i in range(len(matrix1)):
        for j in range(len(matrix2[0])):
            for k in range(len(matrix2)):
                result[i][j] += matrix1[i][k] * matrix2[k][j]

    return result
def printMatrix(row,col,matrix):
    for i in range(row):
        for j in range(col):
            print(matrix[i][j]) 
# Define the dimensions of the matrices
rows_matrix1 = 30
cols_matrix1 = 20
cols_matrix2 = 30

start_time = time.time() 
# Generate random matrices
matrix1 = generate_random_matrix(rows_matrix1, cols_matrix1)
matrix2 = generate_random_matrix(cols_matrix1, cols_matrix2)

# Perform matrix multiplication
result_matrix = matrix_multiplication(matrix1, matrix2)

# Print the matrices and their product
printMatrix(rows_matrix1,cols_matrix1,matrix1)
printMatrix(cols_matrix1,cols_matrix2,matrix2)
printMatrix(rows_matrix1,cols_matrix2,result_matrix)

print("------ %s seconds --------" % (time.time() - start_time)) 