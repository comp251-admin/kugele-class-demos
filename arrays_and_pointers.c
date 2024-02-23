#include <stdio.h>

int main(void) {
  int i_arr[5] = {0,1,2,3,4};
  int *i_ptr = i_arr;

  // check array addresses
  printf("i_arr: %p\n", i_arr);
  printf("&i_arr: %p\n", &i_arr);
  printf("&i_arr[0]: %p\n", &i_arr[0]);
  printf("&i_arr[1]: %p\n", &i_arr[1]);
  puts("");

  // check pointer addresses
  printf("i_ptr: %p\n", i_ptr);
  printf("&i_ptr: %p\n", &i_ptr);
  printf("&i_ptr[0]: %p\n", &i_ptr[0]);
  printf("&i_ptr[1]: %p\n", &i_ptr[1]);
  puts("");

  return 0;
}
