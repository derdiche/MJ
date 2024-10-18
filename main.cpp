#include"./Moteur de rendu/MoteurRendu.h"
int main() {
    try{
        MoteurRendu mr;
        mr.lance();
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return -1; 
    }  
    return 0;
}

