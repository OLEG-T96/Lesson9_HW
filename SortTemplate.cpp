#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template<typename T>
static bool PrintMass( T const *Arr, unsigned ArrSize)
{
    if(Arr == nullptr)
      {
        return false;
      }

    for(unsigned i = 0; i < ArrSize; ++i)
      {
        cout<< Arr[i] << " ";
      }
    cout<< endl;
    return true;
}

template<typename T>
static bool FillRandMass (T *Arr, unsigned ArrSize)
{
    if(Arr == nullptr)
      {
        return false;
      }
    for(unsigned i = 0; i < ArrSize; ++i)
       {
          Arr[i] =(rand() % 100000) / 1000.0;
       }
    return true;
}

template<typename T>
static bool BubbleSort(T *Arr, unsigned ArrSize)
{
    if(Arr == nullptr)
      {
        return false;
      }

    for(unsigned j = 1; j < (ArrSize-1); ++j)
       {
         for(unsigned i = 0; i < (ArrSize - j); ++i)
            {
              if(Arr[i] > Arr[i+1] )
                {
                  std::swap(Arr[i],Arr[i+1]);
                }
            }
       }
    return true;
}

int main()
{
    constexpr unsigned size = 10;
    int i_mass[size];
    FillRandMass(i_mass,size);
    PrintMass(i_mass,size);
    BubbleSort(i_mass,size);
    PrintMass(i_mass,size);
    cout<< endl;
    float f_mass[size];
    FillRandMass(f_mass,size);
    PrintMass(f_mass,size);
    BubbleSort(f_mass,size);
    PrintMass(f_mass,size);
    return 0;
}
