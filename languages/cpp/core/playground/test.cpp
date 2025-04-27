#include <iostream>
#include <unistd.h>

void realocate(int* ptr, int num){
    delete ptr;
    ptr=new int;
    *ptr = num;
    std::cout<<"inside func ptr"<<*ptr<<" adress of ptr - "<<&ptr<<" adress of ptr value - "<<ptr<<std::endl;
}

int main(){
    //original ptr
    int* ptr = new int;
    *ptr = 3;
    std::cout<<"original ptr val "<<*ptr<<" adress of ptr - "<<&ptr<<" adress of ptr value - "<<ptr<<std::endl;
    //int* temp = new int;
    //*temp = 100;

    realocate(ptr, 22);
    
    //delete temp;
    std::cout<<"after relocate ptr"<<*ptr<<" adress of ptr - "<<&ptr<<" adress of ptr value - "<<ptr<<std::endl;
    delete ptr;
    std::cout<<"11";
    return 0;
}