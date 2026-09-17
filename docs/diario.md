# Diário da atividade

## Ambiente

- Versão do OpenCode (`opencode --version`): 1.18.31
- Modelo usado: Big Pickle — OpenCode Zen

## Parte 1: antes de programar

- O que cada classe guarda:
A classe `Astronauta` guarda o CPF, nome, idade e informações sobre estar vivo e disponível. A classe `Voo` guarda o código, o estado do voo e os CPFs dos astronautas que participam dele. A classe `Agencia` guarda os astronautas e os voos cadastrados e faz as operações entre eles.

- O que acontece em `LANCAR_VOO`, em palavras:
O comando verifica se o voo existe, se está planejado e se possui astronautas. Também verifica se os astronautas podem participar do voo. Se estiver tudo certo, os astronautas são embarcados e o voo passa para o estado em curso.

- Uma dúvida que eu tinha antes de começar:
Eu tinha dúvida sobre como controlar a relação entre os astronautas e os voos, principalmente como saber se um astronauta estava disponível para embarcar e como essa situação mudaria depois que o voo fosse lançado.


## Parte 1: uso de IA para entender algo

- O que perguntei (ou "não usei"):
Perguntei sobre um erro de compilação que apareceu no código e sobre como identificar onde estava o problema.

- O que aprendi:
Aprendi a prestar atenção na mensagem do compilador e a verificar as linhas próximas ao local indicado, porque cometi um erro de sintaxe em uma parte do código e acabei causando vários erros em outras linhas.

## Primeiro contato: revisão sem editar

- As três melhorias que a IA sugeriu, em uma linha cada:
Criar uma forma melhor de buscar astronautas e voos, evitando retornar posições com valor -1.
Criar um método para verificar se o voo está planejado, evitando repetir essa condição.
Separar melhor a lógica usada para listar as informações.

- A que escolhi e por quê:
Escolhi criar o método para verificar se o voo está planejado porque era uma alteração simples e diminuía a repetição no código.

- O que mudou no código, e se os seis testes continuaram passando:
Foi criado o método estaPlanejado() na classe Voo e as verificações repetidas foram substituídas por ele. Os seis testes da Parte 1 continuaram passando.

- O que entendi que não sabia antes:
Entendi que posso colocar uma verificação que uso várias vezes dentro de um método e depois chamar esse método quando precisar dela.

## Missão 1: LISTAR_ASTRONAUTAS e HISTORICO

- Primeira mensagem (o pedido do plano):

Leia @AGENTS.md, @ENUNCIADO.md, @src/main.cpp e os testes da Missão 1 em @testes/missao1.
A Parte 1 já está pronta e os seis testes da Parte 1 estão passando.
Agora quero implementar a Missão 1, que adiciona os comandos LISTAR_ASTRONAUTAS e HISTORICO.
Entenda as regras e as saídas esperadas a partir do enunciado e dos testes.
Nesta primeira mensagem, NÃO altere nenhum arquivo.
Explique como você pretende implementar a Missão 1, quais métodos e arquivos serão criados ou alterados e por quê.
Antes de editar, me mostre o plano.

- O plano que a IA apresentou, resumido:
Criar um método para verificar em qual voo em curso o astronauta está. Depois, criar os métodos para listar os astronautas separados entre disponíveis, em voo e mortos, e para mostrar o histórico de voos de um astronauta. Por fim, adicionar os dois novos comandos ao main.

- Mudei algo no plano antes de liberar? Não

- Resultado de `testar.sh missao1` e de `testar.sh parte1`:
Os dois testes da Missão 1 passaram e os seis testes da Parte 1 passaram usando o `testar.sh` no WSL.

- Precisei refazer? O que mudou no pedido:
Sim. O teste de HISTORICO mostrou que faltava o CPF no cabeçalho. Pedi para corrigir apenas essa saída. Depois da correção, os dois testes da Missão 1 e os seis testes da Parte 1 passaram.

## Missão 2: SALVAR e CARREGAR

- Primeira mensagem:
Leia @AGENTS.md, @ENUNCIADO.md, @src/main.cpp e os testes da Missão 2 em @testes/missao2.
A Parte 1 e a Missão 1 já estão prontas e os testes estão passando.
Agora quero implementar a Missão 2, que adiciona os comandos SALVAR e CARREGAR.
Entenda as regras, as mensagens e o formato esperado a partir do enunciado e dos testes.
Nesta primeira mensagem, NÃO altere nenhum arquivo.
Explique como você pretende implementar a Missão 2, quais métodos e arquivos serão criados ou alterados e por quê.
Antes de editar, me mostre o plano.

- O plano, resumido:
Criar os métodos `salvar()` e `carregar()` na classe `Agencia`, usando arquivos de texto para guardar e reconstruir astronautas e voos, e adicionar os comandos `SALVAR` e `CARREGAR` no `main`.

