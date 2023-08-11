#include <iostream>
#include <vector>
#include <time.h>


template <typename T> 
class Matrix{
protected: std::vector<T> V;	
protected: int row; 
protected: int col;

public: 
Matrix(int row, int col) : row(row), col(col) {
    this->createMatrixAsARandomVector();
}

public: void  setRow(int row){
	this->row = row;
}

public : T getRow(){
	return this->row;
}  
public: void setCol(int col){
	this->col = col;
}

public: T getCol(){
	return this->col; 
}
public: std::vector<T> getV(){
	return this->V; 
} 
protected: T getRandomValue() {
    T lowerBound = 0;
    T upperBound = 1000;
	double factor = 0.00001;
    int randomInt = rand(); 

    if (std::is_same<T, int>::value) {
        return factor*(lowerBound + (upperBound - lowerBound) * randomInt);
    } else if (std::is_same<T, double>::value) {
        return factor*(lowerBound + (upperBound - lowerBound) * static_cast<double>(randomInt)) ;
    } else {
		std::cout<<"Sorry not Suported bye"<<std::endl;
		exit(1);
        return T{};
    }
} 
protected: void createMatrixAsARandomVector(){

 
    srand(time(NULL));

    for(int i=0; i<this->row*this->col; i++){
    T randomNumber = this->getRandomValue();
    this->V.push_back(randomNumber);
    }
} 

public: void printMatrix(){
	int index=0;
	for(T num:this->V){
		index++;
		std::cout<<num<<" ";
		if(index % this->col == 0) std::cout<<std::endl;
} 
}

}; 

template <typename T> 
class MatrixMult{ 
const long max_rand = 1000000L;
protected: Matrix<T> A;
protected: Matrix<T> B; 


public: 
MatrixMult(int RowA, int ColA, int RowB, int ColB) : A(RowA, ColA), B(RowB, ColB) {
    if (!this->checkMult()) {
        std::cout << "Sorry not possible to Compute. Try Again" << std::endl;
        exit(1);
    }
}
public: Matrix<T> getA(){
	return this->A;
} 
public: Matrix<T> getB(){
	return this->B;
}

protected: bool checkMult(){
	return A.getCol() == B.getRow();
} 
     
protected: std::vector<T> reorganizeVectorB() {
    int n = this->B->size();
    std::vector<T> BOrganized;
    
    int set = 0;
    int index =0;   
    
    for (int i=0; i<n; i++) { 
    	BOrganized.push_back(this->B->getV()[index]);
    	index+=this->colB;
    	if(index>=n){
    	set++;
    	index=set;   
    	}
    }    
    return BOrganized;
}
	
protected: std::vector<T> duplicateVectorB(){
	std::vector<T> duplicateB;
	int index=0;
	for(int i=0; i<2*this->B->getCol(); i++){
		duplicateB.push_back(this->B->getV()[index]);
		if(index>=this->B->getV().size()){
			index = -1;
		}
		index++;   
	}
	return duplicateB; 		
}
protected: std::vector<T> duplicateVectorA(){
	std::vector<T> duplicateA;

	
	return duplicateA;
}
public: std::vector<T> matrixMultiply(){
	this->reorganizeVectorB();
	//for(int i=0; i<)
}
};       
int main() { 
	MatrixMult<double> matrixMultiplierA(3,3,3,2);
    matrixMultiplierA.getA().printMatrix(); 
	matrixMultiplierA.getB().printMatrix();
	MatrixMult<int> matrixMultiplierB(3,3,3,2);
    matrixMultiplierB.getA().printMatrix(); 
	matrixMultiplierB.getB().printMatrix();		    
    return 0;
}

