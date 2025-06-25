
<img width="100%" src="https://capsule-render.vercel.app/api?type=waving&height=300&color=gradient&text=Library-waterPump-for-Arduino-Uno&fontSize=45"/>

![Arduino](https://img.shields.io/badge/Arduino-Uno-00979D?style=flat&logo=arduino&logoColor=white)
![License](https://img.shields.io/github/license/llsavelino/Library-waterPump-for-Arduino-Uno?color=blue)
![Version](https://img.shields.io/badge/version-1.0.0-orange)
![C++](https://img.shields.io/badge/C++-17-00599C?style=flat&logo=c%2B%2B&logoColor=white)

Uma biblioteca Arduino para controlar bombas d'água com eficiência, oferecendo funcionalidades avançadas para gerenciamento de estado e potência.

## 🔎 Visão Geral

Esta biblioteca simplifica o controle de bombas d'água utilizando Arduino Uno, abstraindo operações de baixo nível e oferecendo:

- ✅ Controle intuitivo de liga/desliga  
- 🎛️ Ajuste preciso de potência via PWM  
- ➕ Operadores sobrecarregados para sintaxe intuitiva  
- 🔧 Gerenciamento automático de pinos  

```cpp
#include "HeaderWp.hpp"
jobBomb* minhaBomba = new jobBomb(9, LOW, 0); // Criação fácil do objeto
````

## 🚀 Funcionalidades Principais

| Feature                     | Descrição                        | Exemplo             |
| --------------------------- | -------------------------------- | ------------------- |
| ⚙️ Controle de Estado       | Liga/desliga com um comando      | `swapState(true)`   |
| 📊 Controle Analógico       | Ajuste potência de 0-255         | `analogPower(128)`  |
| ➕ Operadores Avançados      | Sintaxe intuitiva com operadores | `*minhaBomba += 50` |
| 🔌 Gerenciamento Automático | Configura pinos automaticamente  | -                   |

## 📦 Instalação

1. **Baixe a Biblioteca**:

   ```bash
   git clone https://github.com/llsavelino/Library-waterPump-for-Arduino-Uno.git
   ```
2. **Instale no Arduino IDE**:

   * `Sketch > Incluir Biblioteca > Adicionar Biblioteca .ZIP...`
   * Ou copie para o diretório `libraries`

![Instalação](https://img.shields.io/badge/Installation-Guide-4BC51D)

## 💻 Uso Básico

### 🔧 Inicialização

```cpp
#include "HeaderWp.hpp"
jobBomb* minhaBomba = new jobBomb(9, LOW); // Pino 9, desligado
```

### ⚙️ Controle Simples

```cpp
minhaBomba->swapState(true);  // Liga
minhaBomba->analogPower(200); // 78% de potência
```

### ➕ Operadores

```cpp
*minhaBomba += 30;  // Aumenta potência
*minhaBomba ^= 1;   // Alterna estado
```

## 📚 Exemplo Completo

```cpp
#include "HeaderWp.hpp"

jobBomb* obj = new jobBomb(9, LOW);

void setup() {
  // Configurações iniciais
}

void loop() {
  obj->swapState();  // Alterna estado
  delay(2000);       // Espera 2s
}
```

## 🤝 Contribuição

Contribuições são bem-vindas!

[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](https://github.com/llsavelino/Library-waterPump-for-Arduino-Uno/pulls)

1. Reporte bugs via Issues
2. Envie Pull Requests com melhorias
3. Compartilhe exemplos de uso
