#include"determinante.h"
void stampa(struct matrix *m) {
	for (size_t r = 0; r < m->rows; r++) {
		for (size_t c = 0; c < m->cols; c++) {
			printf("%lf ", m->data[r*m->cols + c]);
		}
		printf("\n");
	}
	printf("\n");


}
void T1(struct matrix *m, int i, int j) {
	double tmp;
	for (size_t c = 0; c < m->cols; c++) {
		tmp = m->data[i*m->cols + c];
		m->data[i*m->cols + c] = m->data[j*m->cols + c];
		m->data[j*m->cols + c] = tmp;
	}


}
void T2(struct matrix *m, int i, int j, double scalare) {
	for (size_t c = 0; c < m->cols; c++) {
		m->data[i*m->cols + c] = m->data[i*m->cols + c] + scalare * m->data[j*m->cols + c];
	}
}
void T3(struct matrix *m, int i, double scalare) {
	if (i >= 0 && i < m->cols) {
		for (size_t c = 0; c < m->cols; c++) {
			m->data[i*m->cols + c] = scalare * m->data[i*m->cols + c];
		}
	}
}


void determinante(struct matrix *m, double *det, bool *flag) {
	size_t rows = m->rows;
	size_t cols = m->cols;
	if (m != NULL) {
		if (rows != cols) {//la matrice non è quadrata
			flag = false;
		}
		else {
			if (rows == 2) {
				*det = (m->data[0] * m->data[1 * cols + 1]) - (m->data[0 * cols + 1] * m->data[1 * cols + 0]);
				flag = true;

			}
			else if (rows == 3) {//uso la formula di sarius
				double a, b;
				a = m->data[0] * m->data[4] * m->data[8] + m->data[1] * m->data[5] * m->data[6] + m->data[2] * m->data[3] * m->data[7];
				b = m->data[1] * m->data[3] * m->data[8] + m->data[0] * m->data[5] * m->data[7] + m->data[2] * m->data[4] * m->data[6];
				*det = a - b;
				flag = true;

			}
			else {//la matrice è quadrata di ordine maggiore di 3 uso l'algorithmo di gauss jordan
				int sgn = 1;
				struct matrix *out = malloc(sizeof(struct matrix));
				out->cols = cols;
				out->rows = rows;
				out->data = malloc(rows*cols * sizeof(double));
				for (size_t r = 0; r < rows; r++) {
					for (size_t c = 0; c < cols; c++) {
						out->data[r*cols + c] = m->data[r*cols + c];
					}
				}

				int count = 0;
				int p = 0;
				for (size_t r = 0; r < rows; r++) {

					if (out->data[r*cols + count] == 0) {
						p = r + 1;
						while (p < rows) {
							if (out->data[p*cols + count] != 0) {
								T1(out, r, p);
								sgn *= -1;
								stampa(out);
								break;

							}
							p++;
						}
					}

					if (p == rows) {
						continue;
						count++;
						stampa(out);

					}
					else {
						for (size_t c = r + 1; c < rows; c++) {
							T2(out, c, r, -(out->data[c*cols + count] / out->data[r*cols + count]));
						}
						stampa(out);
						count++;
					}

				}

				double ris = 1;
				for (size_t r = 0; r < rows; r++) {
					ris = ris * out->data[r*cols + r];
				}

				*det = ris * sgn;
				*flag = true;
				free(out->data);
				free(out);

			}
		}
	}


}