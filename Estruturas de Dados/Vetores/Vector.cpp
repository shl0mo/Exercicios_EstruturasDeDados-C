# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <string.h>
# include <conio.h>
# include <ctype.h>

/* Estruturas de dados */
// Vetor de lista de produtos da loja
typedef struct Loja {
	char tipo[100];
	char marca[100];
	char modelo[100];
	float valor;
	int quantidade_estoque;
	float valor_frete;
	struct Loja* prox;
} LOJA;

typedef LOJA* LOJAptr;

// Vetor de lista de produtos no carrinho
typedef struct Carrinho {
	char nome_produto[100];
	struct Carrinho* prox;
} CARRINHO;

typedef CARRINHO* CARRINHOptr;

// Vetor de informa��es e carrinho do cliente
typedef struct Cliente {
	float saldo;
	char endereco[100];	
	struct Carrinho* carrinho;
} CLIENTE;

typedef CLIENTE* CLIENTEptr;


/* Fun��es */
void apaga_palavra(char palavra[100]) {
	int i;
	for (i = 0; i < 100; i++) {
		palavra[i] = '\0';
	}
}

void copia_palavra(char vetor_destino[100], char palavra[100]) {
	int i;
	for (i = 0; i < 100; i++) {
		vetor_destino[i] = palavra[i];
	}
}

LOJAptr insere_no_loja(LOJAptr loja, int primeiro, char tipo[100], char marca[100], char modelo[100], float valor, int quantidade_estoque, float valor_frete) {
	LOJAptr novo_no = (LOJAptr) malloc(sizeof(LOJA));
 	copia_palavra(novo_no->tipo, tipo);
	copia_palavra(novo_no->marca, marca);
	copia_palavra(novo_no->modelo, modelo);
	novo_no->valor = valor;
	novo_no->quantidade_estoque = quantidade_estoque;
	novo_no->valor_frete = valor_frete;
	if (primeiro == 1) {
		novo_no->prox = NULL;
		return novo_no;
	}
	LOJAptr p = loja;
	while (p->prox != NULL) {
		p = p->prox;
	}
	p->prox = novo_no;
	novo_no->prox = NULL;
	return NULL;
}

LOJAptr inicializa_loja() {
	srand(time(NULL));
	float valor_frete = 15;
	// Produto 1 a ser inserido no vetor
	char tipo_1[] = "Contador";
	char marca_1[] = "Helmholz";
	char modelo_1[] = "600-255-7BA21";
	float valor_1 = 79.29f;
	int quantidade_estoque_1 = rand() % 15 + 5;
	// Produto 2 a ser inserido no vetor
	char tipo_2[] = "Disjuntor";
	char marca_2[] = "Soprano";
	char modelo_2[] = "ASM2-B";
	float valor_2 = 32.40f;
	int quantidade_estoque_2 = rand() % 15 + 5;
	// Produto 3 a ser inserido no vetor
	char tipo_3[] = "DR";
	char marca_3[] = "Schneider";
	char modelo_3[] = "Easy9 2P";
	float valor_3 = 144.99f;
	int quantidade_estoque_3 = rand() % 15 + 5;
	// Produto 4 a ser inserido no vetor
	char tipo_4[] = "Eletroduto";
	char marca_4[] = "Amanco";
	char modelo_4[] = "11448";
	float valor_4 = 11.90f;
	int quantidade_estoque_4 = rand() % 15 + 5;
	// Produto 5 a ser inserido no vetor
	char tipo_5[] = "Interruptor";
	char marca_5[] = "Alumbra";
	char modelo_5[] = "Inova Pro 85042";
	float valor_5 = 21.19f;
	int quantidade_estoque_5 = rand() % 15 + 5;
	// Produto 6 a ser inseido no vetor
	char tipo_6[] = "Tomada";
	char marca_6[] = "Tramontina";
	char modelo_6[] = "Aria";
	float valor_6 = 14.16f;
	int quantidade_estoque_6 = rand() % 15 + 5;
	// Produto 7 a ser inserido no vetor
	char tipo_7[] = "DPS";
	char marca_7[] = "CLAMPER";
	char modelo_7[] = "Front";
	float valor_7 = 41.90f;
	int quantidade_estoque_7 = rand() % 15 + 5;
	// Insere os produtos na loja
	LOJAptr loja = insere_no_loja(NULL, 1, tipo_1, marca_1, modelo_1, valor_1, quantidade_estoque_1, valor_frete);
	insere_no_loja(loja, 0, tipo_2, marca_2, modelo_2, valor_2, quantidade_estoque_2, valor_frete);
	insere_no_loja(loja, 0, tipo_3, marca_3, modelo_3, valor_3, quantidade_estoque_3, valor_frete);
	insere_no_loja(loja, 0, tipo_4, marca_4, modelo_4, valor_4, quantidade_estoque_4, valor_frete);
	insere_no_loja(loja, 0, tipo_5, marca_5, modelo_5, valor_5, quantidade_estoque_5, valor_frete);
	insere_no_loja(loja, 0, tipo_6, marca_6, modelo_6, valor_6, quantidade_estoque_6, valor_frete);
	insere_no_loja(loja, 0, tipo_7, marca_7, modelo_7, valor_7, quantidade_estoque_7, valor_frete);
	return loja;
}

