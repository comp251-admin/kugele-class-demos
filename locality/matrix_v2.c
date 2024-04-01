#include <stdio.h>
#include <time.h>

#define N 10000
double m[N][N];

double avg(void) {
  double total = 0.0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      total += m[j][i];
    }
  }

  return total / (N * N);
}

int main(int argc, char **argv) {
  struct timespec ts1, ts2;
  double start, now, ret;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      m[i][j] = i + j;
    }
  }

  clock_gettime(CLOCK_MONOTONIC, &ts1);

  ret = avg();

  clock_gettime(CLOCK_MONOTONIC, &ts2);

  // convert to milliseconds
  start = (1000.0 * ts1.tv_sec) + (ts1.tv_nsec / 1000000.0);
  now = (1000.0 * ts2.tv_sec) + (ts2.tv_nsec / 1000000.0);

  printf("ji average time: %7.4f ms (average: %7.4f)\n", now - start, ret);

  return 0;
}
