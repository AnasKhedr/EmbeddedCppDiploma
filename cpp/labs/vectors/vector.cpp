#include <iostream>
#include <vector>

//STL Container : Vector its a dynmically allocated , size? is variable in runtime
//STL : to push and pop
//Iterators 

void outputVector(const std::vector<int> &vec)
{
  for(int temp : vec)
    {
        std::cout << temp << std::endl;
    }
}

void inputVector(std::vector<int> &vec)
{
    for(int &item : vec) 
    {
        std::cin >> item ;
    }
}

int main()
{
    std::vector<int> v(3);

    inputVector(v);
    std::cout <<"Vector's size: " << v.size() << " capacity: "<< v.capacity() << std::endl;

    v.push_back(9);
    v.push_back(15);

    outputVector(v);
    
    std::cout <<"Vector's size: " << v.size() << " capacity: "<< v.capacity() << std::endl;
    v.push_back(17);
    v.push_back(18);
    std::cout <<"Vector's size: " << v.size() << " capacity: "<< v.capacity() << std::endl;

    return 0;
}