#include <iostream>
#include <cstdlib>

class base{
	private:
		int b_pi_a;
	protected:
		int b_pro_a;
	public:
		int b_pu_a;

	base() : b_pi_a(100), b_pro_a(200), b_pu_a(300){  std::cout <<"Base class default constructor" << std::endl;}

	void show(){
		std::cout <<"---------------BASE CLASS------------------" << std::endl;
		std::cout <<"public member = " << b_pu_a << std::endl;
		std::cout <<"Protected member = " << b_pro_a << std::endl;
		std::cout <<"Private member = " << b_pi_a << std::endl; 
		std::cout <<"-------------------------------------------"<< std::endl;
	}
};

class derived : private base{
	
	private:	
		int d_pi_a;
	protected:
		int d_pro_a;
	public:
		int d_pu_a;

	derived() : d_pi_a(1000), d_pro_a(2000), d_pu_a(3000){ std::cout <<"Derived class constructor" << std::endl;} 
	void show(){
	
		std::cout <<"-----------DERIVED CLASS----------------" << std::endl;
		std::cout <<"public member = " << d_pu_a << std::endl;
                std::cout <<"Protected member = " << d_pro_a << std::endl;
                std::cout <<"Private member = " << d_pi_a << std::endl;
		std::cout <<"----------------------------------------" << std::endl;		

		

		std::cout <<"-----------BASE CLASS----------------" << std::endl;
                std::cout <<"public member = " << b_pu_a << std::endl;
               	std::cout <<"Protected member = " << b_pro_a << std::endl;
                //std::cout <<"Private member = " << b_pi_a << std::endl;
                std::cout <<"----------------------------------------" << std::endl;	
	}
	
};

class iDerived : private derived{

	private:
                int id_pi_a;
        protected:
                int id_pro_a;
        public:
                int id_pu_a;

	iDerived() : id_pi_a(1), id_pro_a(2), id_pu_a(3) { std::cout <<"IDerived class constructor" << std::endl; } 
		void show(){
	 	std::cout <<"-----------iDERIVED CLASS----------------" << std::endl;
                std::cout <<"public member = " << id_pu_a << std::endl;
                std::cout <<"Protected member = " << id_pro_a << std::endl;
                std::cout <<"Private member = " << id_pi_a << std::endl;
                std::cout <<"----------------------------------------" << std::endl;
	
		std::cout <<"-----------DERIVED CLASS----------------" << std::endl;
                std::cout <<"public member = " << d_pu_a << std::endl;
                std::cout <<"Protected member = " << d_pro_a << std::endl;
                //std::cout <<"Private member = " << d_pi_a << std::endl;
                std::cout <<"----------------------------------------" << std::endl;	
	
                std::cout <<"-----------BASE CLASS----------------" << std::endl;
                //std::cout <<"public member = " << b_pu_a << std::endl;
                //std::cout <<"Protected member = " << b_pro_a << std::endl;
                //std::cout <<"Private member = " << b_pi_a << std::endl;
                std::cout <<"----------------------------------------" << std::endl;
		}
};

/*class iDerived : public base{

}; std::cout <<"-----------DERIVED CLASS----------------" << std::endl;
                std::cout <<"public member = " << d_pu_a << std::endl;
                std::cout <<"Protected member = " << d_pro_a << std::endl;
                std::cout <<"Private member = " << d_pi_a << std::endl;
                std::cout <<"----------------------------------------" << std::endl;

                std::cout <<"-----------BASE CLASS----------------" << std::endl;
                std::cout <<"public member = " << b_pi_a << std::endl;
                std::cout <<"Protected member = " << b_pro_a << std::endl;
                std::cout <<"Private member = " << b_pi_a << std::endl;
                std::cout <<"----------------------------------------" << std::endl;

*/


int main(void){

	derived ibj;
	ibj.show();

	iDerived obj;

	obj.show();
	return EXIT_SUCCESS;
}







