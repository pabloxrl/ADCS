#include "geomagnetic_field/adcs_geomagnetic_field.h"

#include <stdio.h>
#include <stdbool.h>

#include <string.h>

#define EXPONENT_LENGTH           5
#define BASE_LENGTH               11
#define IGRF_COEFFICIENTS11_TXT   "src/geomagnetic_field/data/igrf11coeffs.txt"

double parse_exponent_number(char* str) {
  if (strcmp(str, "e+000") == 0) {
    return 1;
  }

  if (strcmp(str, "e+001") == 0) {
    return 10;
  }

  if (strcmp(str, "e+002") == 0) {
    return 100;
  }

  if (strcmp(str, "e+003") == 0) {
    return 1000;
  }

  if (strcmp(str, "e+004") == 0) {
    return 10000;
  }

  if (strcmp(str, "e-001") == 0) {
    return 0.1;
  }

  if (strcmp(str, "e-002") == 0) {
    return 0.01;
  }

  if (strcmp(str, "e-003") == 0) {
    return 0.001;
  }

  if (strcmp(str, "e-004") == 0) {
    return 0.0001;
  }

  return -1;
}

double parse_base_number(char* str) {
  double ret;
  sscanf(str, "%lf", &ret);

  return ret;
}

void parse_number(double* coefficients, char buffer[], size_t offset) {
  char base_number_str[BASE_LENGTH];
  char exponent_number_str[EXPONENT_LENGTH];
  char *pch;

  double base_number;
  double exponent_number;

  memset(base_number_str, 0, BASE_LENGTH);
  strncpy(base_number_str, buffer, strlen(buffer) - EXPONENT_LENGTH);

  base_number = parse_base_number(base_number_str);

  pch = strchr(buffer,'e');
  memset(exponent_number_str, 0, EXPONENT_LENGTH);
  strncpy(exponent_number_str, pch, EXPONENT_LENGTH);

  exponent_number = parse_exponent_number(exponent_number_str);

  coefficients[offset] = base_number * exponent_number;
}

ADCS_ERROR adcs_geomagnetic_field_get_igrf_coefficients(double* coefficients) {
  FILE *fp;
  char buffer[30];
  size_t n = 0;
  int ret;

  if (coefficients == NULL) {
    return ADCS_ERROR_NULLPARAM;
  }

  fp = fopen("src/geomagnetic_field/data/igrf11coeffs.txt", "r");
  if (fp == NULL) {
    return ADCS_ERROR_FILE_NOT_FOUND;
  }

  while (true) {
    ret = fscanf(fp, "%s", buffer);
    parse_number(coefficients, buffer, n++);

    if (ret == EOF) {
      fclose(fp);

      return ADCS_ERROR_NONE;
    }
  }
}
