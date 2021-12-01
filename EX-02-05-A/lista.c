#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define tamVetor 10 //Nao sabia se podia usar o tamanho do vetor como argumento, acabei fazendo um define para implementar melhor o codigo

//Lucas Simões de Almeida - Matrícula 1712101


struct lista {
	int tam;
	void **vet;
	int ini, fin, corr;
};


Lista * lst_cria(void)
{
	Lista * novo;
	void ** v;
	int i = 0;
	novo = (Lista*)malloc(sizeof(Lista));
	if (novo == NULL)
	{
		exit(0);
	}

	v = malloc(sizeof(void*) * 10);
	if (v == NULL)
	{
		exit(0);
	}
	for (int i = 0; i < tamVetor - 1; i++)
	{
		v[i] = NULL;
	}
	novo->vet = v;
	novo->tam = 0;
	novo->ini = 0;
	novo->fin = 0;
	novo->corr = -1;

	return novo;
}

int lst_vazia(Lista* lst)
{
	if (lst->tam == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void lst_insIni(Lista * lst, void * cod)
{
	int i = 0;

	if (lst_vazia(lst) == 1)
	{
		lst->ini = lst->fin;
		lst->vet[lst->ini] = cod;
	}
	else
	{
		while (i != lst->ini - 1)
		{
			i++;
		}
		lst->ini = i;
		lst->vet[lst->ini] = cod;
	}
	lst->tam++;
}

void lst_insFin(Lista * lst, void * cod)
{
	int i = tamVetor - 1;

	if (lst_vazia(lst)==1)
	{
		lst->fin = lst->ini;
		lst->vet[lst->fin] = cod;
	}
	else
	{
		i = tamVetor - 1;
		while (i != lst->fin + 1)
		{
			i--;
		}
		lst->fin = i;
		lst->vet[lst->fin] = cod;
	}
	lst->tam++;
}

void *lst_retIni(Lista *lst) {

	void *valor_retirado = lst->vet[lst->ini];

	if (lst->tam == 1)
	{
		lst->vet[lst->ini] = NULL;
		lst->vet[lst->fin] = NULL;
	}

	else 
	{
		lst->vet[lst->ini] = lst->vet[lst->ini + 1];
	}


	if (lst_vazia(lst))
		return NULL;
	lst->tam--;
	lst->ini++;

	return valor_retirado;
}

void *lst_retFin(Lista *lst) {

	void *valor_retirado = lst->vet[lst->fin];

	if (lst->tam == 1)
	{
		lst->vet[lst->ini] = NULL;
		lst->vet[lst->fin] = NULL;
	}

	else 
	{
		lst->vet[lst->fin] = lst->vet[lst->fin - 1];
	}


	if (lst_vazia(lst))
		return NULL;
	lst->tam--;
	lst->fin--;

	return valor_retirado;
}

void lst_posIni(Lista * lst)
{
	if (lst_vazia(lst) == 1)
	{
		lst->corr = -1;
	}
	lst->corr = lst->ini;
}

void lst_posFin(Lista * lst)
{
	if (lst_vazia(lst) == 1)
	{
		lst->corr = -1;
	}

	lst->corr = lst->fin;
}

void *lst_prox(Lista * lst)
{
	void * temp;
	if (lst->corr == -1)
	{
		return NULL;
	}

	if (lst->vet[lst->corr]==NULL || lst->corr>lst->fin)
	{
		return NULL;
	}
	else
	{
		temp = lst->vet[lst->corr];
		lst->corr++;
	}

	return temp;
}

void *lst_ant(Lista * lst)
{
	void * temp;
	if (lst->corr == -1)
	{
		return NULL;
	}

	if (lst->vet[lst->corr] == NULL || lst->corr < lst->ini)
	{
		return NULL;
	}
	else
	{
		temp = lst->vet[lst->corr];
		lst->corr--;
	}

	return temp;
}

void lst_libera(Lista * lst)
{
	int i = 0;
	lst_posIni(lst);
	while (lst_prox(lst) != NULL)
	{
		free(lst->vet[i]);
		i++;
	}
	free(lst);
}