void imprime_loja (LOJAptr loja) {
	LOJAptr p = loja;
	int i = 1;
	while (p != NULL) {
		printf("Produto %i:\n", i);
		printf("TIPO: %s\n", p->tipo);
		printf("MARCA: %s\n", p->marca);
		printf("MODELO: %s\n", p->modelo);
		printf("VALOR: %f\n", p->valor);
		printf("ESTOQUE: %i\n", p->quantidade_estoque);
		printf("FRETE: %f\n", p->valor_frete);
		printf("\n\n");
		p = p->prox;
		i = i + 1;
	}
}

CARRINHOptr inicializa_carrinho() {
	// Cria um n� para a cabe�a do vetor do carrinho, com valores nulos para o nome do produto e o ponteiro prox
	CARRINHOptr novo_carrinho = (CARRINHOptr) malloc(sizeof(CARRINHO));
	apaga_palavra(novo_carrinho->nome_produto);
	novo_carrinho->prox = NULL;
	return novo_carrinho;
}

CLIENTEptr inicializa_cliente(float saldo) {
	// Cria um cliente e lhe atribui o valor do saldo passado como par�metro
	CLIENTEptr novo_cliente	= (CLIENTEptr) malloc(sizeof(CLIENTE));
	novo_cliente->saldo = saldo;
	apaga_palavra(novo_cliente->endereco);
	novo_cliente->carrinho = inicializa_carrinho();
}

void adiciona_carrinho(LOJAptr loja, CLIENTEptr cliente, char nome_produto[100]) {
	// A vari�vel p_loja percorre o vetor de lista de produtos da loja
	LOJAptr p_loja = loja;
	while (p_loja) {
		// Se o produto for encontrado
		if (strcmp(p_loja->tipo, nome_produto) == 0) {
			// Verifica se h� saldo suficiente para a compra
			if (cliente->saldo < p_loja->valor) {
				// N�o havendo saldo suficiente, a mensagem abaixo � exibida
				printf("N�o � poss�vel realizar a compra. Saldo insuficiente\n\n");
				return;
			}
			/* Se houver saldo suficiente, o valor do produto ser� subtra�do do saldodo cliente, a quantidade de itens do produto adicionado ao carrinho ser� 
			   subtra�do em uma unidade na lista e o produto ser� adicionado ao carrinho
			*/
			// Subtrai o valor do saldo do cliente pelo valor do produto adicionado ao carrinho e o valor do frete
			cliente->saldo = cliente->saldo - p_loja->valor - p_loja->valor_frete;
			// Subtrai na lista uma unidade do produto adicionado ao carrinho pelo cliente
			p_loja->quantidade_estoque = p_loja->quantidade_estoque - 1;
			// Adiciona produto ao carrinho:
			// Caminha at� o �ltimo elemento da lista
			CARRINHOptr p_carrinho = cliente->carrinho;
			while (p_carrinho->prox != NULL) {
				p_carrinho = p_carrinho->prox;
			}
			// Cria um novo n� para o carrinho no qual ser� adicionado o produto adquirido
			CARRINHOptr novo_carrinho = (CARRINHOptr) malloc(sizeof(CARRINHO));
			// Adiciona o produto no novo n�
			copia_palavra(novo_carrinho->nome_produto, nome_produto);
			// Insere o produto no final do vetor do carrinho
			novo_carrinho->prox = NULL;
			p_carrinho->prox = novo_carrinho;
			return;
		}
		p_loja = p_loja->prox;
	}
	// Se o nome de produto inserido n�o for encontrado, a mensagem abaixo � exibida
	printf("\nProduto nao encontrado\n\n");
}

void imprime_saldo_carrinho(CLIENTEptr cliente) {
	// Imprime o saldo do cliente
	printf("\nSALDO: %f\n", cliente->saldo);
	// Imprime os produtos no carrinho
	int qtd_produtos = 0;
	CARRINHOptr p_carrinho = cliente->carrinho;
	while (p_carrinho) {
		if (qtd_produtos == 1) printf("PRODUTOS NO CARRINHO:\n");
		if (qtd_produtos != 0) printf(" - ");
		if (p_carrinho->nome_produto != NULL) printf("%s\n", p_carrinho->nome_produto);
		p_carrinho = p_carrinho->prox;
		qtd_produtos = qtd_produtos + 1;
	}
	if (qtd_produtos == 1) {
		printf("Carrinho vazio\n\n");
	}
	int espera_tecla;
	printf("\nPressione qualquer tecla para continuar\n");
	_getch();
}

int main () {
	srand(time(NULL));
	float saldo = rand() % 600;
	LOJAptr loja = inicializa_loja();
	CLIENTEptr cliente = inicializa_cliente(saldo);
	while (1) {
		int opcao;
		printf("\nEscolha uma das opcoes abaixo:\n\n");
		printf("1 - Ver produtos\n");
		printf("2 - Realizar compra\n");
		printf("3 - Exibir saldo e carrinho\n");
		printf("4 - Finalizar compra\n\n");
		scanf("%i", &opcao);
		if (opcao == 4) {
			printf("Novo cliente disponivel?\n");
			printf("1 - Sim\n");
			printf("2 - Nao\n");
			scanf("%i", &opcao);
			if (opcao == 1) {
				saldo = rand() % 600;
				loja = inicializa_loja();
				cliente = inicializa_cliente(saldo);
				continue;
			} else {
				break;
			}
		}
		if (opcao == 1) {
			imprime_loja(loja);
		} else if (opcao == 2) {
			char nome_produto[100];
			printf("\nInforme o nome do produto a ser adicionado ao carrinho: ");
			scanf("%s", &nome_produto);
			adiciona_carrinho(loja, cliente, nome_produto);
		} else if (opcao == 3) {
			imprime_saldo_carrinho(cliente);
		}
	}
}
