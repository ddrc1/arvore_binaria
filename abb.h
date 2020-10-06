typedef struct sarvorebb {
	int chave;
	float conteudo;
	struct sarvorebb *esq, *dir, *pai;

} ArvoreBB;

void inicializar (ArvoreBB **raiz);

int inserir_interativo (ArvoreBB **raiz, int chave, float val);

int inserir_recursivo (ArvoreBB **raiz, int chave, float val);

float buscar_interativo (ArvoreBB *raiz, int chave);

float buscar_recursivo (ArvoreBB *no, int chave);

int listar_elementos (ArvoreBB *raiz);

ArvoreBB *minimo(ArvoreBB *no);

ArvoreBB *maximo(ArvoreBB *no);

ArvoreBB *buscar(ArvoreBB *raiz, int chave);

ArvoreBB *sucessor(ArvoreBB *raiz, int chave);