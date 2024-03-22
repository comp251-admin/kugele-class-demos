#include <stdio.h>
#include <stdlib.h>

typedef enum dir_e { LEFT, RIGHT, STRAIGHT, STOP } dir_t;

typedef struct intersect_s {
  char *id;
  char *desc;
} intersect_t;

typedef struct step_s {
  intersect_t inter;
  dir_t dir;
  struct step_s *next;
} step_t;

void display_route(step_t *route) {
  for (step_t *curr = route; curr != NULL; curr = curr->next) {
    printf("%s [%d]\n", curr->inter.desc, curr->dir);
  }
}

void insert_after(step_t *loc, step_t *new_next) {
  new_next->next = loc->next;
  loc->next = new_next;
}

void remove_after(step_t *loc) {
  if (loc->next) {
    loc->next = loc->next->next;
  }
}

int main(void) {
  intersect_t a = {"a", "Bailey Ln and University St"};
  intersect_t b = {"b", "University St and Jackson"};
  intersect_t c = {"c", "Jackson and N. Watkins"};
  intersect_t d = {"d", "N. Watkins and Galloway"};
  intersect_t e = {"e", "N. Watkins and Concourse Ave."};
  intersect_t f = {"f", "Jackson and McLean Ave."};

  step_t step1 = {a, RIGHT, NULL};
  step_t step2a = {b, LEFT, NULL};
  step_t step2b = {f, STRAIGHT, NULL};
  step_t step3 = {c, LEFT, NULL};
  step_t step4 = {d, STRAIGHT, NULL};
  step_t step5 = {e, STOP, NULL};

  insert_after(&step1, &step2a);
  insert_after(&step2a, &step2b);
  insert_after(&step2b, &step3);
  insert_after(&step3, &step4);
  insert_after(&step4, &step5);

  printf("before removal:\n");
  display_route(&step1);

  remove_after(&step2a);
  printf("after removal:\n");

  display_route(&step1);

  return 0;
}
