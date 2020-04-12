
#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

//#define _CRT_SECURE_NO_WARNINGS
#define MAX 10

typedef struct polynomial                                               //
{
	int coef;
	int expon;
	struct polynomial* link;
}polynomial;

typedef struct polynomial_h                                               //
{
	int size;
	struct polynomial* h_link;
}polynomial_h;

polynomial_h* create_h()                                               //
{
	polynomial_h* temp = (polynomial_h*)malloc(sizeof(polynomial_h));
	return temp;
}

polynomial* create()                                                   //
{
	polynomial* temp = (polynomial*)malloc(MAX * sizeof(polynomial));
	if (temp == NULL)
	{
		printf("\n malloc error!\n"); exit;
	}
	else
	{
		printf("\n temp address=%d\n", temp);
	}
	temp->coef = 0;
	temp->expon = 0;
	temp->link = NULL;
	return temp;
}

void initialize_h(polynomial_h* init)
{
	init->h_link = NULL;
	init->size = 0;
}

void initialize(polynomial* init)
{
	init->coef = 0;
	init->expon = 0;
	init->link = NULL;
}

int free_memory_h(polynomial_h* del)
{
	free(del);
	return 1;
}

void free_memory(polynomial* del)                                       //
{
	free(del);
}

void display(polynomial_h* disp)                                           //
{
	int p = 0;
	polynomial_h* temp;
	temp = disp;

	for (p; p < disp->size; p++)
	{
		printf("\n\n");
		printf("%d x^%d\n", temp->h_link->coef, temp->h_link->expon);
		temp->h_link = temp->h_link->link;
	}
}

void poly_add(polynomial_h* a_h, polynomial_h* b_h, polynomial_h* c_h)
{
	int ia = 0;
	int ib = 0;
	int ic = 0;

	polynomial_h* temp_a = create_h();
	polynomial_h* temp_b = create_h();
	polynomial_h* temp_c = create_h();

	temp_a = a_h;
	temp_a = a_h;

	while (ia < a_h->size && ib < b_h->size)
	{
		if (temp_a->h_link->expon > temp_b->h_link->expon)
		{
			temp_c->h_link->expon = temp_a->h_link->expon;
			temp_c->h_link->coef = temp_a->h_link->coef;
			temp_a->h_link = temp_a->h_link->link;
			ia++;
			ic++;
		}
		else if (temp_a->h_link->expon == temp_b->h_link->expon)
		{
			temp_c->h_link->expon = temp_a->h_link->expon + temp_b->h_link->expon;
			temp_c->h_link->coef = temp_a->h_link->coef + temp_b->h_link->coef;
			temp_a->h_link = temp_a->h_link->link;
			temp_b->h_link = temp_b->h_link->link;
			ia++;
			ib++;
			ic++;
		}
		else if (temp_a->h_link->expon < temp_b->h_link->expon)
		{
			temp_c->h_link->expon = temp_b->h_link->expon;
			temp_c->h_link->coef = temp_b->h_link->coef;
			temp_b->h_link = temp_b->h_link->link;
			ib++;
			ic++;
		}
		while (ia < a_h->size)
		{
			temp_c->h_link->expon = temp_a->h_link->expon;
			temp_c->h_link->coef = temp_a->h_link->coef;
			temp_a->h_link = temp_a->h_link->link;
			ia++;
			ic++;
		}
		while (ib < b_h->size)
		{
			temp_c->h_link->expon = temp_b->h_link->expon;
			temp_c->h_link->coef = temp_b->h_link->coef;
			temp_b->h_link = temp_b->h_link->link;
			ib++;
			ic++;
		}
		temp_c->size = ic;
		c_h = temp_c;
	}

}

void poly_multiply(polynomial_h* a, polynomial_h* b, polynomial_h* d)
{
	int ia = 0;
	int ib = 0;
	int id = 0;

}

int main()
{
	polynomial_h* a_head = create_h();
	polynomial_h* b_head = create_h();
	polynomial_h* c_head = create_h();
	polynomial_h* d_head = create_h();

	initialize_h(a_head);
	initialize_h(b_head);
	initialize_h(c_head);
	initialize_h(d_head);

	polynomial* a = create();
	printf("DONE2\n");
	printf("%d\n", a);
	if (a == NULL)
	{
		printf("malloc error\n");
	}
	polynomial* b = create();
	polynomial* c = (polynomial*)malloc(2 * MAX * sizeof(polynomial));
	polynomial* d = (polynomial*)malloc(MAX * MAX * sizeof(polynomial));

	initialize(a);
	initialize(b);
	initialize(c);
	initialize(d);

	printf("%d\n%d\n%d\n%d\n", a, a->coef, a->expon, a->link);

	a_head->h_link = a;
	b_head->h_link = b;
	c_head->h_link = c;
	d_head->h_link = d;

	printf("\n%d\n", a_head->h_link);

	FILE* fp;
	FILE* fq;
	fp = fopen("input.txt", "rt");
	fq = fopen("input.txt", "rb");                                   //

	int txt[MAX * 2];
	char bin[MAX * 10];

	int it = 0;
	int iq = 0;
	int k = 0;
	int k_5;
	int n = 0;
	int o;
	int p;
	int* temp = NULL;

	int a_address;

	while (!feof(fp))
	{
		fscanf(fp, "%d", &txt[it]);
		it++;
	}
	while (!feof(fq))
	{
		fscanf(fq, "%c", &bin[iq]);
		iq++;
	}

	for (k; k < MAX * 10; k++)
	{
		if (bin[k] == '\n' && bin[k + 2] == '\n')
			break;
	}

	k_5 = (k + 1) / 5;                                                           //

	printf("\n%d\n", txt[0]);
	int test;
	test = txt[2 * n];
	printf("\n---->>>>%d\n", test);

	for (n = 0; n < k_5; n++)
	{
		a->coef = txt[2 * n]; // ????
		a->expon = txt[2 * n + 1];
		a = a->link;
	}
	a_head->size = n;
}