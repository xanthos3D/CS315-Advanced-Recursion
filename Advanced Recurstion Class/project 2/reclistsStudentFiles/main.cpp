#include<iostream>
#include"reclists.hpp"
#include"solutions.hpp"

int main()
{

    std::cout << "Enter list #1: ";
    list p = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(p);
    std::cout << "Enter a list #2: ";
    list q = read_list();
    std::cout << "Echoing the list that you entered below." << std::endl;
    write_list(q);
    std::cout<< std::endl;

    /*std::cout << "testing is_lat ";
    std::cout<< is_lat(p) << std::endl;*/

    /*std::cout << "testing Member ";
    std::cout<<  member(p, q) << std::endl;*/

    /*std::cout << "testing Last ";
    write_list(last(p));
    std::cout<< std::endl;*/

    /*std::cout << "testing list_pair ";
    write_list(list_pair(p,q));
    std::cout<< std::endl;*/

    /*std::cout << "testing first ";
    write_list(firsts(p));
    std::cout<< std::endl;*/

    /*std::cout << "testing flat ";
    write_list(flat(p));
    std::cout<< std::endl;*/

    std::cout << "testing two_the_same ";
    std::cout<<  two_the_same(p, q) << std::endl;

    /*std::cout << "testing equal ";
    std::cout<< equal(p,q) << std::endl;*/

     /*std::cout << "testing total_reverse ";
     write_list(total_reverse(p));
     std::cout<< std::endl;*/

    /*std::cout << "testing shape ";
    write_list(shape(p));
    std::cout<< std::endl;*/

   /*std::cout << "testing intersection ";
    write_list(intersection(p,q));
    std::cout<< std::endl;*/

     /*std::cout << "testing list_union ";
    write_list(list_union(p,q));
    std::cout<< std::endl;*/




    return 0;
}
