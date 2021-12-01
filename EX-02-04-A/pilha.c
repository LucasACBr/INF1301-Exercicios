//Lucas Simoes de Almeida - 1712101

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"

struct pilha {
	Lista* lst;
};Pilha *pilha_cria(void)
{
	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
	p->lst = lst_cria();
	return p;
}

int pilha_vazia(Pilha *p)
{
	if (lst_vazia(p->lst) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void pilha_push(Pilha* p, void *v)
{
	lst_posIni(p->lst);
	lst_insIni(p->lst, v);
}

void *pilha_pop(Pilha* p)
{
	void *valor_retirado;
	if (pilha_vazia(p) == 1)
	{
		return NULL;
	}
	else
	{
		valor_retirado = lst_retIni(p->lst);
	};

	return valor_retirado;
}

void pilha_libera(Pilha *p){
	lst_libera(p->lst);
	free(p);
}