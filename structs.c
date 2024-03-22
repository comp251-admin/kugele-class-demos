#include <stdio.h>
#include <stdlib.h>

typedef struct name_s {
  char *given_name;
  char *family_name;
  char *preferred_name;
} name_t;

typedef struct student_s {
  name_t name;
  double gpa;
  char *admit_term;
  char *graduation_term;
  struct student_s *roommate;
} student_t;

/* void display_student(char *given_name, char *family_name, char
 *preferred_name, double gpa, char *admit_term, char *graduation_term); */

void display_student(student_t *student);
void hack_gpa(student_t *student, int gpa);

int main(void) {
  student_t morty;

  student_t *summer = malloc(sizeof(student_t));

  summer->name.given_name = "Summer";
  summer->name.family_name = "Smith";
  summer->name.preferred_name = "Summer";
  summer->gpa = 4.0;
  summer->admit_term = "Fall 2013";
  summer->graduation_term = "Spring 2015";

  /* student */
  morty.name.given_name = "Morty";
  morty.name.family_name = "Smith";
  morty.name.preferred_name = "Morty";
  morty.gpa = 1.75;
  morty.admit_term = "Fall 2013";
  morty.graduation_term = NULL;

  hack_gpa(&morty, 10.0);
  display_student(&morty);
  display_student(summer);

  return 0;
}

void display_student(student_t *student) {
  printf("[%s, %s, %s, %f, %s, %s]\n", student->name.given_name,
         student->name.family_name, student->name.preferred_name, student->gpa,
         student->admit_term, student->graduation_term);
}

void hack_gpa(student_t *student, int gpa) { student->gpa = gpa; }

/*
void display_student(char *given_name, char *family_name, char *preferred_name,
                     double gpa, char *admit_term, char *graduation_term) {
  printf("[%s, %s, %s, %f, %s, %s]\n", given_name, family_name, preferred_name,
         gpa, admit_term, graduation_term);
}*/
