# Libft on — minha Libft explicada para estudar

Repositório didático baseado na minha implementação da **Libft da 42 Porto**. Esta versão pública tem comentários extensos para ajudar a entender **o raciocínio dos algoritmos, a função de cada instrução, ponteiros, memória e casos-limite**.

> **Atenção:** os arquivos em `codigo_comentado/` são materiais de estudo, **não** os arquivos preparados para entrega ou para Norminette. As instruções originais foram preservadas e comentários foram acrescentados; a existência desses comentários não certifica ausência de bugs. O repositório privado original não foi alterado nesta publicação.

## Como estudar

1. Escolha uma função na pasta [codigo_comentado](codigo_comentado).
2. Leia o comentário de abertura para entender **o problema** e **o plano do algoritmo**.
3. Leia o código de cima para baixo, acompanhando as decisões e a movimentação de índices/ponteiros.
4. Feche o arquivo e tente explicar: **entradas**, **saída**, **casos especiais**, **critério de parada** e **memória**.
5. Reescreva a função do zero, **sem copiar**, num arquivo de testes separado; compare a lógica com a versão original.

## Mapa das funções

| Grupo | Funções |
|---|---|
| Verificações ASCII | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Conversões | `ft_toupper`, `ft_tolower`, `ft_atoi`, `ft_itoa` |
| Strings | `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strlcpy`, `ft_strlcat`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri` |
| Memória | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Escrita em fd | `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` |
| Listas encadeadas (bônus) | `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap` |

**Arquivos auxiliares:** [libft.h](codigo_comentado/libft.h) e [Makefile](codigo_comentado/Makefile), preservados com uma introdução didática.

## Defenda qualquer função com este roteiro

**1. Contrato:** que parâmetros entram? Que tipo volta? A função modifica algo do chamador?

**2. Algoritmo:** qual é a condição inicial? O que cada repetição realiza? O que faz o laço terminar?

**3. Memória:** quem aloca? Quem libera? Se uma alocação falhar depois de outras, o que já existe?

**4. Limites:** string vazia, tamanho zero, um único elemento, último elemento, `NULL` quando aplicável, `INT_MIN`, espaços e delimitadores repetidos.

**5. Complexidade:** quantas vezes cada elemento é visitado? Quantas alocações são feitas?

### Exemplos de defesa ligados ao código

- **`ft_memmove`:** explique por que o sentido da cópia evita sobrescrever dados de origem antes de usá-los. Simule deslocamento de um array para a direita.
- **`ft_split`:** identifique a contagem de palavras, o array de ponteiros, a alocação de cada palavra e o papel de `free_split` numa falha parcial.
- **`ft_itoa`:** justifique a variável `long`, o cálculo do tamanho e o preenchimento de trás para frente.
- **`ft_lstadd_front`:** explique por que `new->next = *lst` precisa acontecer antes de `*lst = new`.
- **`ft_lstclear`:** mostre o *use-after-free* que existiria sem salvar o próximo nó.
- **`ft_lstmap`:** diferencie o ponteiro para conteúdo transformado do ponteiro para o novo nó; explique por que há limpeza da lista parcial e do conteúdo que ficou sem nó.

## Preparação para o live coding

Pratique **sem olhar os arquivos**. São exercícios progressivos, não previsão da avaliação:

| Nível | Desafio | O que precisa demonstrar |
|---|---|---|
| 1 | Reescreva uma contagem de caracteres em string | índice, `\0`, caso vazio |
| 2 | Implemente busca da primeira ou última ocorrência | valor de retorno: endereço ou `NULL` |
| 3 | Copie `n` bytes para um destino | ponteiros, bytes e limite |
| 4 | Aloque e copie uma substring | `malloc`, cálculo exato, terminador e falha |
| 5 | Crie e percorra três nós de `t_list` | `->next`, `*`, `&`, limite final |
| 6 | Escreva uma limpeza segura de lista | guardar próximo antes de `free` |
| 7 | Refaça `ft_split` ou `ft_lstmap` | decomposição em auxiliares e cleanup completo |

**Método de treino:** 5 minutos explicando o plano em português, 10–20 minutos codificando sem consultar, 5 minutos testando e depois revisão do que errou. O ganho vem de conseguir reconstruir, não de decorar.

## Antes da avaliação oficial

Verifique o subject da sua edição e o repositório de entrega. Dois pontos que merecem revisão na versão consultada:

- `ft_lstsize` no código usa `int`; confira se sua versão do subject exige `unsigned int` no protótipo e na implementação.
- O Makefile original coloca as funções bônus junto de `SRCS`; confira o comportamento esperado de `make` e `make bonus`, incluindo não fazer *relink* desnecessário.

Execute os testes no **repositório de entrega**, não nesta edição comentada. Norminette verifica estilo, não a correção funcional; use também compilação, testes e checagem de memória.

## Uso de IA

O **ChatGPT foi utilizado como tutor de programação** para explicar conceitos, algoritmos e funcionamento das funções durante o estudo da Libft.

---

Código de origem: [Libft_42](https://github.com/lucasbraga-2002/Libft_42) (acesso conforme permissões do proprietário). Autor: `lbraga-m`. Comentários adicionados para finalidade educacional.
