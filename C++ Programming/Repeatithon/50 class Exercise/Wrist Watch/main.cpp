#include "Watch.hpp"

int main(void){
    Watch new_watch(
                    "Fastrack New Limitless X2 Smartwatch",
                    9,
                    "Android",
                    {"Multisport Tracker", "Activity Tracker", "Phone Call", "Stress Tracking", "Heart Rate Monitor"},
                    "Bluetooth",
                    "Bluetooth",
                    "Lithum Polymer",
                    "Fastrack Limitless X2 comes with 1.91 UltraVU HD Display, Working Crown and a bright Pixel Resolution Enjoy a faster and smooth navigation like never before with 60 Hz Refresh Rate Superior Connectivity with Advanced Chipset and SingleSync BT Calling with Favourite Contacts storage and Quick Replies (Android)",
                    100000.00,
                    {"Google Pay", "Debit Card", "Phone Pay", "Credit Card"},
                    {"30% off", "50% off", "75% off","100% off"},
                    "USA London",
                    "Jackey Shroff",
                    191379,
                    "9.2 x 9.2 x 9 cm; 48 g",
                    "1080p",
                    "LCD"
                );
    std::cout<< new_watch << std::endl;
    std::cout <<"Programe terminated sucesfully";
    return EXIT_SUCCESS;
}