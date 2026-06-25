

# Tranca com Password — Arduino Uno

Sistema de segurança físico desenvolvido com Arduino Uno que controla uma tranca mediante a introdução de uma password num teclado 4x4.

Este é o meu primeiro projeto pessoal. Sou o Edjorge Campos, tenho 18 anos e estou no 1º ano de Engenharia Informática no ISCTE. Tenho interesse no desenvolvimento de sistemas funcionais, tanto digitais como embebidos, e este projeto surgiu depois da cadeira de arquitetura de computadores que suscitou vontade de construir algo físico e real desde cedo no curso.

# Demonstração




https://github.com/user-attachments/assets/11a4730a-9537-40ef-89cd-7a6020c9ff11






# Como funciona

O sistema arranca com a tranca fechada e o LCD a mostrar "Tranca fechada". O utilizador digita uma password de 4 dígitos no teclado, com cada tecla a aparecer como asterisco no ecrã. Ao premir `#`, o sistema verifica a password:

- Se estiver correta, o LCD mostra "Pass certa", o servo abre a tranca, o LED verde acende, e após 2 segundos a tranca fecha automaticamente.
- Se estiver errada, o LCD mostra "Pass errada" e o LED vermelho acende.
- Se forem introduzidos mais de 4 dígitos sem confirmar, o LCD mostra "Pass invalida".

# Componentes

- 1x Arduino Uno 
- 1x Teclado matricial 4x4 
- 1x LCD 16x2  
- 1x Potenciómetro (brilho do LCD) 
- 1x Servo motor  
- 1x LED verde  
- 1x LED vermelho  
- 2x Resistências 220Ω 
- 1x Breadboard 
- Fios de ligação 

# Ligações/Pinout

 - Teclado : Linhas { 2, 3, 4, 5 }
 - Teclado : Colunas { 6, 7, 8, 9 }
 - Servo motor : 10 
 - LED verde : 11 
 - LED vermelho : 12 
 - LCD (RS, E, D4, D5, D6, D7) : A0, A1, A2, A3, A4, A5 

# Esquema de Ligações

<img width="1536" height="694" alt="CircuitDesign" src="https://github.com/user-attachments/assets/939b60f6-c60d-4314-94ac-25b83642b3f0" />


# Código

O código está no ficheiro `Tranca_com_password.ino` neste repositório.

# Bibliotecas utilizadas

- [Keypad](https://playground.arduino.cc/Code/Keypad/) — leitura do teclado matricial
- [Servo](https://www.arduino.cc/reference/en/libraries/servo/) — controlo do servo motor
- [LiquidCrystal](https://www.arduino.cc/reference/en/libraries/liquidcrystal/) — controlo do LCD

# Melhorias futuras

Há algumas coisas que quero melhorar quando tiver mais experiência:

- Substituir `delay()` por `millis()` para não bloquear o sistema durante as esperas
- Guardar a password em EEPROM para permitir alterá-la sem recompilar o código
- Adicionar um limite de tentativas com bloqueio temporário após erros consecutivos
- Permitir alterar a password diretamente pelo teclado

# Autor

Edjorge Campos  
1º ano — Engenharia Informática  
Interesse em arquitetura de computadores e sistemas funcionais
