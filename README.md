MiniCalc
========

Uma linguagem simples para cálculo de expressões aritméticas.
O interpretador para a linguagem será desenvolvido em estágios, começando
com a versão mais simples e gradativamente adicionando novos
recursos.

## Estágio 1

Programas são da forma

```
print E
```

sendo E uma expressão. As expressões podem ser:

```
E ::= (E + E) | (E * E) 
E ::= <numero>
```

`<numero>` é um número inteiro.

Exemplo 1:
```
print 2
```

Exemplo 2:
```
print (4 + 5)
```

Exemplo 3:
```
print (4 + (2 * 3))
```

## Estágio 2

Mais operações.


## Estágio 3

Variáveis.


## Estágio 4

Precedência de operadores.