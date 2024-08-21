#include <iostream>
#include <cstdio>
#include <cstdlib>

void run(void);
struct ref{
	int* ptr;
	int count;
};

class shallowCopy{
	private:
		struct ref* ref_ptr;
		int n;
	public:
		shallowCopy(int n_, int val) : ref_ptr(new ref), n(n_){
			ref_ptr->ptr = (int*)malloc(sizeof(int));
			if(ref_ptr->ptr == 0){
				std::cout <<"Error in allocating the meomary" <<std::endl;
				exit(EXIT_FAILURE);
			}
			*ref_ptr->ptr = val;
			ref_ptr->count = 1;
		}
		
		shallowCopy(const shallowCopy& rhs) : ref_ptr(rhs.ref_ptr), n(rhs.n){
			ref_ptr->count += 1;
		}

		shallowCopy& operator=(const shallowCopy& rhs){
			if(this != &rhs){
				ref_ptr->count -= 1;
				if(ref_ptr->count == 0){
					free(ref_ptr->ptr);
					free(ref_ptr);
				}
				n = rhs.n;
				ref_ptr = rhs.ref_ptr;
				ref_ptr->count += 1;
			}
			return *this;
		}

		friend std::ostream& operator<<(std::ostream& os, const shallowCopy& rhs){
			os<<"n = "<< rhs.n <<std::endl 
			  <<"ptr = "<< *rhs.ref_ptr->ptr <<std::endl;
			return os;
		}
		~shallowCopy(){
			std::cout <<"destroy object "<<ref_ptr->count<<std::endl;
			ref_ptr->count -= 1;
			if(ref_ptr->count == 0){
				free(ref_ptr->ptr);
				free(ref_ptr); 	 	
			}
		}
};

int main(void){
	run();
	std::cout <<"Programme terminated succesfully" <<std::endl;
	return 0;
}

void run(void){
	shallowCopy* s1 = new shallowCopy(100, 200); //Parameterised constructor
	shallowCopy* s2 = new shallowCopy(*s1); // Copy constructor
	shallowCopy* s3 = new shallowCopy(*s1); // Copy constructor
	
	std::cout <<"s1" <<std::endl	<< *s1 <<std::endl;
	std::cout <<"s2" <<std::endl	<< *s2 <<std::endl;
	std::cout <<"s3" <<std::endl	<< *s3 <<std::endl;

	delete s1;
	delete s2;
	delete s3;
}