- O formato do arquivo (cole cinco linhas do `dados_teste.txt`):
AGENCIA
ASTRONAUTAS 1
111 25 1 1 Ana Maria
VOOS 1
10 0 1 111

- Resultado de `testar.sh missao2` e de `testar.sh parte1`:
Os três testes da Missão 2 passaram e os seis testes da Parte 1 passaram usando o `testar.sh` no WSL.

- Precisei refazer? O que mudou no pedido:
Sim. Ao conferir as saídas, precisei ajustar a formatação de `LISTAR_VOOS` e a mensagem de erro de `LANCAR_VOO` sem astronautas. Depois os testes passaram.

## Missão 3: RELATORIO

- Primeira mensagem:
Leia @AGENTS.md, @ENUNCIADO.md, @src/main.cpp e os testes da Missão 3 em @testes/missao3.
A Parte 1, a Missão 1 e a Missão 2 já estão prontas e os testes estão passando.
Agora quero implementar a Missão 3, que adiciona o comando RELATORIO.
Entenda as regras e as saídas esperadas a partir do enunciado e dos testes.
Nesta primeira mensagem, NÃO altere nenhum arquivo.
Explique como você pretende implementar a Missão 3, quais métodos e arquivos serão criados ou alterados e por quê.
Antes de editar, me mostre o plano.

- O plano, resumido:
Criar o método `relatorio()` na classe `Agencia`, calculando a quantidade de voos planejados, em curso, finalizados com sucesso e finalizados com explosão, além da quantidade de astronautas cadastrados, vivos e mortos. Também calcular qual astronauta possui mais experiência, considerando a quantidade de voos lançados em que participou, e calcular a taxa de sucesso dos voos finalizados. Depois, adicionar o comando `RELATORIO` no `main`.

- Resultado de `testar.sh missao3` e de `testar.sh parte1`:
Os testes da Missão 3 passaram e os seis testes da Parte 1 também passaram.

- Precisei refazer? O que mudou no pedido:
Não precisei refazer. A implementação da Missão 3 foi feita conforme o plano e os testes passaram.

## Missão 4: CONTAR_DISPONIVEIS

- O que escolhi e por quê:
Escolhi criar o comando 'CONTAR_DISPONIVEIS' porque é uma funcionalidade simples que mostra quantos astronautas estão vivos e disponíveis para participar de um voo. 

- O comando novo, a saída que eu esperava e o nome do meu arquivo de comandos
  (escritos antes de pedir):

Comando novo: `CONTAR_DISPONIVEIS`

Saída esperada:

```text
ASTRONAUTAS DISPONIVEIS: 3
ASTRONAUTAS DISPONIVEIS: 2
```

Arquivo de comandos:

`testes/missao4/01_contar_disponiveis.in`

- Primeira mensagem:
Leia @AGENTS.md, @ENUNCIADO.md, @src/main.cpp e o arquivo de comandos da Missão 4 em @testes/missao4/01_contar_disponiveis.in.
A Parte 1, a Missão 1, a Missão 2 e a Missão 3 já estão prontas e os testes estão passando.
Agora quero implementar a Missão 4, adicionando o comando CONTAR_DISPONIVEIS.
O comando deve contar quantos astronautas estão vivos e disponíveis no momento e imprimir exatamente:
ASTRONAUTAS DISPONIVEIS: X
Nesta primeira mensagem, NÃO altere nenhum arquivo.
Explique como você pretende implementar essa funcionalidade, quais métodos e arquivos serão criados ou alterados e por quê.
Antes de editar, me mostre o plano.

- O que veio, comparado com o que eu esperava:
A IA propôs fazer um método para contar os astronautas disponíveis e adicionar o comando no main. Foi o que eu esperava e não precisei mudar o plano. Depois de fazer, a saída ficou como eu tinha pensado e os testes continuaram passando.

- `testar.sh parte1` continuou passando?
Sim. Os 6 testes da Parte 1 continuaram passando.

- Aceitei, ajustei ou descartei? Por quê:
Aceitei, porque a implementação ficou de acordo com o que foi planejado, a saída esperada foi obtida e os testes da Parte 1 continuaram passando.

## Fechamento

- O que a IA fez que eu não conseguiria fazer sozinho nesse prazo:
Ajudou a implementar as funcionalidades mais rápido e a encontrar alguns erros nas saídas dos testes.

- Onde ela errou ou fez algo que eu não pedi:
Algumas saídas não ficaram exatamente como os testes esperavam, então precisei pedir alguns ajustes.

- O que eu faria diferente da próxima vez:
Prestaria mais atenção nas saídas esperadas dos testes e faria mais testes durante o desenvolvimento.


## Relatório complementar

Decidi fazer este relatório para registrar com mais detalhes algumas coisas que aconteceram durante o desenvolvimento e que não caberiam nas respostas curtas do diário.

### Problemas encontrados na Parte 1

