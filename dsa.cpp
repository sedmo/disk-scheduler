#include "dsa.h"
#include <algorithm> //std::sort
#include <map>
#include <set>


int h=0;
bool cmp(int a, int b);
int DSA::fcfs(){
	/*
	 * finds difference between previous arr val and new 
	 * sums differences as sol
	 * returns "sol" 
	 */
	int prev = this->head;
	int sol = 0;
	for(int i: reqs){
		sol += abs(prev - i);
		prev = i;
	}

	return sol;

};

int DSA::sstf(){
	/*
	 * sorts reqs array by the closest to this->head 
	 * then finds differences and returns
	 */
	array <int,REQ_SZ> c = reqs;
	h = this->head;
	
	sort(c.begin(), c.end(), cmp);
	int prev = this->head;			
	int sol = 0;
	for(int i: c){
		sol += abs(prev - i);
		prev = i;
	}

	return sol;
};

bool cmp(int a, int b){
	return abs(h - a) <  abs(h - b);
};
                int scan();
                int cscan();
                int look();
                int clook();

 
int DSA::scan(){
	/*
	 * runs for loop left then runs right til end
	 * if it matches a number, finds diff from prev hit
	 * returns sum of delta old hit current hit
	 */
	
	int prev = this->head;
	int sol = 0;
	set<int> my_set (reqs.begin(), reqs.end());
	for(int l = this->head; l > -1 ; --l){
		if( my_set.count(l) != 0){
			sol += abs(prev - l);		
			prev = l;
		}    

	}

	for(int r = this->head; r < C_SZ; r++){
		if( my_set.count(r) != 0){
			sol += abs(prev - r);		
			prev = r;
		}    
	
	}
	return sol;
}

int DSA::cscan(){
	//runs for loop right then start at 0 back to head
	
	int prev = this->head;
	int sol = 0;
	set<int> my_set (reqs.begin(), reqs.end());	

	for(int r = this->head; r < C_SZ; r++){
		if( my_set.count(r) != 0){
			sol += abs(prev - r);		
			prev = r;
		}    
	
	}

	for(int l = 0; l <= this->head; l++){
		if( my_set.count(l) != 0){
			sol += abs(prev - l);
			prev = l;
		}
	}

	return sol;
}

int DSA::look(){
	
	//look is bounded by smallest and largest elements in the string
	
	int prev = this->head;
        int sol = 0;
        set<int> my_set (reqs.begin(), reqs.end());
        for(int l = this->head; l > min(this->head, *my_set.begin() ) ; --l){
                if( my_set.count(l) != 0){
                        sol += abs(prev - l);
                        prev = l;
                }

        }

        for(int r = this->head; r < max(this->head, *my_set.end() ) ; r++){
                if( my_set.count(r) != 0){
                        sol += abs(prev - r);
                        prev = r;
                }

        }
        return sol;
}

int DSA::clook(){


	int prev = this->head;
        int sol = 0;
        set<int> my_set (reqs.begin(), reqs.end());
        
	for(int r = this->head; r < max(this->head, *my_set.end() ) ; r++){
                if( my_set.count(r) != 0){
                        sol += abs(prev - r);
                        prev = r;
                }

        }
	
	for(int l = min(this->head, *my_set.begin()); l < this->head; l++){
		if( my_set.count(l) != 0){
                        sol += abs(prev - l);
                        prev = l;
                }	
	} 

        return sol;
}

void DSA::print(){
	cout<<"FCFS algorithm: "<<fcfs()<<" cylinders."<<endl;
	cout<<"SSTF algorith: "<<sstf()<<" cylinders."<<endl;
	cout<<"SCAN algorithm: "<<scan()<<" cylinders."<<endl;
	cout<<"CSCAN algorithm: "<<cscan()<<" cylinders."<<endl;
}
