#include <math.h>
#include <climits>
#include "point.h"

Point::Point(){
	size=0;
	value = NULL;
	isEvalCorrect=0;
};

Point::Point(int size){
	this->size=size;
	value = new float[size];
	for (int i = 0; i<size; ++i)
		value[i]=0;
	isEvalCorrect=0;
};


Point::Point(const Point * p){
	size=p->getSize();
	value = new float[size];
	for (int i = 0; i<size; ++i)
		value[i]=p->value[i];	
	eval=p->eval;
	isEvalCorrect=p->isEvalCorrect;
};

Point::Point(const Point & p){
	size=p.getSize();
	value = new float[size];
	for (int i = 0; i<size; ++i)
		value[i]=p.value[i];	
	eval=p.eval;
	isEvalCorrect=p.isEvalCorrect;
};

Point::~Point(){
	delete value;
}

int Point::getSize() const{
	return size;
}

float Point::getCoord(int i) const{
    // TODO throw exception in case of i>=size
    return value[i];
}
	
void Point::setCoord(int i, float val){
    // TODO throw exception in case of i>=size
    this->value[i]=val;
}

float Point::getEval() const {
    // TODO throw exception in case of isEvalCorrect=-=
    return eval;
}
	
void Point::evaluate() {
	//if (isEvalCorrect==0)
	{		
		
		//Rosenbrock function
		eval=0;
		for (int i = 0; i<size-1; ++i)
		{
			eval+=(1-value[i])*(1-value[i])
			    +100*(value[i+1]-value[i]*value[i])*(value[i+1]-value[i]*value[i]);
		}
		
		/*
		//Quadratic function
		eval=0;
		for (int i = 0; i<size; ++i)
		{
			eval+=value[i]*value[i];
		}
		*/
	}
	isEvalCorrect=1;
};

void Point::generateRandom(){
	for (int i = 0; i<size; ++i)
		value[i]=(float)(rand()%(2*RADIUS*PRECISION))/PRECISION-RADIUS;
};


bool Point::operator<(const Point& other) const {
    return getEval()<other.getEval();
}
    
std::ostream& operator<< (std::ostream &os, Point & p){
//	os<<"size="<<p.size<<"\n";	
	os<<"values=[";
	for (int i=0; i<p.getSize(); ++i)
	{
	os<<p.getCoord(i);
	if (i<p.getSize()-1) 
		os<<",";
	}
	os<<"]\t";
	os<<"eval="<<p.getEval()<<"\n";
	return os;
};


