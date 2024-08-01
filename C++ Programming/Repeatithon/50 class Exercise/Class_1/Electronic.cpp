#include "Electronic.hpp"

void Get_Item(Electronic_Item* ptr){
	std::cout <<std::endl <<"DISPATCHED" <<std::endl;
	if(ptr)
		ptr->dispatch();
}

Electronic_Item* Inventory(size_t choice){
	Electronic_Item* ptr = 0;
	switch(choice){
		case 1:
			 ptr = Laptop_catlog();
			break;
			
		case 2:
			ptr = Mobile_catlog();
			break;
			
		default:
			break;
	}
	return (ptr);
}

Electronic_Item* Laptop_catlog(void){
	int choice;
	printf("List of all Laptop Catlog\n");
	printf("1.Dell Laptop\n2.Acer Laptop\n3.Lenovo Laptop\n4.Razor Laptop\n5.HP Lpatop\n");
	
	do{
		printf("Enter the Choice\n");
		scanf("%d", &choice);
	}while(choice < 0);
	
	srand(time(0));
	Electronic_Item* ptr = 0;
	switch(choice){
		case 1:
			 ptr = new Electronic_Item(rand(), "Dell Laptop");
			break;
		case 2:
			ptr = new Electronic_Item(rand(), "Acer Laptop");
			break;
		case 3:
			ptr = new Electronic_Item(rand(), "Lenovo Laptop");
			break;
		case 4:
			ptr = new Electronic_Item(rand(), "Razor Laptop");
			break;
		case 5:
			ptr = new Electronic_Item(rand(), "HP Laptop");
			break;
		default:
			break;
	}
	return (ptr);
}

Electronic_Item* Mobile_catlog(void){
	int choice;
	printf("List of all Laptop Catlog\n");
	printf("1.SAMSUNG\n2.APPLE\n3.MI\n4.ONEPLUS\n5.NOKIA\n");
	
	do{
		printf("Enter the Choice\n");
		scanf("%d", &choice);
	}while(choice < 0);
	
	Electronic_Item* ptr = 0;
	switch(choice){
		case 1:
			 ptr = new Electronic_Item(rand(), "SAMSUNG");
			break;
		case 2:
			ptr = new Electronic_Item(rand(), "APPLE");
			break;
		case 3:
			ptr = new Electronic_Item(rand(), "MI");
			break;
		case 4:
			ptr = new Electronic_Item(rand(), "ONEPLUS");
			break;
		case 5:
			ptr = new Electronic_Item(rand(), "NOKIA");
			break;
		default:
			break;
	}
	return (ptr);
}