Durante a Parte 1, tive um problema de compilação no `main.cpp`. Depois de uma alteração, o VS Code começou a mostrar vários erros no arquivo. No começo parecia que havia vários problemas diferentes, mas o problema era uma chave `}` que estava faltando na função `buscarAstronauta`. Depois de corrigir a chave, os vários erros que estavam aparecendo desapareceram.

Também fiz uma revisão da Parte 1 antes de começar as missões. Nessa revisão, foram sugeridas algumas melhorias no código. Uma delas foi criar o método `estaPlanejado()` na classe `Voo`, para evitar repetir a mesma verificação em vários lugares. Escolhi fazer essa alteração porque era simples e eu conseguia entender o que estava sendo mudado. Depois disso, os seis testes da Parte 1 continuaram passando.

### Missão 1

Na Missão 1, implementei `LISTAR_ASTRONAUTAS` e `HISTORICO`.

Depois de implementar, rodei os testes e um deles não passou. O problema não estava exatamente na lógica do histórico, mas no formato da saída. O teste esperava que o cabeçalho mostrasse o CPF e o nome do astronauta, mas o CPF não estava sendo mostrado.

Então pedi para corrigir somente essa parte. Depois da correção, os dois testes da Missão 1 passaram e os seis testes da Parte 1 também continuaram passando. Percebi que não bastava a funcionalidade estar funcionando, a saída também precisava estar exatamente no formato esperado pelo teste.

### Missão 2

Na Missão 2, implementei `SALVAR` e `CARREGAR`.

Antes de deixar a IA alterar os arquivos, pedi que ela analisasse o enunciado e os testes e explicasse como pretendia fazer a implementação. Depois disso, a funcionalidade foi implementada usando arquivos de texto para salvar e recuperar os dados.

Quando conferi os resultados, apareceram alguns problemas de saída. Foi necessário ajustar a formatação de `LISTAR_VOOS` e também a mensagem mostrada por `LANCAR_VOO` quando o voo não tinha astronautas.

Depois desses ajustes, os três testes da Missão 2 passaram. Também rodei novamente os testes das missões anteriores e os seis testes da Parte 1 continuaram passando.

### Mudança na forma de testar o projeto

No começo, eu estava fazendo alguns testes manualmente, executando os comandos no programa e conferindo as respostas. Depois, percebi que o projeto pedia o `testar.sh`, que reunia os testes preparados para verificar as funcionalidades. A partir disso, passei a usar o `bash testes/testar.sh parte1` para conferir a Parte 1 e, nas missões, usei também os testes específicos de cada uma. Isso facilitou bastante para perceber quando alguma coisa estava diferente do que o projeto esperava.

Foi usando esses testes que consegui identificar alguns dos problemas que apareceram durante o desenvolvimento. Por exemplo, na Missão 1, o teste mostrou que faltava o CPF no cabeçalho do `HISTORICO`. Na Missão 2, os testes também mostraram diferenças na formatação de `LISTAR_VOOS` e na mensagem de erro do `LANCAR_VOO`. Depois de cada correção, eu rodava novamente os testes para confirmar que o problema tinha sido resolvido e que as funcionalidades anteriores continuavam funcionando.

No começo eu estava fazendo mais testes manualmente e não estava usando o testar.sh como principal forma de conferência, depois percebi que ele facilitava bastante a comparação com as saídas esperadas.

### Missão 3

Na Missão 3, implementei o comando `RELATORIO`.

Dessa vez, a implementação foi feita seguindo o plano que tinha sido apresentado antes da alteração dos arquivos. Depois de executar os testes, os cinco testes da missão passaram e também confirmei que os testes da Parte 1 continuavam passando.

Não precisei fazer uma nova correção nessa missão.

### Missão 4

Para a Missão 4, escolhi criar o comando `CONTAR_DISPONIVEIS`.

Escolhi essa funcionalidade porque queria fazer algo simples e que eu conseguisse entender facilmente. Antes de pedir a implementação, criei o arquivo de comandos e defini o que esperava que o programa mostrasse.

Primeiro cadastrei três astronautas e usei o comando para contar os disponíveis. O resultado esperado era 3. Depois coloquei um deles em um voo e lancei o voo. Como ele deixou de estar disponível, a segunda contagem deveria ser 2.

A implementação ficou de acordo com o que eu tinha planejado. Executei o arquivo de comandos manualmente e as duas saídas apareceram como esperado. Depois também rodei novamente os seis testes da Parte 1, que continuaram passando.

### O que aprendi com os erros e correções

Uma coisa que ficou mais clara para mim durante o trabalho foi a importância de testar cada alteração. Algumas vezes o código estava funcionando de forma geral, mas a saída não estava exatamente como o teste esperava.

Também percebi que é importante não aceitar uma alteração sem conferir o resultado. Durante o projeto, eu precisei olhar os testes, identificar o que estava diferente e pedir ajustes quando era necessário.

No final, consegui manter os testes das partes anteriores passando enquanto novas funcionalidades eram adicionadas.