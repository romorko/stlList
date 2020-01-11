#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using std::cout;
using std::cin;

int main()
{
    cout<<"Zadaj pocet cisel:";
    int pocet=50;
    int i=1;
    //cin>>pocet;
    std::list<int> cisla(pocet);
    std::generate(cisla.begin(),cisla.end(),[&i](){return ++i;});
    std::copy(cisla.begin(),cisla.end(),std::ostream_iterator<int>(cout," "));
    cout<<std::endl;
    auto prvy =cisla.begin();
    while(prvy!=cisla.end())
    {
        cout<<*prvy<<" ";
        cisla.remove_if([prvy](auto prvok){return prvok%(*prvy)==0;});
        //std::copy(cisla.begin(),cisla.end(),std::ostream_iterator<int>(cout," "));
        //cout<<std::endl;
        prvy=cisla.begin();
    }
    std::copy(cisla.begin(),cisla.end(),std::ostream_iterator<int>(cout," "));
return 0;
}
