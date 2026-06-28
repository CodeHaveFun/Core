#include <iostream>
#include <string>
#include <map>
std::map<std::string, int> myMap = {
    {"An", 1},
    {"Binh", 2},
    {"An", 3}  // Lưu ý: key trùng "An" sẽ ghi đè, chỉ giữ giá trị 3
};

std::string searchKey = "Anb";
int main(){
    if (myMap.count(searchKey) > 0) {
        std::cout << "Key '" << searchKey << "' TON TAI trong map" << std::endl;
        std::cout << "Gia tri: " << myMap[searchKey] << std::endl;
    } else {
        std::cout << "Key '" << searchKey << "' KHONG TON TAI" << std::endl;
    }
}
// Cách 1: Dùng count() - đơn giản nhất