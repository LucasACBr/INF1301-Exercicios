#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//Lucas Simões de Almeida - Matrícula 1712101

struct no 
{
	void *info;
	struct no *prox;
	struct no *ant;
};

struct lista {
	int tam;
	No *ini;
	No *fin;
	No *corr;
};



Lista * lst_cria(void)
{
	Lista * novo;
	novo = (Lista*)malloc(sizeof(Lista));
	if (novo == NULL)
	{
		exit(0);
	}
	novo->ini = NULL;
	novo->corr= NULL;
	novo->tam = 0;
	novo->fin = NULL;
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
	void *temp;
	No * p = (No*)malloc(sizeof(No));
	if (p==NULL)
	{
		exit(0);
	}
	p->info = cod;
	p->ant = NULL;
	p->prox = NULL;
	if (lst_vazia(lst)==1)
	{
		lst->ini = p;
		lst->fin = p;
	}
	else
	{
		temp = lst->ini;
		lst->ini->ant = p;
		lst->ini = p;
		lst->ini->prox = temp;
	}
	lst->tam++;
}

void lst_insFin(Lista * lst, void * cod)
{
	No * p = (No*)malloc(sizeof(No));
	if (p == NULL)
	{
		exit(0);
	}
	p->info = cod;
	p->ant = NULL;
	p->prox = NULL;
	if (lst_vazia(lst) == 1)
	{
		lst->ini = p;
		lst->fin = p;
	}
	else
	{
		p->ant = lst->fin;
		lst->fin->prox = p;
		lst->fin = p;
	}
	lst->tam++;
}

void *lst_retIni(Lista *lst) {

	void *valor_retirado = lst->fin->info;

	if (lst->tam == 1)
		lst->ini = NULL;

	else {
		lst->ini->prox->ant = NULL;
		lst->ini = lst->ini->prox;
		lst->tam--;
	}


	if (lst_vazia(lst))
		return NULL;

	return valor_retirado;
}

void *lst_retFin(Lista *lst) {

	void *valor_retirado = lst->fin->info;

	if (lst->tam == 1)
		lst->ini = NULL;

	else {
		lst->fin->ant->prox = NULL; 
		lst->fin = lst->fin->ant;
		lst->tam--;
	}


	if (lst_vazia(lst))
		return NULL;

	return valor_retirado;
}

void lst_posIni(Lista * lst)
{
	if (lst_vazia(lst) == 1)
	{
		lst->corr = NULL;
	}
	lst->corr = lst->ini;
}

void lst_posFin(Lista * lst)
{
	if (lst_vazia(lst) == 1)
	{
		lst->corr = NULL;
	}

	lst->corr = lst->fin;
}

void *lst_prox(Lista * lst)
{
	void * temp;
	if (lst->corr==NULL)
	{
		return NULL;
	}
	temp = lst->corr->info;
	lst->corr = lst->corr->prox;
	return temp;
}

void *lst_ant(Lista * lst)
{
		void * temp;
		if (lst->corr == NULL)
		{
			return NULL;
		}
		temp = lst->corr->info;
		lst->corr = lst->corr->ant;
		return temp;
}

void lst_libera(Lista * lst)
{
	lst_posIni(lst);
	while(lst_prox(lst)!=NULL)
	{
		free(lst->corr->info);
	}
	free(lst);
}

