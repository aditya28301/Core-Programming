#include "Electronic.hpp"

int main(void){
	int choice;
	srand(time(0));
	printf("1.Laptop Catlog\n2.Mobile Catlog\n");
	do{
		printf("Enter the Choice\n");
		scanf("%d", &choice);
	}while(choice < 0);
	
	Electronic_Item* ptr = 0;
	ptr = Inventory(choice);
	if(ptr != 0){
		Get_Item(ptr);
		delete ptr;
		ptr = 0;
	}
	puts("Terminated Succesfully");
	return 0;
}
