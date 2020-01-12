#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <numeric>

using std::cout;
using std::cin;

int main()
{
    cout << "Zadaj pocet cisel:";
    int pocet = 100;
    int i = 1;
    //cin>>pocet;
    std::list<int> cisla(pocet);
    std::generate(cisla.begin(), cisla.end(), [&i]() { return ++i; });
    //std::copy(cisla.begin(), cisla.end(), std::ostream_iterator<int>(cout, " "));
    cout << std::endl;
    auto prvy = cisla.begin();
    while (prvy != cisla.end())
    {
        cout << *prvy << " ";
        cisla.remove_if([prvy](auto prvok) { return !(prvok % (*prvy)); });
        prvy = cisla.begin();
    }
    cisla.sort();
    cisla.unique();
/*  int sucet=std::accumulate(cisla.begin(),cisla.end(),0);
    int sucin=std::accumulate(cisla.begin(),cisla.end(),1,[](auto i,auto j){return i*j;});
    cout<<sucin<<" "<<sucet;*/
    return 0;
}
