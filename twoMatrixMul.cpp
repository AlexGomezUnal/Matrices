#include <iostream>
#include <vector>
#include <random>
#include <chrono>

template <typename T> 
class Matrix{
protected: std::vector<T> V;	
protected: int row; 
protected: int col;
public: int n = 100;

public: 
Matrix(int row, int col) {
	this->setRow(row); 
	this->setCol(col);
	this->createMatrixAsARandomVector(); 
}
public: void fillWithZeros(){
	for(int i=0; i<this->V.size(); i++) V.push_back(0);
} 

public: void setMatrix(std::vector<T> in){
	this->V = in; 

}  

public: void  setRow(int row){
	this->row = row;
}

public : int getRow(){
	return this->row;
}  
public: void setCol(int col){
	this->col = col;
}

public: int getCol(){
	return this->col; 
}
public: std::vector<T> getV(){
	return this->V; 
} 
protected: T getRandomValue() {

    if (std::is_same<T, int>::value) {
		std::random_device rd;
    	std::mt19937 gen(rd());
    	std::uniform_int_distribution<> dis(-this->n, this->n);
		return dis(gen); 
    } else if (std::is_same<T, double>::value) {
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_real_distribution<double> dis(-this->n, this->n);
		return dis(gen);
    } else {
		std::cout<<"Sorry not Suported bye"<<std::endl;
		exit(1);
        return T{};
    }
} 
protected: void createMatrixAsARandomVector(){ 

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
protected: Matrix<T> BorganizedB; 


public: 
MatrixMult(Matrix<T> Ain, Matrix<T> Bin) : A(Ain), B(Bin), BorganizedB(B.getRow(), B.getCol()){
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

public: std::vector<T> reorganizeVectorB() {
    int n = this->B.getV().size();
    std::vector<T> BOrganized;
    
    int set = 0;
    int index =0;   
    
    for (int i=0; i<n; i++) { 
    	BOrganized.push_back(this->B.getV()[index]);
    	index+=this->B.getCol();
    	if(index>=n){
    	set++;
    	index=set;   
    	}
    }    
    return BOrganized;
}
	
public: std::vector<T> duplicateVectorB(){
	this->BorganizedB.setMatrix(this->reorganizeVectorB());
	std::vector<T> duplicateB;
	int index=0;
	for(int i=0; i<(this->B.getV().size()*this->A.getRow()); i++){
		duplicateB.push_back(this->BorganizedB.getV()[index]);
		if(index == this->B.getV().size()-1){
			index = -1;
		}
		index++;
		   
	}
	return duplicateB; 		
}
public: std::vector<T> duplicateVectorA(){
	std::vector<T> duplicateA;

	int index =0;
	int count=0;
	for(int i=0;i<(this->B.getCol()*this->B.getRow()*this->A.getRow()); ++i){
		if(index%this->B.getRow() == 0 && index !=0){
			index -=(this->B.getRow());
			count++;
			if((count%this->B.getCol()) ==0 && count !=0){
				index = (count/(this->B.getCol()))*(this->B.getRow());
			}   
		}
		duplicateA.push_back(this->A.getV()[index]);
		index++;	   
	}		
	
	return duplicateA;
}
public: Matrix<T> matrixMultiply(){
	std::vector<T> DuplyA = this->duplicateVectorA();
	std::vector<T> DuplyB = this->duplicateVectorB();
	std::vector<T> products;

	Matrix<T> C(this->A.getRow(),this->B.getCol());

	T element =0;
	std::vector<T> result;  
	for(int i=0; i<=DuplyA.size(); i++){
		if(i%this->A.getCol() == 0 && i!=0){
			result.push_back(element);
			element=products[i];
			if(i%(this->A.getCol()*this->A.getRow())==0){
				element=0;
			}   
		}
		products.push_back(DuplyA[i]*DuplyB[i]);
		element+=products[i];

	}
	
	C.setMatrix(result);
	return C;    
}
};   
int main() { 
	auto start = std::chrono::steady_clock::now();
	Matrix<int> A(30,20);
	Matrix<int> B(20,30);
	MatrixMult<int> matrixMultiplierA(A,B);
	matrixMultiplierA.getA().printMatrix();
	matrixMultiplierA.getB().printMatrix();
	matrixMultiplierA.matrixMultiply();
    auto end = std::chrono::steady_clock::now();
	auto diff = end -start;
    std::cout<<std::chrono::duration <double, std::milli> (diff).count()<<" ms"<<std::endl;

	return 0;
}

