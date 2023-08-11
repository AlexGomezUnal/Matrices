#include <iostream>
#include <vector>
#include <time.h>

template <typename T> 
class MatrixMult{ 
const long max_rand = 1000000L;
protected: std::vector<T> A;
protected: std::vector<T> B; 
protected: int rowA; 
protected: int rowB;
protected: int colA;
protected: int colB;


public: MatrixMult(int RowA, int ColA, int RowB, int ColB){
	this->setRowA(RowA);
	this->setColA(ColA);
	this->setRowB(RowB);
	this->setColB(ColB);
	if (this->checkMult()){ 
	this->twoMatrixRandomInit();
	}else{
	std::cout<<"Sorry not possible to Compute Try Again"<<std::endl;
	exit(1); 
	}
	 	
} 
public: std::vector<T> getA(){
	return this->A;
} 
public: std::vector<T> getB(){
	return this->B;
}
protected: void  setRowA(int row){
	this->rowA = row;
}

protected: void setRowB(int row){
	this->rowB = row;
}

protected: void setColA(int col){
	this->colA = col;
}

protected: void setColB(int col){
	this->colB = col;
}  
protected: std::vector<T> createMatrixAsAVector(int row, int col){
	std::vector<T> MatrixAsVector;

    T lowerBound = 0;
    T upperBound = 1000;
 
    srand(time(NULL));

    for(int i=0; i<row*col; i++){
    T randomNumber = lowerBound + (upperBound - lowerBound)* (rand() % max_rand)/ max_rand;
    MatrixAsVector.push_back(randomNumber);
    }

    return MatrixAsVector; 	
}  
protected: bool checkMult(){
	return this->rowB == this->colA;
} 

public: void twoMatrixRandomInit(){
	this->A = this->createMatrixAsAVector(rowA,colA); 
	this->B = this->createMatrixAsAVector(rowB,colB);
	
}     
protected: std::vector<T> reorganizeVectorB() {
    int n = this->B->size();
    std::vector<T> BOrganized;
    
    int set = 0;
    int index =0;   
    
    for (int i=0; i<n; i++) { 
    	BOrganized.push_back(this->B[index]);
    	index+=this->colB;
    	if(index>=n){
    	set++;
    	index=set;   
    	}
    }    
    return BOrganized;
}
public: void printMatrix(std::vector<T> v,int col){
	int index=0;
	for(T num:v){
		index++;
		std::cout<<num<<" ";
		if(index%col == 0) std::cout<<std::endl;
} 
	
}
protected: std::vector<T> duplicateVectorB(){
	std::vector<T> duplicateB;
	int index=0;
	for(int i=0; i<2*colB; i++){
		duplicateB.push_back(this->B[index]);
		if(index>=this->B->size()){
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
	MatrixMult<int> matrixMultipliyer(3,3,3,2);
		    
    return 0;
}

