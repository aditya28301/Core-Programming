#include "PersonalCare.hpp"

void run(void){
	std::cout <<"CREATE INVENTORY = DONE" <<std::endl;
	char* list[] = {
        "Face Wash", "Micellar Water", "Cleansing Oil", "Exfoliating Cleanser",
        "Hydrating Toner", "Astringent Toner", "Refreshing Toner",
        "Facial Moisturizer", "Gel Moisturizer", "Night Cream", "Hydrating Serum",
        "SPF 30 Sunscreen", "SPF 50 Sunscreen", "Mineral Sunscreen", "Sunscreen Spray",
        "Acne Treatment", "Anti-Aging Serum", "Brightening Serum", "Retinol Cream",
        "Hydrating Mask", "Clay Mask", "Sheet Mask", "Overnight Mask",
        "Scrub", "Chemical Exfoliant", "Enzyme Peel",
        "Eye Cream", "Eye Serum", "Under-Eye Patch",
        "Lip Balm", "Lip Scrub", "Lip Treatment",
        "Spot Treatment", "Face Oil", "Facial Mist"
    };

	size_t size;
	size = sizeof(list) / sizeof(list[0]);

	std::cout <<"ADD ELEMENT FROM INVENTORY TO A CART = DONE" <<std::endl;
	personalcare* slot = new personalcare[size];
	addItem(slot, list, size);
	std::cout <<"DISPLAY ALL ITEM IN CART WISE = DONE" <<std::endl;
	print(slot, size);
	
	delete[] slot;
	slot = 0;
}

void print(personalcare* slot, size_t& size){
	for(size_t i = 0; i < size; ++i){
		print_with_delay(slot[i], 600);
	}
}
void addItem(personalcare* slot, char** list, size_t& size){
	for(size_t i = 0; i < size; ++i){
		(slot[i]).set(list[i]);
	}
}

void print_with_delay(const personalcare& item, int delay_ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    std::cout << item << std::endl;
}