#include <riscv_vector.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>

#define MAX_ARRAY_SIZE 1000000

#define MAX_SIZE 1024 // Maximum size of the array to generate

// Helper function to generate random float data
void generate_random_array(float *arr, size_t size) {
  for (size_t i = 0; i < size; i++) {
    arr[i] =
        (float)rand() / RAND_MAX * 2.0f - 1.0f; // Values between -1.0 and 1.0
  }
}

// SAXPY operation for vector processing
void saxpy_vec(size_t n, const float a, const float *x, float *y) {
  for (size_t vl; n > 0; n -= vl, x += vl, y += vl) {
    vl = __riscv_vsetvl_e32m8(n);
    vfloat32m8_t vx = __riscv_vle32_v_f32m8(x, vl);
    vfloat32m8_t vy = __riscv_vle32_v_f32m8(y, vl);
    __riscv_vse32_v_f32m8(y, __riscv_vfmacc_vf_f32m8(vy, a, vx, vl), vl);
  }
}

// Function to measure clock cycles using clock()
uint64_t measure_time_clock(void (*func)(size_t, const float, const float *,
                                         float *),
                            size_t n, const float a, const float *x, float *y) {
  clock_t start, end;

  // Start the clock
  start = clock();

  // Execute SAXPY operation
  func(n, a, x, y);

  // Stop the clock
  end = clock();

  // Calculate elapsed time in seconds
  uint64_t elapsed_time = ((double)(end - start)) * CLOCKS_PER_SEC;
  return elapsed_time;
}

void saxpy_normal(size_t n, const float a, const float *x, float *y) {
  for (size_t i = 0; i < n; i++) {
    y[i] = a * x[i] + y[i];
  }
}

int main() {
  srand(time(NULL));
  size_t n = 70;
  printf("Array size: %zu\n", n);

  // Allocate memory for arrays
  float *x = (float *)malloc(n * sizeof(float));
  float *y = (float *)malloc(n * sizeof(float));
  float *y_normal =
      (float *)malloc(n * sizeof(float)); // Copy of y for normal operation

  // Initialize arrays with random data
  generate_random_array(x, n);
  generate_random_array(y, n);
  for (size_t i = 0; i < n; i++) {
    y_normal[i] = y[i]; // Copy y to y_normal for comparison
  }
  // Measure time for vectorized SAXPY operation using cycles
  uint64_t vector_cycles = measure_time_clock(saxpy_vec, n, 2.0f, x, y);

  // Measure time for normal SAXPY operation using cycles
  uint64_t normal_cycles =
      measure_time_clock(saxpy_normal, n, 2.0f, x, y_normal);

  // Display the results
  printf("Cycles taken for normal SAXPY is around: %lu cycles\n",
         normal_cycles);
  printf("Cycles taken for vectorized SAXPY is around: %lu cycles\n",
         vector_cycles);

  // Clean up
  free(x);
  free(y);
  free(y_normal);

  return 0;
}
