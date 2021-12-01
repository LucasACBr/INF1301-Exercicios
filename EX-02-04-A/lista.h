//Lucas Simões de Almeida - Matrícula 1712101

typedef struct no No;

typedef struct lista Lista;

Lista * lst_cria(void);

int lst_vazia(Lista* lst);

void lst_insIni(Lista * lst, void * cod);

void lst_insFin(Lista * lst, void * cod);

void *lst_retIni(Lista * lst);

void *lst_retFin(Lista * lst);

void lst_posIni(Lista * lst);

void lst_posFin(Lista * lst);

void *lst_prox(Lista * lst);

void *lst_ant(Lista * lst);

void lst_libera(Lista * lst);
