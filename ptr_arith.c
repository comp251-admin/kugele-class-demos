#include <stdio.h>

int main(void){
  int i; // counter var

  // statically allocated char array
  char c_arr[5] = {'a','b','c','d','e'};
  char *c_ptr = c_arr;

  // statically allocated int array
  int i_arr[5] = {0,1,2,3,4};
  int *i_ptr = i_arr;

  printf("c_arr: %d\n", c_arr);
  printf("c_ptr: %p\n", c_ptr);
  for (i = 0; i < 5; i++) {
    printf("c_ptr + %d: %p\t", i, c_ptr + i);
    printf("*(c_ptr + %d): %c\t\t", i, *(c_ptr + i));
    printf("c_ptr[%d]: %c\n", i, c_ptr[i]);
  }

  puts("");

  printf("i_arr: %p\n", i_arr);
  printf("i_ptr: %p\n", i_ptr);
  for (i = 0; i < 5; i++) {
    printf("i_ptr + %d: %p\t", i, i_ptr + i);
    printf("*(i_ptr + %d): %d\t\t", i, *(i_ptr + i));
    printf("i_ptr[%d]: %d\n", i, i_ptr[i]);
  }

  return 0;
}
