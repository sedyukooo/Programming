#include <iostream>
using namespace std;
void create(int **arr, int len, int start = 0, int tosum = 0)
{
 *arr = new int[len];
 for (int i = 0; i < len; i++)
 {
  (*arr)[i] = start;
  start += tosum;
 }
}
int *sort(int *arr, int len)
{
 int *i, *last = arr + len;
 int ival;
 for (i = arr + 1; i < last; i++)
 {
  if (*i < *(i - 1))
  {
   for (ival = *i; i > arr && *(i - 1) > ival; i--)
   {
    *i = *(i - 1);
   }
   *i = ival;
  }
 }

 return arr;
}
int *print(int *arr, int len)
{
 if (len == 0)
  std::cout << "[]\n";
 std::cout << "[" << arr[0];
 for (int i = 1; i < len; i++)
 {
  std::cout << ',' << arr[i];
 }
 std::cout << "]\n";
 return arr;
}
void destroy(int **arr)
{
 if (!*arr)
 {
  delete[] * arr;
  *arr = nullptr;
 }
}

int main()
{
 int len, start, toplus;
 cin >> len >> start >> toplus;
 int *arr;
 create(&arr, len, start, toplus);
 sort(arr, len);
 print(arr, len);
 destroy(&arr);
}